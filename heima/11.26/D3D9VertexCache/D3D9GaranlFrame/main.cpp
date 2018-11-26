
//-----------------------------------������˵����----------------------------------------------
//  ��������:��D3DdemoCore
//	 2018��11Create by hc
//  ������Direct3D���ƻ��������㻺��
//------------------------------------------------------------------------------------------------

//-----------------------------------��ͷ�ļ��������֡�---------------------------------------
//	����������������������ͷ�ļ�
//------------------------------------------------------------------------------------------------

#include <d3d9.h>
#include <d3dx9.h>		// �ṩ����ѧ���㣬������ͼ�����㣬�������㣬��	
#include <tchar.h>
// ---------------------------------- - �����ļ��������֡�-------------------------------------- -
//	���������������������Ŀ��ļ�
//------------------------------------------------------------------------------------------------
//#pragma comment(lib,"winmm.lib")		// playsound����Ҫ���ļ���
//#pragma comment(lib,"d3d9.lib")
//#pragma comment(lib,"d3dx9.lib")		// �������������ӿⶨ���ˡ�����������Բ���л�����⡢

//-----------------------------------���궨�岿�֡�--------------------------------------------
//	����������һЩ������
//------------------------------------------------------------------------------------------------
LPDIRECT3DDEVICE9 g_pd3dDevice = NULL; //Direct3D�豸����
ID3DXFont* g_pFont = NULL;				// ����COM�ӿ�
float g_Fps = 0.0f;
wchar_t g_strFps[50];					// һ������֡�ʵ��ַ�������
LPDIRECT3DVERTEXBUFFER9 g_pVertexBuffer = NULL;		// ���㻺��������


//-----------------------------------��ȫ�ֱ����������֡�-------------------------------------
//	������ȫ�ֱ���������
//------------------------------------------------------------------------------------------------
#define WINDOW_WIDTH	800							//Ϊ���ڿ�ȶ���ĺ꣬�Է����ڴ˴��޸Ĵ��ڿ��
#define WINDOW_HEIGHT	600							//Ϊ���ڸ߶ȶ���ĺ꣬�Է����ڴ˴��޸Ĵ��ڸ߶�
#define WINDOW_TITLE	L"������������Ϩ�����Ϸ�������롿Direct3D����ĺ��Ŀ��"	//Ϊ���ڱ��ⶨ��ĺ�
#define SAFE_RELEASE(p) { if(p) { (p)->Release(); (p)=NULL; } }   //����һ����ȫ�ͷź꣬���ں���COM�ӿ�ָ����ͷ�

//-----------------------------------��ȫ�ֺ����������֡�-------------------------------------
//	������ȫ�ֺ�����������ֹ��δ�����ı�ʶ��ϵ�д���
//------------------------------------------------------------------------------------------------
// ���㻺���Ĳ���  1.��ƶ����ʽ
struct CUSTOMVERTEX
{
	float x, y, z, rhw;
	DWORD color;
};
// �궨�壬��ʾ���Ǵ���������FVF�ṹ��
#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZRHW|D3DFVF_DIFFUSE)		

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);// ���ڹ��̺���������
HRESULT Direct3D_Init(HWND hwnd);		// Direct3D�ĳ�ʼ��
HRESULT Objects_Init(HWND hwnd);		// ��Դ��ʼ��
VOID Direct3D_Render(HWND hwnd);
VOID Direct3D_CleanUp();      // ������Դ
float Get_Fps();




//-----------------------------------��WinMain( )������--------------------------------------
//	������WindowsӦ�ó������ں��������ǵĳ�������￪ʼ
//------------------------------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
	LPSTR lpCmdLine, int nShowCmd)
{
	//��1�����ڴ����Ĳ���֮һ����ʼ���һ�������Ĵ�����
	WNDCLASSEX wndClass = { 0 };
	wndClass.cbSize = sizeof(WNDCLASSEX);			//���ýṹ����ֽ�����С
	wndClass.style = CS_HREDRAW | CS_VREDRAW;	//���ô��ڵ���ʽ
	wndClass.lpfnWndProc = WndProc;					//����ָ�򴰿ڹ��̺�����ָ��
	wndClass.cbClsExtra = 0;								//������ĸ����ڴ棬ȡ0�Ϳ�����
	wndClass.cbWndExtra = 0;							//���ڵĸ����ڴ棬��Ȼȡ0������
	wndClass.hInstance = hInstance;						//ָ���������ڹ��̵ĳ����ʵ�������
	wndClass.hIcon = (HICON)::LoadImage(NULL, L"icon.ico", IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_LOADFROMFILE);  //���ؼ����Զ���icoͼ��
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);    //ָ��������Ĺ������
	wndClass.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);  //ΪhbrBackground��Աָ��һ����ɫ��ˢ���	
	wndClass.lpszMenuName = NULL;						//��һ���Կ���ֹ���ַ�����ָ���˵���Դ�����֡�
	wndClass.lpszClassName = L"ForTheDreamOfGameDevelop";	//��һ���Կ���ֹ���ַ�����ָ������������֡�

	//��2�����ڴ����Ĳ���֮����ע�ᴰ����
	if (!RegisterClassEx(&wndClass))
	{
		MessageBox(0, L"RegisterClassEx fail", L"msg", 0);
	}
	//��3�����ڴ����Ĳ���֮������ʽ��������
	HWND hwnd = CreateWindow(L"ForTheDreamOfGameDevelop", WINDOW_TITLE, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, WINDOW_WIDTH, WINDOW_HEIGHT, NULL, NULL, hInstance, NULL);

	//Direct3D��Դ�ĳ�ʼ��
	if (Direct3D_Init(hwnd) == S_OK)
	{
		MessageBox(hwnd, L"Direct3D��ʼ�����~��", L"hc����Ϣ����", 0); //ʹ��MessageBox����������һ����Ϣ����  
	}
	else
	{
		MessageBox(hwnd, L"Direct3D��ʼ��ʧ��~��", L"hc����Ϣ����", 0); //ʹ��MessageBox����������һ����Ϣ����
	}

	//��4�����ڴ����Ĳ���֮�ģ����ڵ��ƶ�����ʾ�����
	MoveWindow(hwnd, 250, 80, WINDOW_WIDTH, WINDOW_HEIGHT, true);
	ShowWindow(hwnd, nShowCmd);
	UpdateWindow(hwnd);

	PlaySound(L"Final Fantasy XIII.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	MessageBox(hwnd, L"DirectX�������ưɣ���������������~!", L"ǳī����Ϣ����", 0); //ʹ��MessageBox��������ʾһ����Ϣ����

	//��5����Ϣѭ������
	MSG msg = { 0 };//��ʼ��msg
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))//�鿴Ӧ�ó�����Ϣ���У�����Ϣʱ�������е���Ϣ�ɷ���ȥ��
		{
			TranslateMessage(&msg);//���������Ϣת��Ϊ�ַ���Ϣ
			DispatchMessage(&msg);		//�ú����ַ�һ����Ϣ�����ڳ���
		}
		else
		{
			Direct3D_Render(hwnd);   //������Ⱦ
		}
	}
	//��6���������ע��
	UnregisterClass(L"ForTheDreamOfGameDevelop", wndClass.hInstance);
	return 0;
}

//-----------------------------------��WndProc( )������--------------------------------------
//	���������ڹ��̺���WndProc,�Դ�����Ϣ���д���
//------------------------------------------------------------------------------------------------
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)						//switch��俪ʼ
	{
	case WM_PAINT:						// ���ǿͻ����ػ���Ϣ
		Direct3D_Render(hwnd);                 //����Direct3D��Ⱦ����
		ValidateRect(hwnd, NULL);		// ���¿ͻ�������ʾ
		break;									//������switch���

	case WM_KEYDOWN:					// ���Ǽ��̰�����Ϣ
		if (wParam == VK_ESCAPE)    // ��������µļ���ESC
			DestroyWindow(hwnd);		// ���ٴ���, ������һ��WM_DESTROY��Ϣ
		break;									//������switch���

	case WM_DESTROY:					//���Ǵ���������Ϣ
		Direct3D_CleanUp();			//�����Զ������Դ������Game_CleanUp���������˳�ǰ����Դ����
		PostQuitMessage(0);			//��ϵͳ�����и��߳�����ֹ����������ӦWM_DESTROY��Ϣ
		break;									//������switch���

	default:										//������case�����������ϣ���ִ�и�default���
		return DefWindowProc(hwnd, message, wParam, lParam);		//����ȱʡ�Ĵ��ڹ���
	}

	return 0;									//�����˳�
}

//-----------------------------------��Direct3D_Init( )������--------------------------------------
//	������Direct3D��ʼ������������Direct3D�ĳ�ʼ��
//------------------------------------------------------------------------------------------------
HRESULT Direct3D_Init(HWND hwnd)
{
	//--------------------------------------------------------------------------------------
	// ��Direct3D��ʼ���Ĳ���֮һ�����ӿڡ�������Direct3D�ӿڶ���, �Ա��ø�Direct3D���󴴽�Direct3D�豸����
	//--------------------------------------------------------------------------------------
	LPDIRECT3D9   pD3D = NULL; //Direct3D�ӿڶ���Ĵ���
	if (NULL == (pD3D = Direct3DCreate9(D3D_SDK_VERSION))) //��ʼ��Direct3D�ӿڶ��󣬲�����DirectX�汾Э��
	{
		return E_FAIL;
	}
	//--------------------------------------------------------------------------------------
	// ��Direct3D��ʼ���Ĳ���֮��,ȡ��Ϣ������ȡӲ���豸��Ϣ
	//--------------------------------------------------------------------------------------
	D3DCAPS9 caps; int vp = 0;			// ��D3DCAPS9�ṹ�屣��Ӳ���豸��Ϣ
	if (FAILED(pD3D->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &caps)))
	{
		return E_FAIL;
	}
	if (caps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
		vp = D3DCREATE_HARDWARE_VERTEXPROCESSING;   //֧��Ӳ���������㣬���ǾͲ���Ӳ���������㣬���׵�
	else
		vp = D3DCREATE_SOFTWARE_VERTEXPROCESSING; //��֧��Ӳ���������㣬����ֻ�ò��������������

	//--------------------------------------------------------------------------------------
	// ��Direct3D��ʼ���Ĳ���֮���������ݡ������D3DPRESENT_PARAMETERS�ṹ��
	//--------------------------------------------------------------------------------------
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.BackBufferWidth = WINDOW_WIDTH;
	d3dpp.BackBufferHeight = WINDOW_HEIGHT;
	d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;
	d3dpp.BackBufferCount = 1;										// �ж��ٸ���̨������
	d3dpp.MultiSampleType = D3DMULTISAMPLE_NONE;
	d3dpp.MultiSampleQuality = 0;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.hDeviceWindow = hwnd;									// ���ھ����ָ������һ�����ڻ���
	d3dpp.Windowed = true;
	d3dpp.EnableAutoDepthStencil = true;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D24S8;
	d3dpp.Flags = 0;
	d3dpp.FullScreen_RefreshRateInHz = 0;
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;

	//--------------------------------------------------------------------------------------
	// ��Direct3D��ʼ���Ĳ���֮�ģ����豸��������Direct3D�豸�ӿ�
	//--------------------------------------------------------------------------------------
	if (FAILED(pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL,
		hwnd, vp, &d3dpp, &g_pd3dDevice)))
		return E_FAIL;


	//g_pd3dDevice ����ָ��direct3d�豸�ӿڵľ�������ǻ���direct3D�Ľ�Կ��
	SAFE_RELEASE(pD3D) //LPDIRECT3D9�ӿڶ����ʹ����ɣ����ǽ����ͷŵ�

	if (!(S_OK == Objects_Init(hwnd))) return E_FAIL;     //����һ��Objects_Init��������Ⱦ��Դ�ĳ�ʼ��
	return S_OK;
}



//-----------------------------------��Object_Init( )������--------------------------------------
//	��������Ⱦ��Դ��ʼ���������ڴ˺����н���Ҫ����Ⱦ���������Դ�ĳ�ʼ��
//--------------------------------------------------------------------------------------------------
HRESULT Objects_Init(HWND hwnd)
{
	if (FAILED(D3DXCreateFont(g_pd3dDevice, 36, 0, 0, 1, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, 0,
		_T("΢���ź�"), &g_pFont)))
	{
		return E_FAIL;
		srand(timeGetTime());// �趨ʱ�����������ӣ�timeGetTime()���غ��뼶ʱ��
	}

	// ���㻺��ʹ���Ĳ�����2 �������㻺��
	if (FAILED(g_pd3dDevice->CreateVertexBuffer(6*sizeof(CUSTOMVERTEX),0,D3DFVF_CUSTOMVERTEX,D3DPOOL_DEFAULT,&g_pVertexBuffer,NULL)))
	{
		return E_FAIL;
	}

	// ���㻺��ʹ���Ĳ�����3 ���ʶ��㻺��
	// �������ݵ�����
	CUSTOMVERTEX vertices[] = {
		//����rand���� ���������������ɫ��λ��
		//����rand���������������������ɫ��λ��
		{ 300.0f, 100.0f, 0.0f, 1.0f, D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256), },
		{ 500.0f, 100.0f, 0.0f, 1.0f, D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256), },
		{ 300.0f, 300.0f, 0.0f, 1.0f, D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256), },
		{ 300.0f, 300.0f, 0.0f, 1.0f, D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256), },
		{ (float)(800.0*rand() / (RAND_MAX + 1.0)), (float)(600.0*rand() / (RAND_MAX + 1.0)), 0.0f, 1.0f, D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256), },
		{ (float)(800.0*rand() / (RAND_MAX + 1.0)), (float)(600.0*rand() / (RAND_MAX + 1.0)), 0.0f, 1.0f, D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256), }
	};

	// ��䶥�㻺����
	VOID *pvertices;
	if (FAILED(g_pVertexBuffer->Lock(0,sizeof(vertices),(void **)&pvertices,0)))
	{
		return E_FAIL;
	}
	memcpy(pvertices, vertices, sizeof(vertices));
	g_pVertexBuffer->Unlock();
	g_pd3dDevice->SetRenderState(D3DRS_CULLMODE, false);   //�ص����������������Ƿ�˳ʱ�룬������Ǹ������ζ�����ʾ��
	return S_OK;
}


//-----------------------------------��Direct3D_Render( )������--------------------------------------
//	������ʹ��Direct3D������Ⱦ
//--------------------------------------------------------------------------------------------------
void Direct3D_Render(HWND hwnd)
{
	//��ʱΪ�գ������»طֽ�
	//��Ϸ��Ⱦ5������1������������ ��Կ��Ϊg_pd3dDevice
	g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
	//��Ϸ��Ⱦ5������2������ʼ����
	g_pd3dDevice->BeginScene();		//g_pd3dDevice�����豸����ʼ����
	//��Ϸ��Ⱦ5������3������ʽ����
	RECT formatRect;// ����һ�������������ڻ�ȡ�����ڵľ���
	GetClientRect(hwnd, &formatRect);		// ��ȡ�����ھ��β���ֵ���ṹ��
	int charCount = swprintf_s(g_strFps, 20,_T("FPS: %0.3f"), Get_Fps());
	// ���㻺����Ĳ�������ͼ��
	g_pd3dDevice->SetStreamSource(0, g_pVertexBuffer, 0, sizeof(CUSTOMVERTEX));
	g_pd3dDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
	g_pd3dDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);

	g_pFont->DrawText(0, g_strFps, charCount, &formatRect, DT_TOP|DT_RIGHT, D3DCOLOR_XRGB(255, 39, 136));

	//��Ϸ��Ⱦ5������4������������
	g_pd3dDevice->EndScene();		//g_pd3dDevice�����豸�����������
	//��Ϸ��Ⱦ5������5������ת��ʾ
	// ֮ǰ�Ĳ�������Ļ����ʾ�����÷�ת��ʾ���ܴ�Ļ���ת��̨ǰ
	g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}


//-----------------------------------��Direct3D_CleanUp( )������--------------------------------
//	��������Դ���������ڴ˺����н��г����˳�ǰ��Դ��������
//---------------------------------------------------------------------------------------------------
void Direct3D_CleanUp()
{
	//��ʱΪ�գ������»طֽ�
	SAFE_RELEASE(g_pFont);
	SAFE_RELEASE(g_pd3dDevice);
}

float Get_Fps()
{
	static float fps = 0;
	static int frameCount = 0;
	static float currentTime = 0.0f;
	static float lastTime = 0.0f;

	// ����һ�ξ�����һ��
	frameCount++;

	currentTime = timeGetTime() * 0.001f;		// ��ȡʱ�䣬ת��Ϊ����
	if ((currentTime - lastTime) > 1.0f)
	{
		fps = (float)frameCount / (currentTime - lastTime);
		lastTime = timeGetTime() * 0.001f;
		frameCount = 0;  // �����ε�֡����գ��ȴ�һ���Ժ��ٴε���
	}
	return fps;
}

//-----------------------------------������˵����----------------------------------------------
//  ��������:��D3DdemoCore
//	 2018��11Create by hc
//  ������Direct3D����ĺ��Ŀ��
//------------------------------------------------------------------------------------------------

//-----------------------------------��ͷ�ļ��������֡�---------------------------------------
//	����������������������ͷ�ļ�
//------------------------------------------------------------------------------------------------

#include <d3d9.h>
#include <d3dx9.h>
#include <windows.h>
#include <tchar.h>
// ---------------------------------- - �����ļ��������֡�-------------------------------------- -
//	���������������������Ŀ��ļ�
//------------------------------------------------------------------------------------------------
#pragma comment(lib,"winmm.lib")		// playsound����Ҫ���ļ���

//-----------------------------------���궨�岿�֡�--------------------------------------------
//	����������һЩ������
//------------------------------------------------------------------------------------------------
#define WINDOW_WIDTH	800							//Ϊ���ڿ�ȶ���ĺ꣬�Է����ڴ˴��޸Ĵ��ڿ��
#define WINDOW_HEIGHT	600							//Ϊ���ڸ߶ȶ���ĺ꣬�Է����ڴ˴��޸Ĵ��ڸ߶�
#define WINDOW_TITLE	L"������������Ϩ�����Ϸ�������롿Direct3D����ĺ��Ŀ��"	//Ϊ���ڱ��ⶨ��ĺ�
#define SAFE_RELEASE(p) {if(p){(p)->Release();(p)=NULL;}}   //����һ����ȫ�ͷź꣬���ں���COM�ӿ�ָ����ͷ�

// ���㻺��ʹ���Ĳ�����һ������������ʽ
struct CUSTOMVERTEX
{
	FLOAT x, y, z;
	DWORD color;
};
#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZ|D3DFVF_DIFFUSE)     // fvf�����ʽ
//D3DFVF_XYZ �� D3DFVF_XYZRHW����������û�о�������任�����Ҫ����任����ԭʼ����
//-----------------------------------��ȫ�ֱ����������֡�-------------------------------------
//	������ȫ�ֱ���������
//------------------------------------------------------------------------------------------------
LPDIRECT3DDEVICE9 g_pd3dDevice = NULL;			//direct3D�豸����
ID3DXFont* g_pFont = NULL;						// ����ӿ�
float g_Fps = 0.0f;								// ֡��
wchar_t g_strFps[50];							// ֡�ʵ��ַ�������
LPDIRECT3DVERTEXBUFFER9 g_pVertexBuffer = NULL;	// ���㻺�����
LPDIRECT3DINDEXBUFFER9  g_pIndexBufer = NULL;	// �����������

//-----------------------------------��ȫ�ֺ����������֡�-------------------------------------
//	������ȫ�ֺ�����������ֹ��δ�����ı�ʶ��ϵ�д���
//------------------------------------------------------------------------------------------------
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);// ���ڹ��̺���������
HRESULT Direct3D_Init(HWND hwnd);		// Direct3D�ĳ�ʼ��
HRESULT Objects_Init(HWND hwnd);		// ��Դ��ʼ��
VOID Direct3D_Render(HWND hwnd);
VOID Direct3D_CleanUp();      // ������Դ
float							Get_FPS();
VOID			Matrix_Set();		

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
	Direct3D_Init(hwnd);

	//��4�����ڴ����Ĳ���֮�ģ����ڵ��ƶ�����ʾ�����
	MoveWindow(hwnd, 250, 80, WINDOW_WIDTH, WINDOW_HEIGHT, true);
	ShowWindow(hwnd, nShowCmd);
	UpdateWindow(hwnd);

	PlaySound(L"War3XMainScreen.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	//MessageBox(hwnd, L"DirectX�������ưɣ���������������~!", L"ǳī����Ϣ����", 0); //ʹ��MessageBox��������ʾһ����Ϣ����

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
	LPDIRECT3D9  pD3D = NULL; //Direct3D�ӿڶ���Ĵ���
	if (NULL == (pD3D = Direct3DCreate9(D3D_SDK_VERSION))) //��ʼ��Direct3D�ӿڶ��󣬲�����DirectX�汾Э��
		return E_FAIL;

	//--------------------------------------------------------------------------------------
	// ��Direct3D��ʼ���Ĳ���֮��,ȡ��Ϣ������ȡӲ���豸��Ϣ
	//--------------------------------------------------------------------------------------
	D3DCAPS9 caps; int vp = 0;
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
	d3dpp.BackBufferCount = 1;
	d3dpp.MultiSampleType = D3DMULTISAMPLE_NONE;
	d3dpp.MultiSampleQuality = 0;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.hDeviceWindow = hwnd;
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

	SAFE_RELEASE(pD3D) //LPDIRECT3D9�ӿڶ����ʹ����ɣ����ǽ����ͷŵ�


	if (!(S_OK == Objects_Init(hwnd))) return E_FAIL;     //����һ��Objects_Init��������Ⱦ��Դ�ĳ�ʼ��

	// ������Ⱦ״̬
	g_pd3dDevice->SetRenderState(D3DRS_LIGHTING, FALSE);      //�رչ���
	g_pd3dDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);   //������������

	return S_OK;
}



//-----------------------------------��Object_Init( )������--------------------------------------
//	��������Ⱦ��Դ��ʼ���������ڴ˺����н���Ҫ����Ⱦ���������Դ�ĳ�ʼ��
//--------------------------------------------------------------------------------------------------
HRESULT Objects_Init(HWND hwnd)
{
	// �����������
	if (FAILED(D3DXCreateFont(g_pd3dDevice,36,0,0,1,false,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,DEFAULT_QUALITY,0,_T("΢���ź�"),&g_pFont)))
	{
		return E_FAIL;
	}
	srand(timeGetTime());													// ��ʱ����Ϊ���������timeGetTime()����ms��ʱ��

	// �������������Ĳ���֮�� �����������������
	// �������㻺��
	if (FAILED(g_pd3dDevice->CreateVertexBuffer(8*sizeof(CUSTOMVERTEX),0,D3DFVF_CUSTOMVERTEX,D3DPOOL_DEFAULT,
		&g_pVertexBuffer,NULL)))
	{
		return E_FAIL;
	}

	// ������������
	if (FAILED(g_pd3dDevice->CreateIndexBuffer(36*sizeof(WORD),0,D3DFMT_INDEX16,D3DPOOL_DEFAULT,&g_pIndexBufer,NULL)))
	{
		return E_FAIL;
	}

	// �������������Ĳ���֮�� ���ʶ��㻺�����������
	CUSTOMVERTEX Vertices[] = {
		{-20.0f,20.0f,-20.0f,D3DCOLOR_XRGB(rand() % 256,rand() % 256,rand() % 256)},
		{-20.0f,20.0f,20.0f,D3DCOLOR_XRGB(rand() % 256,rand() % 256,rand() % 256)},
		{20.0f,20.0f,20.0f,D3DCOLOR_XRGB(rand() % 256,rand() % 256,rand() % 256)},
		{20.0f,20.0f,-20.0f,D3DCOLOR_XRGB(rand() % 256,rand() % 256,rand() % 256)},
		{-20.0f,-20.0f,-20.0f,D3DCOLOR_XRGB(rand() % 256,rand() % 256,rand() % 256)},
		{-20.0f,-20.0f,20.0f,D3DCOLOR_XRGB(rand() % 256,rand() % 256,rand() % 256)},
		{20.0f,-20.0f,20.0f,D3DCOLOR_XRGB(rand() % 256,rand() % 256,rand() % 256)},
		{20.0f,-20.0f,-20.0f,D3DCOLOR_XRGB(rand() % 256,rand() % 256,rand() % 256)},
	};

	// ��䶥�㻺��
	VOID *pVertices;
	if (FAILED(g_pVertexBuffer->Lock(0,sizeof(Vertices),(void **)&pVertices,0)))
	{
		return E_FAIL;
	}
	memcpy(pVertices, Vertices, sizeof(Vertices));
	g_pVertexBuffer->Unlock();

	// �����������
	WORD *pIndex = NULL;
	g_pIndexBufer->Lock(0, 0, (void **)&pIndex, 0);
	// ����
	pIndex[0] = 0, pIndex[1] = 1, pIndex[2] = 2;
	pIndex[3] = 0, pIndex[4] = 2, pIndex[5] = 3;
	// ����
	pIndex[6] = 0, pIndex[7] = 3, pIndex[8] = 7;
	pIndex[9] = 0, pIndex[10] = 7, pIndex[11] = 4;
	// �����
	pIndex[12] = 0, pIndex[13] = 4, pIndex[14] = 5;
	pIndex[15] = 0, pIndex[16] = 5, pIndex[17] = 1;
	// �Ҳ���
	pIndex[18] = 2, pIndex[19] = 6, pIndex[20] = 7;
	pIndex[21] = 2, pIndex[22] = 7, pIndex[23] = 3;
	// ����
	pIndex[24] = 2, pIndex[25] = 5, pIndex[26] = 6;
	pIndex[27] = 2, pIndex[28] = 1, pIndex[29] = 5;
	// ����
	pIndex[30] = 4, pIndex[31] = 6, pIndex[32] = 5;
	pIndex[33] = 4, pIndex[34] = 7, pIndex[35] = 6;

	g_pIndexBufer->Unlock();

	// ������Ⱦģʽ
	g_pd3dDevice->SetRenderState(D3DRS_LIGHTING, false);    // �رչ���
	g_pd3dDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);	// ������������

	return S_OK;
}


//-----------------------------------��Direct3D_Render( )������--------------------------------------
//	������ʹ��Direct3D������Ⱦ
//--------------------------------------------------------------------------------------------------
void Direct3D_Render(HWND hwnd)
{
	//--------------------------------------------------------------------------------------
	// ��Direct3D��Ⱦ�岽��֮һ������������
	//--------------------------------------------------------------------------------------
	g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(255, 200, 158), 1.0f, 0);
	//����һ�����Σ����ڻ�ȡ�����ھ���
	RECT formatRect;
	GetClientRect(hwnd, &formatRect);
	//--------------------------------------------------------------------------------------
	// ��Direct3D��Ⱦ�岽��֮��������ʼ����
	//--------------------------------------------------------------------------------------
	g_pd3dDevice->BeginScene();                     // ��ʼ����
	//--------------------------------------------------------------------------------------
	// ��Direct3D��Ⱦ�岽��֮��������ʽ���ƣ����ö��㻺�����ͼ��
	//--------------------------------------------------------------------------------------
	//----------------------------------------------------------------
	// �����㻺�桢���������ͼ�Ĳ���֮�ġ�������ͼ��
	//----------------------------------------------------------------
	Matrix_Set();;//���÷�װ���Ĵ�任�ĺ�������Direct3D����任��ȡ���任��ͶӰ�任���ӿڱ任��������
	// ��ȡ������Ϣ������������Ӧ�����ģʽ
	if (::GetAsyncKeyState(VK_UP))         // �����ּ�1�����£������߿����
		g_pd3dDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
	if (::GetAsyncKeyState(VK_DOWN))         // �����ּ�2�����£�����ʵ�����
		g_pd3dDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);				// ����Ϊ�����
	
	g_pd3dDevice->SetStreamSource(0, g_pVertexBuffer, 0, sizeof(CUSTOMVERTEX));				// ������Ⱦ��ˮ��
	g_pd3dDevice->SetFVF(D3DFVF_CUSTOMVERTEX);								// ָ��FVFΪ���趨�ĺ��ʽ
	g_pd3dDevice->SetIndices(g_pIndexBufer);					// �趨��������
	g_pd3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 8, 0, 12);	// ����
	
	//�ڴ������ϽǴ�����ʾÿ��֡��
	int charCount = swprintf_s(g_strFps, 20, _T("FPS:%0.3f"), Get_FPS());
	g_pFont->DrawText(NULL, g_strFps, charCount, &formatRect, DT_TOP | DT_RIGHT, D3DCOLOR_XRGB(255, 39, 136));

	//--------------------------------------------------------------------------------------
	// ��Direct3D��Ⱦ�岽��֮�ġ�����������
	//--------------------------------------------------------------------------------------
	g_pd3dDevice->EndScene();                       // ��������
	//--------------------------------------------------------------------------------------
	// ��Direct3D��Ⱦ�岽��֮�塿����ʾ��ת
	//--------------------------------------------------------------------------------------
	g_pd3dDevice->Present(NULL, NULL, NULL, NULL);  // ��ת����ʾ
}


//-----------------------------------��Direct3D_CleanUp( )������--------------------------------
//	��������Դ���������ڴ˺����н��г����˳�ǰ��Դ��������
//---------------------------------------------------------------------------------------------------
void Direct3D_CleanUp()
{
	//�ͷ�COM�ӿڶ���
	SAFE_RELEASE(g_pIndexBufer);
	SAFE_RELEASE(g_pVertexBuffer);
	SAFE_RELEASE(g_pFont);
	SAFE_RELEASE(g_pd3dDevice);
}


//-----------------------------------��Get_FPS( )������------------------------------------------
//	���������ڼ���ÿ��֡���ʵ�һ������
//--------------------------------------------------------------------------------------------------
float Get_FPS()
{
	//�����ĸ���̬����
	static float  fps = 0; //������Ҫ�����FPSֵ
	static int     frameCount = 0;//֡��
	static float  currentTime = 0.0f;//��ǰʱ��
	static float  lastTime = 0.0f;//����ʱ��

	frameCount++;//ÿ����һ��Get_FPS()������֡������1
	currentTime = timeGetTime()*0.001f;//��ȡϵͳʱ�䣬����timeGetTime�������ص����Ժ���Ϊ��λ��ϵͳʱ�䣬������Ҫ����0.001���õ���λΪ���ʱ��

	//�����ǰʱ���ȥ����ʱ�������1���ӣ��ͽ���һ��FPS�ļ���ͳ���ʱ��ĸ��£�����֡��ֵ����
	if (currentTime - lastTime > 1.0f) //��ʱ�������1����
	{
		fps = (float)frameCount / (currentTime - lastTime);//������1���ӵ�FPSֵ
		lastTime = currentTime; //����ǰʱ��currentTime��������ʱ��lastTime����Ϊ��һ��Ļ�׼ʱ��
		frameCount = 0;//������֡��frameCountֵ����
	}

	return fps;
}


VOID			Matrix_Set()
{
	srand(timeGetTime());
	//--------------------------------------------------------------------------------------
	//���Ĵ�任֮һ��������任���������
	//--------------------------------------------------------------------------------------
	D3DXMATRIX matWorld, Rx, Ry, Rz;
	D3DXMatrixIdentity(&matWorld);					// ��λ���������
	D3DXMatrixRotationX(&Rx, D3DX_PI*(::timeGetTime() / 1000.0f));
	D3DXMatrixRotationY(&Ry, D3DX_PI*(::timeGetTime() / 1000.0f/2));
	D3DXMatrixRotationZ(&Rz, D3DX_PI*(::timeGetTime() / 1000.0f/3));

	matWorld = matWorld * Rx * Ry * Rz;
	g_pd3dDevice->SetTransform(D3DTS_WORLD, &matWorld);

	//--------------------------------------------------------------------------------------
	//���Ĵ�任֮������ȡ���任���������
	//--------------------------------------------------------------------------------------
	D3DXMATRIX matView;			// ����һ������
	D3DXVECTOR3 vEye(0.0f, 0.0f, -200.0f);			// ���������λ��
	D3DXVECTOR3 vAt(0.0f, 0.0f, 0.0f);				// ����۲���λ��
	D3DXVECTOR3 vUp(0.0f, 1.0f, 0.0f);				// �������ϵ�����
	D3DXMatrixLookAtLH(&matView, &vEye, &vAt, &vUp);	// ����ȡ���任����
	g_pd3dDevice->SetTransform(D3DTS_VIEW, &matView);

	//--------------------------------------------------------------------------------------
	//���Ĵ�任֮������ͶӰ�任���������
	//--------------------------------------------------------------------------------------
	D3DXMATRIX matProj;		// ����һ������
	D3DXMatrixPerspectiveFovLH(&matProj, D3DX_PI / 4.0f, 1.0f, 1.0f, 1000.f);
	g_pd3dDevice->SetTransform(D3DTS_PROJECTION, &matProj);


	//--------------------------------------------------------------------------------------
	//���Ĵ�任֮�ġ����ӿڱ任������
	//--------------------------------------------------------------------------------------
	D3DVIEWPORT9 vp; //ʵ����һ��D3DVIEWPORT9�ṹ�壬Ȼ��������������������ֵ�Ϳ�����
	vp.X = 0;		//��ʾ�ӿ�����ڴ��ڵ�X����
	vp.Y = 0;		//�ӿ���ԶԴ��ڵ�Y����
	vp.Width = WINDOW_WIDTH;	//�ӿڵĿ��
	vp.Height = WINDOW_HEIGHT; //�ӿڵĸ߶�
	vp.MinZ = 0.0f; //�ӿ�����Ȼ����е���С���ֵ
	vp.MaxZ = 1.0f;	//�ӿ�����Ȼ����е�������ֵ
	g_pd3dDevice->SetViewport(&vp); //�ӿڵ�����

}
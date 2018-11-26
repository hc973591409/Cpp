
//-----------------------------------【程序说明】----------------------------------------------
//  程序名称:：D3DdemoCore
//	 2018年11Create by hc
//  描述：Direct3D绘制基础，顶点缓存
//------------------------------------------------------------------------------------------------

//-----------------------------------【头文件包含部分】---------------------------------------
//	描述：包含程序所依赖的头文件
//------------------------------------------------------------------------------------------------

#include <d3d9.h>
#include <d3dx9.h>		// 提供了数学运算，文理，和图像运算，网格运算，等	
#include <tchar.h>
// ---------------------------------- - 【库文件包含部分】-------------------------------------- -
//	描述：包含程序所依赖的库文件
//------------------------------------------------------------------------------------------------
//#pragma comment(lib,"winmm.lib")		// playsound所需要的文件库
//#pragma comment(lib,"d3d9.lib")
//#pragma comment(lib,"d3dx9.lib")		// 由于我们在链接库定义了。所以这里可以不用谢依赖库、

//-----------------------------------【宏定义部分】--------------------------------------------
//	描述：定义一些辅助宏
//------------------------------------------------------------------------------------------------
LPDIRECT3DDEVICE9 g_pd3dDevice = NULL; //Direct3D设备对象
ID3DXFont* g_pFont = NULL;				// 字体COM接口
float g_Fps = 0.0f;
wchar_t g_strFps[50];					// 一个包含帧率的字符串数组
LPDIRECT3DVERTEXBUFFER9 g_pVertexBuffer = NULL;		// 定点缓冲区对象


//-----------------------------------【全局变量声明部分】-------------------------------------
//	描述：全局变量的声明
//------------------------------------------------------------------------------------------------
#define WINDOW_WIDTH	800							//为窗口宽度定义的宏，以方便在此处修改窗口宽度
#define WINDOW_HEIGHT	600							//为窗口高度定义的宏，以方便在此处修改窗口高度
#define WINDOW_TITLE	L"【致我们永不熄灭的游戏开发梦想】Direct3D程序的核心框架"	//为窗口标题定义的宏
#define SAFE_RELEASE(p) { if(p) { (p)->Release(); (p)=NULL; } }   //定义一个安全释放宏，便于后面COM接口指针的释放

//-----------------------------------【全局函数声明部分】-------------------------------------
//	描述：全局函数声明，防止“未声明的标识”系列错误
//------------------------------------------------------------------------------------------------
// 顶点缓存四部曲  1.设计顶点格式
struct CUSTOMVERTEX
{
	float x, y, z, rhw;
	DWORD color;
};
// 宏定义，表示我们创建了灵活定点FVF结构体
#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZRHW|D3DFVF_DIFFUSE)		

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);// 窗口过程函数的声明
HRESULT Direct3D_Init(HWND hwnd);		// Direct3D的初始化
HRESULT Objects_Init(HWND hwnd);		// 资源初始化
VOID Direct3D_Render(HWND hwnd);
VOID Direct3D_CleanUp();      // 清理资源
float Get_Fps();




//-----------------------------------【WinMain( )函数】--------------------------------------
//	描述：Windows应用程序的入口函数，我们的程序从这里开始
//------------------------------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
	LPSTR lpCmdLine, int nShowCmd)
{
	//【1】窗口创建四步曲之一：开始设计一个完整的窗口类
	WNDCLASSEX wndClass = { 0 };
	wndClass.cbSize = sizeof(WNDCLASSEX);			//设置结构体的字节数大小
	wndClass.style = CS_HREDRAW | CS_VREDRAW;	//设置窗口的样式
	wndClass.lpfnWndProc = WndProc;					//设置指向窗口过程函数的指针
	wndClass.cbClsExtra = 0;								//窗口类的附加内存，取0就可以了
	wndClass.cbWndExtra = 0;							//窗口的附加内存，依然取0就行了
	wndClass.hInstance = hInstance;						//指定包含窗口过程的程序的实例句柄。
	wndClass.hIcon = (HICON)::LoadImage(NULL, L"icon.ico", IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_LOADFROMFILE);  //本地加载自定义ico图标
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);    //指定窗口类的光标句柄。
	wndClass.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);  //为hbrBackground成员指定一个白色画刷句柄	
	wndClass.lpszMenuName = NULL;						//用一个以空终止的字符串，指定菜单资源的名字。
	wndClass.lpszClassName = L"ForTheDreamOfGameDevelop";	//用一个以空终止的字符串，指定窗口类的名字。

	//【2】窗口创建四步曲之二：注册窗口类
	if (!RegisterClassEx(&wndClass))
	{
		MessageBox(0, L"RegisterClassEx fail", L"msg", 0);
	}
	//【3】窗口创建四步曲之三：正式创建窗口
	HWND hwnd = CreateWindow(L"ForTheDreamOfGameDevelop", WINDOW_TITLE, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, WINDOW_WIDTH, WINDOW_HEIGHT, NULL, NULL, hInstance, NULL);

	//Direct3D资源的初始化
	if (Direct3D_Init(hwnd) == S_OK)
	{
		MessageBox(hwnd, L"Direct3D初始化完成~！", L"hc的消息窗口", 0); //使用MessageBox函数，创建一个消息窗口  
	}
	else
	{
		MessageBox(hwnd, L"Direct3D初始化失败~！", L"hc的消息窗口", 0); //使用MessageBox函数，创建一个消息窗口
	}

	//【4】窗口创建四步曲之四：窗口的移动、显示与更新
	MoveWindow(hwnd, 250, 80, WINDOW_WIDTH, WINDOW_HEIGHT, true);
	ShowWindow(hwnd, nShowCmd);
	UpdateWindow(hwnd);

	PlaySound(L"Final Fantasy XIII.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	MessageBox(hwnd, L"DirectX，等着瞧吧，我们来降服你了~!", L"浅墨的消息窗口", 0); //使用MessageBox函数，显示一个消息窗口

	//【5】消息循环过程
	MSG msg = { 0 };//初始化msg
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))//查看应用程序消息队列，有消息时将队列中的消息派发出去。
		{
			TranslateMessage(&msg);//将虚拟键消息转换为字符消息
			DispatchMessage(&msg);		//该函数分发一个消息给窗口程序。
		}
		else
		{
			Direct3D_Render(hwnd);   //进行渲染
		}
	}
	//【6】窗口类的注销
	UnregisterClass(L"ForTheDreamOfGameDevelop", wndClass.hInstance);
	return 0;
}

//-----------------------------------【WndProc( )函数】--------------------------------------
//	描述：窗口过程函数WndProc,对窗口消息进行处理
//------------------------------------------------------------------------------------------------
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)						//switch语句开始
	{
	case WM_PAINT:						// 若是客户区重绘消息
		Direct3D_Render(hwnd);                 //调用Direct3D渲染函数
		ValidateRect(hwnd, NULL);		// 更新客户区的显示
		break;									//跳出该switch语句

	case WM_KEYDOWN:					// 若是键盘按下消息
		if (wParam == VK_ESCAPE)    // 如果被按下的键是ESC
			DestroyWindow(hwnd);		// 销毁窗口, 并发送一条WM_DESTROY消息
		break;									//跳出该switch语句

	case WM_DESTROY:					//若是窗口销毁消息
		Direct3D_CleanUp();			//调用自定义的资源清理函数Game_CleanUp（）进行退出前的资源清理
		PostQuitMessage(0);			//向系统表明有个线程有终止请求。用来响应WM_DESTROY消息
		break;									//跳出该switch语句

	default:										//若上述case条件都不符合，则执行该default语句
		return DefWindowProc(hwnd, message, wParam, lParam);		//调用缺省的窗口过程
	}

	return 0;									//正常退出
}

//-----------------------------------【Direct3D_Init( )函数】--------------------------------------
//	描述：Direct3D初始化函数，进行Direct3D的初始化
//------------------------------------------------------------------------------------------------
HRESULT Direct3D_Init(HWND hwnd)
{
	//--------------------------------------------------------------------------------------
	// 【Direct3D初始化四步曲之一，创接口】：创建Direct3D接口对象, 以便用该Direct3D对象创建Direct3D设备对象
	//--------------------------------------------------------------------------------------
	LPDIRECT3D9   pD3D = NULL; //Direct3D接口对象的创建
	if (NULL == (pD3D = Direct3DCreate9(D3D_SDK_VERSION))) //初始化Direct3D接口对象，并进行DirectX版本协商
	{
		return E_FAIL;
	}
	//--------------------------------------------------------------------------------------
	// 【Direct3D初始化四步曲之二,取信息】：获取硬件设备信息
	//--------------------------------------------------------------------------------------
	D3DCAPS9 caps; int vp = 0;			// 用D3DCAPS9结构体保存硬件设备信息
	if (FAILED(pD3D->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &caps)))
	{
		return E_FAIL;
	}
	if (caps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
		vp = D3DCREATE_HARDWARE_VERTEXPROCESSING;   //支持硬件顶点运算，我们就采用硬件顶点运算，妥妥的
	else
		vp = D3DCREATE_SOFTWARE_VERTEXPROCESSING; //不支持硬件顶点运算，无奈只好采用软件顶点运算

	//--------------------------------------------------------------------------------------
	// 【Direct3D初始化四步曲之三，填内容】：填充D3DPRESENT_PARAMETERS结构体
	//--------------------------------------------------------------------------------------
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.BackBufferWidth = WINDOW_WIDTH;
	d3dpp.BackBufferHeight = WINDOW_HEIGHT;
	d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;
	d3dpp.BackBufferCount = 1;										// 有多少个后台缓冲区
	d3dpp.MultiSampleType = D3DMULTISAMPLE_NONE;
	d3dpp.MultiSampleQuality = 0;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.hDeviceWindow = hwnd;									// 窗口句柄，指定在哪一个窗口绘制
	d3dpp.Windowed = true;
	d3dpp.EnableAutoDepthStencil = true;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D24S8;
	d3dpp.Flags = 0;
	d3dpp.FullScreen_RefreshRateInHz = 0;
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;

	//--------------------------------------------------------------------------------------
	// 【Direct3D初始化四步曲之四，创设备】：创建Direct3D设备接口
	//--------------------------------------------------------------------------------------
	if (FAILED(pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL,
		hwnd, vp, &d3dpp, &g_pd3dDevice)))
		return E_FAIL;


	//g_pd3dDevice 就是指向direct3d设备接口的句柄，就是绘制direct3D的金钥匙
	SAFE_RELEASE(pD3D) //LPDIRECT3D9接口对象的使命完成，我们将其释放掉

	if (!(S_OK == Objects_Init(hwnd))) return E_FAIL;     //调用一次Objects_Init，进行渲染资源的初始化
	return S_OK;
}



//-----------------------------------【Object_Init( )函数】--------------------------------------
//	描述：渲染资源初始化函数，在此函数中进行要被渲染的物体的资源的初始化
//--------------------------------------------------------------------------------------------------
HRESULT Objects_Init(HWND hwnd)
{
	if (FAILED(D3DXCreateFont(g_pd3dDevice, 36, 0, 0, 1, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, 0,
		_T("微软雅黑"), &g_pFont)))
	{
		return E_FAIL;
		srand(timeGetTime());// 设定时间的随机数种子，timeGetTime()返回毫秒级时间
	}

	// 定点缓存使用四部曲：2 创建定点缓存
	if (FAILED(g_pd3dDevice->CreateVertexBuffer(6*sizeof(CUSTOMVERTEX),0,D3DFVF_CUSTOMVERTEX,D3DPOOL_DEFAULT,&g_pVertexBuffer,NULL)))
	{
		return E_FAIL;
	}

	// 定点缓存使用四部曲：3 访问定点缓存
	// 定点数据的设置
	CUSTOMVERTEX vertices[] = {
		//采用rand函数 给定点以随机的颜色和位置
		//采用rand函数，给顶点以随机的颜色和位置
		{ 300.0f, 100.0f, 0.0f, 1.0f, D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256), },
		{ 500.0f, 100.0f, 0.0f, 1.0f, D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256), },
		{ 300.0f, 300.0f, 0.0f, 1.0f, D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256), },
		{ 300.0f, 300.0f, 0.0f, 1.0f, D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256), },
		{ (float)(800.0*rand() / (RAND_MAX + 1.0)), (float)(600.0*rand() / (RAND_MAX + 1.0)), 0.0f, 1.0f, D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256), },
		{ (float)(800.0*rand() / (RAND_MAX + 1.0)), (float)(600.0*rand() / (RAND_MAX + 1.0)), 0.0f, 1.0f, D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256), }
	};

	// 填充顶点缓冲区
	VOID *pvertices;
	if (FAILED(g_pVertexBuffer->Lock(0,sizeof(vertices),(void **)&pvertices,0)))
	{
		return E_FAIL;
	}
	memcpy(pvertices, vertices, sizeof(vertices));
	g_pVertexBuffer->Unlock();
	g_pd3dDevice->SetRenderState(D3DRS_CULLMODE, false);   //关掉背面消隐，无论是否顺时针，随机的那个三角形都会显示。
	return S_OK;
}


//-----------------------------------【Direct3D_Render( )函数】--------------------------------------
//	描述：使用Direct3D进行渲染
//--------------------------------------------------------------------------------------------------
void Direct3D_Render(HWND hwnd)
{
	//暂时为空，且听下回分解
	//游戏渲染5部曲（1）：清屏操作 金钥匙为g_pd3dDevice
	g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
	//游戏渲染5部曲（2）：开始场景
	g_pd3dDevice->BeginScene();		//g_pd3dDevice利用设备对象开始绘制
	//游戏渲染5部曲（3）：正式绘制
	RECT formatRect;// 定义一个矩形区域，用于获取主窗口的矩形
	GetClientRect(hwnd, &formatRect);		// 获取主窗口矩形并赋值给结构体
	int charCount = swprintf_s(g_strFps, 20,_T("FPS: %0.3f"), Get_Fps());
	// 顶点缓存第四部，绘制图形
	g_pd3dDevice->SetStreamSource(0, g_pVertexBuffer, 0, sizeof(CUSTOMVERTEX));
	g_pd3dDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
	g_pd3dDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);

	g_pFont->DrawText(0, g_strFps, charCount, &formatRect, DT_TOP|DT_RIGHT, D3DCOLOR_XRGB(255, 39, 136));

	//游戏渲染5部曲（4）：结束场景
	g_pd3dDevice->EndScene();		//g_pd3dDevice利用设备对象结束绘制
	//游戏渲染5部曲（5）：反转显示
	// 之前的操作都是幕后显示，调用翻转显示才能从幕后调转到台前
	g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}


//-----------------------------------【Direct3D_CleanUp( )函数】--------------------------------
//	描述：资源清理函数，在此函数中进行程序退出前资源的清理工作
//---------------------------------------------------------------------------------------------------
void Direct3D_CleanUp()
{
	//暂时为空，且听下回分解
	SAFE_RELEASE(g_pFont);
	SAFE_RELEASE(g_pd3dDevice);
}

float Get_Fps()
{
	static float fps = 0;
	static int frameCount = 0;
	static float currentTime = 0.0f;
	static float lastTime = 0.0f;

	// 调用一次就自增一次
	frameCount++;

	currentTime = timeGetTime() * 0.001f;		// 获取时间，转化为秒数
	if ((currentTime - lastTime) > 1.0f)
	{
		fps = (float)frameCount / (currentTime - lastTime);
		lastTime = timeGetTime() * 0.001f;
		frameCount = 0;  // 将本次的帧率清空，等待一秒以后再次调用
	}
	return fps;
}
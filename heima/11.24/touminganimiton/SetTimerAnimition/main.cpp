/*loop加透明贴图实现动画*/

#include <windows.h>
#include <iostream>

using namespace std;
// 各种函数声明
LRESULT CALLBACK WinProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL Game_Init(HWND hwnd);						// 资源的初始化
VOID Game_Paint(HWND hwnd);						// 开始绘图
BOOL Game_CleanUp(HWND hwnd);					// 清理资源
HDC g_hdc = NULL, g_mdc = NULL, g_bufdc = NULL;	// 三缓冲技术，主dc，兼容性dc，和内存dc
HBITMAP g_hSprite;						// 声明位图数用来存储各张人物图
HBITMAP g_back=NULL;
int g_inum = 0;									// 用来记录图号
DWORD g_timePre = 0, g_timeNow = 0;
HBITMAP bmp=NULL;
int g_ix = 800, g_iy = 0;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	// 新建窗口第一步  设计窗口
	WNDCLASSEX wndclass = {0};
	wndclass.cbClsExtra = 0;// 窗口类的附件内存，0即可
	wndclass.cbSize = sizeof(WNDCLASSEX);// 设置结构体字节大小
	wndclass.cbWndExtra = 0;// 窗口的附加内存
	wndclass.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hIcon = (HICON)LoadImage(NULL, L"icon.ico", IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_LOADFROMFILE);
	wndclass.hInstance = hInstance;// 指定包含窗口过程的程序实例句柄,这里指定main创建的即可
	wndclass.lpfnWndProc = WinProc;// 回调函数
	wndclass.lpszClassName = L"hello world";
	wndclass.lpszMenuName = NULL;
	wndclass.style = CS_HREDRAW | CS_VREDRAW;		// 设置窗口样式为可变
	
	// 创建窗口第二部 注册
	if (!RegisterClassEx(&wndclass))
	{
		MessageBoxA(0, "failed to create window", "msg", 0);
		return -1;
	}

	// 创建窗口第二部 创建			
	HWND hwnd = CreateWindow(L"hello world", L"动画窗口的制作", WS_OVERLAPPEDWINDOW, 0, 0, 800, 600, NULL, NULL, hInstance, NULL);

	if (!Game_Init(hwnd))				// 如果游戏初始化失败
	{
		MessageBox(hwnd, L"资源初始化失败", L"message", 0);
		return 0;
	}

	// 移动显示和更新
	MoveWindow(hwnd, 150, 300, 800, 600, true);
	ShowWindow(hwnd, nShowCmd);
	UpdateWindow(hwnd);

	// 开始消息循环，用于接收是不是退出之类的消息
	MSG msg = { 0 };
	while (msg.message != WM_QUIT)
	{
		//
		if (PeekMessage(&msg,0,0,0,PM_REMOVE))
		{
			TranslateMessage(&msg);			//解析消息
			DispatchMessage(&msg);			// 转发消息
		}
		else
		{
			
			g_timeNow = GetTickCount();
			if (g_timeNow - g_timePre >= 50)				// 10ms绘制一次
			{
				Game_Paint(hwnd);
			}
		}
		
	}

	// 窗口准备完成，注销窗口
	UnregisterClass(L"hello world", wndclass.hInstance);

	return 0;
}

LRESULT CALLBACK WinProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_TIMER:
		Game_Paint(hwnd);			// 收到定时器消息就重绘
		break;
	// 处理键盘消息
	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE)
		{
			DestroyWindow(hwnd);
		}
		else if (wParam == VK_RETURN)
		{
			MessageBox(0, L"VK_RETURN", L"VK_RETURN", 0);
		}
		break;
	case WM_DESTROY:
		Game_CleanUp(hwnd);
		PostQuitMessage(0);// 给系统发送消息，告诉有个线程要退出了
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	// 处理鼠标消息
	if (wParam & MK_LBUTTON)
	{
		MessageBox(0, L"MK_LBUTTON", L"MK_LBUTTON", 0);
	}
	else if (wParam & MK_RBUTTON)
	{
		MessageBox(0, L"MK_RBUTTON", L"MK_RBUTTON", 0);
	}
	RECT X;
	return 0;
}

BOOL Game_Init(HWND hwnd)
{
	g_hdc = GetDC(hwnd);						//获取Device Context
	
	g_mdc = CreateCompatibleDC(g_hdc);						// 创建兼容性DC，也就是背景内存
	g_bufdc = CreateCompatibleDC(g_hdc);		// 创建内存DC
	bmp = CreateCompatibleBitmap(g_hdc, 800, 600);		// 创建一个空的位图对象
	SelectObject(g_mdc, bmp);							// 把空的位图对象发放到g_mdc上
	g_hSprite = (HBITMAP)LoadImage(NULL, L"SSS.bmp", IMAGE_BITMAP, 326, 126, LR_LOADFROMFILE);	// 加载图
	g_back = (HBITMAP)LoadImage(NULL, L"timg.bmp", IMAGE_BITMAP, 800, 600, LR_LOADFROMFILE);	// 加载图

	g_ix = 800;
	g_iy = 326;							// 设置贴图的初始位置
	
	Game_Paint(hwnd);

	return TRUE;
}

VOID Game_Paint(HWND hwnd)
{
	if (g_inum >= 5)
	{
		g_inum = 0;
	}
	SelectObject(g_bufdc, g_back);			//在内存DC上选择背景图，一级缓冲
	BitBlt(g_mdc, 0, 0, 800, 600, g_bufdc, 0, 0, SRCCOPY);	// 二级缓冲

	SelectObject(g_bufdc, g_hSprite);

	if (!TransparentBlt(g_mdc, g_ix, g_iy, 65, 126, g_bufdc, g_inum * 65, 0, 65, 126, RGB(255, 255, 255)))	//透明贴图
	{
		MessageBox(0, L"设置失败", L"手动阀", 0);
	}

	BitBlt(g_hdc, 0, 0, 800, 600, g_mdc, 0, 0, SRCCOPY);			// 最后绘制在dc上
	g_timePre = GetTickCount();
	g_inum++;
	g_ix -= 8;
	if (g_ix <= 0)
	{
		g_ix = 800;
	}

}
BOOL Game_CleanUp(HWND hwnd)
{
	DeleteObject(g_hSprite);
	DeleteDC(g_mdc);
	DeleteDC(g_bufdc);
	ReleaseDC(hwnd, g_hdc);

	return TRUE;
}

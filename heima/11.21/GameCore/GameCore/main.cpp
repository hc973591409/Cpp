//---------------------------------【程序说明】--------------------------------
//程序名称： GameCore
//2018-11-21 Create by 胡超
//window窗口学习
//-----------------------------------------------------------------------------
#include <windows.h>
#define WINDOW_WIDTH 800				// 窗口宽度
#define WINDOW_HEIGHT 600				// 窗口宽度
#define WINDOW_TITLE L"[致我们永不熄灭的游戏开发梦想]"				// 窗口宽度

// 全局游戏声明，防止出现未声明的错误
LRESULT CALLBACK WindProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
// main 


int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	// 第一步 创建一个完整的窗口类
	WNDCLASSEX wndClass = { 0 };					// 定义窗口类
	wndClass.cbSize = sizeof(WNDCLASSEX);			// 设置结构体字节大小
	wndClass.style = CS_HREDRAW | CS_VREDRAW;		// 设置窗口样式为可变
	wndClass.lpfnWndProc = WindProc;				// 回调函数
	wndClass.cbClsExtra = 0;						// 窗口类的附件内存，0即可
	wndClass.cbWndExtra = 0;						// 窗口的附加内存
	wndClass.hInstance = hInstance;					// 指定包含窗口过程的程序实例句柄,这里指定main创建的即可
	wndClass.hIcon = (HICON)::LoadImage(NULL, L"icon.ico", IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_LOADFROMFILE);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);			// 系统默认光标
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);		// 设置会灰色画刷
	wndClass.lpszClassName = L"ForTheDreamOfDevelopment";				// 窗口类名
	wndClass.lpszMenuName = NULL;										// 菜单选项

	// 注册   需要注册了才能用该类创建窗口
	if (!RegisterClassEx(&wndClass))
		return -1;

	// 创建窗口
	HWND hwnd = CreateWindow(L"ForTheDreamOfDevelopment", WINDOW_TITLE, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
		WINDOW_WIDTH, WINDOW_HEIGHT, NULL, NULL, hInstance, NULL);

	// 移动显示和更新
	MoveWindow(hwnd, 250, 80, WINDOW_WIDTH, WINDOW_HEIGHT, true);    // 调整窗口显示位置
	ShowWindow(hwnd, nShowCmd);         // 显示窗口
	UpdateWindow(hwnd);

	// 消息循环过程
	MSG msg = { 0 };
	while (msg.message != WM_QUIT)	// 只要没有收到退出消息
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);			// 把虚拟键转成消息，翻译
			DispatchMessage(&msg);			// 分发任务
		} 
		else
		{
		}
	}
	// 窗口准备完成，注销窗口
	UnregisterClass(L"ForTheDreamOfDevelopment", wndClass.hInstance);

	return 0;
}

LRESULT CALLBACK WindProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_PAINT://客户端重绘
		ValidateRect(hwnd, NULL);
		break;
	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE)
		{
			DestroyWindow(hwnd);
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);			// 给系统发送消息，告诉有个线程要退出了
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0; // 正常退出
}

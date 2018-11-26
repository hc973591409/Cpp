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
BOOL Game_Init(HWND hwnd);						// 资源的初始化
VOID Game_Paint(HWND hwnd);						// 开始绘图
BOOL Game_CleanUp(HWND hwnd);					// 清理资源

// main 

HDC g_hdc = NULL;								// 客户区Device context
HDC g_mdc = NULL;								// 声明位图的兼容性设备环境
HBITMAP g_hBitmap = NULL;						// 声明全局的位图变量

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
	
	if (!Game_Init(hwnd))				// 如果游戏初始化失败
	{
		MessageBox(hwnd, L"资源初始化失败", L"message", 0);
		return 0;
	}
	PlaySound(L"4250.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
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

BOOL Game_Init(HWND hwnd)
{
	g_hdc = GetDC(hwnd);						//获取Device Context

	// 加载位图，获取位图对象
	g_hBitmap = (HBITMAP)LoadImage(NULL, L"timg.bmp",IMAGE_BITMAP,800,600,LR_LOADFROMFILE);

	// 建立兼容性Device Context
	g_mdc = CreateCompatibleDC(g_hdc);				// 从全局DC从获取兼容新DC的内存

	Game_Paint(hwnd);
	ReleaseDC(hwnd, g_hdc);
	return TRUE;
}

LRESULT CALLBACK WindProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT paintstruct;						// 定义一个paintstruct 结构体来记录绘制信息
	switch (message)
	{
	case WM_PAINT://客户端重绘
		g_hdc = BeginPaint(hwnd, &paintstruct);		// 指定窗口进行绘图工作准备，保存绘图信息
		Game_Paint(hwnd);
		EndPaint(hwnd, NULL);						// 结束绘图过程
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

VOID Game_Paint(HWND hwnd)						// 开始绘图
{
	// 选择位图对象
	SelectObject(g_mdc, g_hBitmap);

	// 贴图
	BitBlt(g_hdc, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, g_mdc, 0, 0, SRCCOPY);		// 设置窗口大小和贴图模式即可

	// 创建字体对象
	HFONT hFont = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, GB2312_CHARSET, 0, 0, 0, 0, TEXT("Consolas"));
	SelectObject(g_hdc, hFont);			// 选择字体对象
	SetBkMode(g_hdc, TRANSPARENT);
	wchar_t text1[] = L"我们的所有梦想终将成真，只要我们有勇气去追梦";
	wchar_t text2[] = L"all our dream can be true, if we have courage to pursue them";
	wchar_t text3[] = L"----------disney";
	// 输出第一段文字
	SetTextColor(g_hdc, RGB(50, 255, 50));
	TextOut(g_hdc, 30, 150, text1, wcslen(text1));

	// 输出第二段文字
	SetTextColor(g_hdc, RGB(50, 50, 255));
	TextOut(g_hdc, 30, 200, text2, wcslen(text2));

	// 输出第三段文字
	SetTextColor(g_hdc, RGB(255, 150, 50));
	TextOut(g_hdc, 500, 250, text3, wcslen(text3));

	// 删除字体对象
	DeleteObject(hFont);
}
BOOL Game_CleanUp(HWND hwnd)					// 清理资源
{
	DeleteObject(g_hBitmap);
	DeleteObject(g_mdc);
	return TRUE;
}

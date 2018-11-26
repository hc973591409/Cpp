//---------------------------------【程序说明】--------------------------------
//程序名称： GameCore
//2018-11-21 Create by 胡超
//window窗口学习
//-----------------------------------------------------------------------------
#include <windows.h>
#include <ctime>

#pragma comment(lib,"winmm.lib")

#define WINDOW_WIDTH 800				// 窗口宽度
#define WINDOW_HEIGHT 600				// 窗口宽度
#define WINDOW_TITLE L"[致我们永不熄灭的游戏开发梦想]"				// 窗口宽度


HDC g_hdc = NULL;			// 全局Device Context 句柄
HPEN g_hPen[7] = { 0 };		// 全局画刷
HBRUSH g_hBrush[7] = { 0 };
int g_iPenStyle[7] = { PS_SOLID, PS_DASH, PS_DOT, PS_DASHDOT, PS_DASHDOTDOT,PS_NULL,PS_INSIDEFRAME };
int g_bBrushStyle[6] = { HS_VERTICAL, HS_HORIZONTAL, HS_FDIAGONAL, HS_BDIAGONAL, HS_CROSS, HS_DIAGCROSS };


// 全局游戏声明，防止出现未声明的错误
LRESULT CALLBACK WindProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL Game_Init(HWND hwnd);						// 资源的初始化
VOID Game_Paint(HWND hwnd);						// 开始绘图
BOOL Game_CleanUp(HWND hwnd);					// 清理资源




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
	wndClass.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);		// 设置会灰色画刷
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

	// 移动显示和更新
	MoveWindow(hwnd, 250, 80, WINDOW_WIDTH, WINDOW_HEIGHT, true);    // 调整窗口显示位置
	ShowWindow(hwnd, nShowCmd);         // 显示窗口
	UpdateWindow(hwnd);

	PlaySound(L"4250.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
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

BOOL Game_Init(HWND hwnd)						// 资源的初始化
{
	g_hdc = GetDC(hwnd);						//获取Device Context
	srand((unsigned int)time(NULL));			// 设立随机数种子
	for (int i = 0; i <= 6;i++)
	{
		g_hPen[i] = CreatePen(g_iPenStyle[i], 1, RGB(rand() % 255, rand() % 256, rand() % 256));
		if (i%6 == 0)
		{
			g_hBrush[i] = CreateSolidBrush(RGB(rand() % 255, rand() % 256, rand() % 256));
		}
		else
		{
			g_hBrush[i] = CreateHatchBrush(g_bBrushStyle[i], RGB(rand() % 255, rand() % 256, rand() % 256));
		}
	}
	Game_Paint(hwnd);
	ReleaseDC(hwnd,g_hdc);
	return TRUE;
}
VOID Game_Paint(HWND hwnd)						// 开始绘图
{
	// 定义Y
	int y = 0;
	for (int i = 0; i <= 6;i++)
	{
		y = (i + 1) * 70;
		SelectObject(g_hdc, g_hPen[i]);         // 选择对应的画笔
		MoveToEx(g_hdc, 30, y, NULL);
		LineTo(g_hdc, 100, y);
	}
	int x1 = 120;
	int x2 = 190;
	for (int i = 0; i < 7; i++)
	{
		SelectObject(g_hdc, g_hBrush[i]);		// 选择对应的画刷
		Rectangle(g_hdc, x1, 70, x2, y);
		x2 += 90;
		x1 += 90;
	}

	// 输出文字。默认背景 为white brush
	wchar_t text[] = L"要有最朴素的生活，与最遥远的梦想，及时明天寒冬，最终马亡";
	SetTextColor(g_hdc, RGB(255, 0, 0));				// 设置文字颜色
	SetBkMode(g_hdc, TRANSPARENT);						// 设置透明背景  只有调用一次，后续所有文字设置都是透明的
	TextOut(g_hdc, 30, 20, text, wcslen(text));			// 设置显示文字
	
	
}
BOOL Game_CleanUp(HWND hwnd)					// 清理资源
{
	for (int i = 0; i < 7; i++)
	{
		DeleteObject(g_hPen[i]);
		DeleteObject(g_hBrush[i]);			// 删除画笔对象和画刷对象
	}
	return TRUE;
}


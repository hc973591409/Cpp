#include "GameCore.h"

LRESULT CALLBACK WinProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);	// 回调函数

GameCore::GameCore(HINSTANCE hInstance)
{
	this->hInstance = hInstance;
	// 设计窗口类
	this->wndclass.cbSize = sizeof(WNDCLASSEX);		// 窗口的内存大小
	this->wndclass.cbClsExtra = 0;					// 窗口类的大小
	this->wndclass.cbWndExtra = 0;					// 窗口的额外内存
	this->wndclass.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);	// 背景
	this->wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);		// 系统默认画刷
	this->wndclass.hIcon = (HICON)::LoadImage(NULL, L"icon.ico", IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_LOADFROMFILE);
	this->wndclass.hInstance = hInstance;
	this->wndclass.lpfnWndProc = WinProc;
	this->wndclass.lpszClassName = L"ForTheDreamOfDevelopment";				// 窗口类名
	this->wndclass.lpszMenuName = NULL;

	// 注册窗口类
	if (!RegisterClassEx(&this->wndclass))
	{
		MessageBox(0, L"注册失败", L"msg", 0);
		return;
	}	
}

void GameCore::UpdateWind()
{
	this->hwnd = CreateWindow(L"ForTheDreamOfDevelopment", WINDOW_TITLE, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
		WINDOW_WIDTH, WINDOW_HEIGHT, NULL, NULL, hInstance, NULL);
	// 移动显示和更新
	MoveWindow(hwnd, 250, 80, WINDOW_WIDTH, WINDOW_HEIGHT, true);    // 调整窗口显示位置
	ShowWindow(hwnd, NULL);         // 显示窗口
	UpdateWindow(hwnd);
}

GameCore::~GameCore()
{
}


LRESULT CALLBACK WinProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
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

#include "GameCore.h"

LRESULT CALLBACK WinProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);	// �ص�����

GameCore::GameCore(HINSTANCE hInstance)
{
	this->hInstance = hInstance;
	// ��ƴ�����
	this->wndclass.cbSize = sizeof(WNDCLASSEX);		// ���ڵ��ڴ��С
	this->wndclass.cbClsExtra = 0;					// ������Ĵ�С
	this->wndclass.cbWndExtra = 0;					// ���ڵĶ����ڴ�
	this->wndclass.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);	// ����
	this->wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);		// ϵͳĬ�ϻ�ˢ
	this->wndclass.hIcon = (HICON)::LoadImage(NULL, L"icon.ico", IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_LOADFROMFILE);
	this->wndclass.hInstance = hInstance;
	this->wndclass.lpfnWndProc = WinProc;
	this->wndclass.lpszClassName = L"ForTheDreamOfDevelopment";				// ��������
	this->wndclass.lpszMenuName = NULL;

	// ע�ᴰ����
	if (!RegisterClassEx(&this->wndclass))
	{
		MessageBox(0, L"ע��ʧ��", L"msg", 0);
		return;
	}	
}

void GameCore::UpdateWind()
{
	this->hwnd = CreateWindow(L"ForTheDreamOfDevelopment", WINDOW_TITLE, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
		WINDOW_WIDTH, WINDOW_HEIGHT, NULL, NULL, hInstance, NULL);
	// �ƶ���ʾ�͸���
	MoveWindow(hwnd, 250, 80, WINDOW_WIDTH, WINDOW_HEIGHT, true);    // ����������ʾλ��
	ShowWindow(hwnd, NULL);         // ��ʾ����
	UpdateWindow(hwnd);
}

GameCore::~GameCore()
{
}


LRESULT CALLBACK WinProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_PAINT://�ͻ����ػ�
		ValidateRect(hwnd, NULL);
		break;
	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE)
		{
			DestroyWindow(hwnd);
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);			// ��ϵͳ������Ϣ�������и��߳�Ҫ�˳���
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0; // �����˳�
}

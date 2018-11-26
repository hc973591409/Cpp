/*setTimerʵ�ֶ���*/

#include <windows.h>
#include <iostream>

using namespace std;
// ���ֺ�������
LRESULT CALLBACK WinProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL Game_Init(HWND hwnd);						// ��Դ�ĳ�ʼ��
VOID Game_Paint(HWND hwnd);						// ��ʼ��ͼ
BOOL Game_CleanUp(HWND hwnd);					// ������Դ
HDC g_hdc = NULL, g_mdc = NULL;
HBITMAP g_hSprite[12];							// ����λͼ�������洢��������ͼ
int g_inum = 0;									// ������¼ͼ��

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	// �½����ڵ�һ��  ��ƴ���
	WNDCLASSEX wndclass = {0};
	wndclass.cbClsExtra = 0;// ������ĸ����ڴ棬0����
	wndclass.cbSize = sizeof(WNDCLASSEX);// ���ýṹ���ֽڴ�С
	wndclass.cbWndExtra = 0;// ���ڵĸ����ڴ�
	wndclass.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hIcon = (HICON)LoadImage(NULL, L"icon.ico", IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_LOADFROMFILE);
	wndclass.hInstance = hInstance;// ָ���������ڹ��̵ĳ���ʵ�����,����ָ��main�����ļ���
	wndclass.lpfnWndProc = WinProc;// �ص�����
	wndclass.lpszClassName = L"hello world";
	wndclass.lpszMenuName = NULL;
	wndclass.style = CS_HREDRAW | CS_VREDRAW;		// ���ô�����ʽΪ�ɱ�
	
	// �������ڵڶ��� ע��
	if (!RegisterClassEx(&wndclass))
	{
		MessageBoxA(0, "failed to create window", "msg", 0);
		return -1;
	}

	// �������ڵڶ��� ����			
	HWND hwnd = CreateWindow(L"hello world", L"�������ڵ�����", WS_OVERLAPPEDWINDOW, 0, 0, 800, 600, NULL, NULL, hInstance, NULL);

	if (!Game_Init(hwnd))				// �����Ϸ��ʼ��ʧ��
	{
		MessageBox(hwnd, L"��Դ��ʼ��ʧ��", L"message", 0);
		return 0;
	}

	// �ƶ���ʾ�͸���
	MoveWindow(hwnd, 150, 300, 800, 600, true);
	ShowWindow(hwnd, nShowCmd);
	UpdateWindow(hwnd);

	// ��ʼ��Ϣѭ�������ڽ����ǲ����˳�֮�����Ϣ
	MSG msg = { 0 };
	while (msg.message != WM_QUIT)
	{
		//
		if (PeekMessage(&msg,0,0,0,PM_REMOVE))
		{
			TranslateMessage(&msg);			//������Ϣ
			DispatchMessage(&msg);			// ת����Ϣ
		}
		
	}

	// ����׼����ɣ�ע������
	UnregisterClass(L"hello world", wndclass.hInstance);

	return 0;
}

LRESULT CALLBACK WinProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_TIMER:
		Game_Paint(hwnd);			// �յ���ʱ����Ϣ���ػ�
		break;
	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE)
		{
			DestroyWindow(hwnd);
		}
		break;
	case WM_DESTROY:
		Game_CleanUp(hwnd);
		PostQuitMessage(0);// ��ϵͳ������Ϣ�������и��߳�Ҫ�˳���
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}

BOOL Game_Init(HWND hwnd)
{
	g_hdc = GetDC(hwnd);						//��ȡDevice Context
	
	wchar_t filename[20];
	for (int i = 0; i < 4;i++)
	{
		memset(filename, 0, sizeof(filename));
		swprintf_s(filename, L"%d.bmp", i);
		g_hSprite[i] = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 800, 600, LR_LOADFROMFILE);
	}
	g_mdc = CreateCompatibleDC(g_hdc);						// ����������DC��Ҳ���Ǳ����ڴ�

	g_inum = 0;												// ���ó�ʼ��ͼ��
	SetTimer(hwnd, 1, 50, NULL);
	return TRUE;
}

VOID Game_Paint(HWND hwnd)
{
	if (g_inum >= 4)
	{
		g_inum = 0;
	}
	SelectObject(g_mdc, g_hSprite[g_inum]);				// ����ͼ��ѡ���Ӧ��λͼ
	BitBlt(g_hdc, 0, 0, 800, 600, g_mdc, 0, 0, SRCCOPY);	// ��ʾͼƬ
	g_inum++;
}
BOOL Game_CleanUp(HWND hwnd)
{
	KillTimer(hwnd, 1);
	for (int i = 0; i < 4;i++)
	{
		DeleteObject(g_hSprite[i]);
	}
	DeleteDC(g_mdc);
	ReleaseDC(hwnd, g_hdc);
	return TRUE;
}

/*loop��͸����ͼʵ�ֶ���*/

#include <windows.h>
#include <iostream>

using namespace std;
// ���ֺ�������
LRESULT CALLBACK WinProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL Game_Init(HWND hwnd);						// ��Դ�ĳ�ʼ��
VOID Game_Paint(HWND hwnd);						// ��ʼ��ͼ
BOOL Game_CleanUp(HWND hwnd);					// ������Դ
HDC g_hdc = NULL, g_mdc = NULL, g_bufdc = NULL;	// �����弼������dc��������dc�����ڴ�dc
HBITMAP g_hSprite;						// ����λͼ�������洢��������ͼ
HBITMAP g_back=NULL;
int g_inum = 0;									// ������¼ͼ��
DWORD g_timePre = 0, g_timeNow = 0;
HBITMAP bmp=NULL;
int g_ix = 800, g_iy = 0;

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
		else
		{
			
			g_timeNow = GetTickCount();
			if (g_timeNow - g_timePre >= 50)				// 10ms����һ��
			{
				Game_Paint(hwnd);
			}
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
	// ���������Ϣ
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
		PostQuitMessage(0);// ��ϵͳ������Ϣ�������и��߳�Ҫ�˳���
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	// ���������Ϣ
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
	g_hdc = GetDC(hwnd);						//��ȡDevice Context
	
	g_mdc = CreateCompatibleDC(g_hdc);						// ����������DC��Ҳ���Ǳ����ڴ�
	g_bufdc = CreateCompatibleDC(g_hdc);		// �����ڴ�DC
	bmp = CreateCompatibleBitmap(g_hdc, 800, 600);		// ����һ���յ�λͼ����
	SelectObject(g_mdc, bmp);							// �ѿյ�λͼ���󷢷ŵ�g_mdc��
	g_hSprite = (HBITMAP)LoadImage(NULL, L"SSS.bmp", IMAGE_BITMAP, 326, 126, LR_LOADFROMFILE);	// ����ͼ
	g_back = (HBITMAP)LoadImage(NULL, L"timg.bmp", IMAGE_BITMAP, 800, 600, LR_LOADFROMFILE);	// ����ͼ

	g_ix = 800;
	g_iy = 326;							// ������ͼ�ĳ�ʼλ��
	
	Game_Paint(hwnd);

	return TRUE;
}

VOID Game_Paint(HWND hwnd)
{
	if (g_inum >= 5)
	{
		g_inum = 0;
	}
	SelectObject(g_bufdc, g_back);			//���ڴ�DC��ѡ�񱳾�ͼ��һ������
	BitBlt(g_mdc, 0, 0, 800, 600, g_bufdc, 0, 0, SRCCOPY);	// ��������

	SelectObject(g_bufdc, g_hSprite);

	if (!TransparentBlt(g_mdc, g_ix, g_iy, 65, 126, g_bufdc, g_inum * 65, 0, 65, 126, RGB(255, 255, 255)))	//͸����ͼ
	{
		MessageBox(0, L"����ʧ��", L"�ֶ���", 0);
	}

	BitBlt(g_hdc, 0, 0, 800, 600, g_mdc, 0, 0, SRCCOPY);			// ��������dc��
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

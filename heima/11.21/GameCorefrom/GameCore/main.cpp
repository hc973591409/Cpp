//---------------------------------������˵����--------------------------------
//�������ƣ� GameCore
//2018-11-21 Create by ����
//window����ѧϰ
//-----------------------------------------------------------------------------
#include <windows.h>
#include <ctime>

#pragma comment(lib,"winmm.lib")

#define WINDOW_WIDTH 800				// ���ڿ��
#define WINDOW_HEIGHT 600				// ���ڿ��
#define WINDOW_TITLE L"[����������Ϩ�����Ϸ��������]"				// ���ڿ��


HDC g_hdc = NULL;			// ȫ��Device Context ���
HPEN g_hPen[7] = { 0 };		// ȫ�ֻ�ˢ
HBRUSH g_hBrush[7] = { 0 };
int g_iPenStyle[7] = { PS_SOLID, PS_DASH, PS_DOT, PS_DASHDOT, PS_DASHDOTDOT,PS_NULL,PS_INSIDEFRAME };
int g_bBrushStyle[6] = { HS_VERTICAL, HS_HORIZONTAL, HS_FDIAGONAL, HS_BDIAGONAL, HS_CROSS, HS_DIAGCROSS };


// ȫ����Ϸ��������ֹ����δ�����Ĵ���
LRESULT CALLBACK WindProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL Game_Init(HWND hwnd);						// ��Դ�ĳ�ʼ��
VOID Game_Paint(HWND hwnd);						// ��ʼ��ͼ
BOOL Game_CleanUp(HWND hwnd);					// ������Դ




int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	// ��һ�� ����һ�������Ĵ�����
	WNDCLASSEX wndClass = { 0 };					// ���崰����
	wndClass.cbSize = sizeof(WNDCLASSEX);			// ���ýṹ���ֽڴ�С
	wndClass.style = CS_HREDRAW | CS_VREDRAW;		// ���ô�����ʽΪ�ɱ�
	wndClass.lpfnWndProc = WindProc;				// �ص�����
	wndClass.cbClsExtra = 0;						// ������ĸ����ڴ棬0����
	wndClass.cbWndExtra = 0;						// ���ڵĸ����ڴ�
	wndClass.hInstance = hInstance;					// ָ���������ڹ��̵ĳ���ʵ�����,����ָ��main�����ļ���
	wndClass.hIcon = (HICON)::LoadImage(NULL, L"icon.ico", IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_LOADFROMFILE);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);			// ϵͳĬ�Ϲ��
	wndClass.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);		// ���û��ɫ��ˢ
	wndClass.lpszClassName = L"ForTheDreamOfDevelopment";				// ��������
	wndClass.lpszMenuName = NULL;										// �˵�ѡ��

	// ע��   ��Ҫע���˲����ø��ഴ������
	if (!RegisterClassEx(&wndClass))
		return -1;



	// ��������
	HWND hwnd = CreateWindow(L"ForTheDreamOfDevelopment", WINDOW_TITLE, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
		WINDOW_WIDTH, WINDOW_HEIGHT, NULL, NULL, hInstance, NULL);

	if (!Game_Init(hwnd))				// �����Ϸ��ʼ��ʧ��
	{
		MessageBox(hwnd, L"��Դ��ʼ��ʧ��", L"message", 0);
		return 0;
	}

	// �ƶ���ʾ�͸���
	MoveWindow(hwnd, 250, 80, WINDOW_WIDTH, WINDOW_HEIGHT, true);    // ����������ʾλ��
	ShowWindow(hwnd, nShowCmd);         // ��ʾ����
	UpdateWindow(hwnd);

	PlaySound(L"4250.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	// ��Ϣѭ������
	MSG msg = { 0 };
	while (msg.message != WM_QUIT)	// ֻҪû���յ��˳���Ϣ
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);			// �������ת����Ϣ������
			DispatchMessage(&msg);			// �ַ�����
		} 
		else
		{
		}
	}
	// ����׼����ɣ�ע������
	UnregisterClass(L"ForTheDreamOfDevelopment", wndClass.hInstance);

	return 0;
}

LRESULT CALLBACK WindProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT paintstruct;						// ����һ��paintstruct �ṹ������¼������Ϣ
	switch (message)
	{
	case WM_PAINT://�ͻ����ػ�
		g_hdc = BeginPaint(hwnd, &paintstruct);		// ָ�����ڽ��л�ͼ����׼���������ͼ��Ϣ
		Game_Paint(hwnd);
		EndPaint(hwnd, NULL);						// ������ͼ����
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

BOOL Game_Init(HWND hwnd)						// ��Դ�ĳ�ʼ��
{
	g_hdc = GetDC(hwnd);						//��ȡDevice Context
	srand((unsigned int)time(NULL));			// �������������
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
VOID Game_Paint(HWND hwnd)						// ��ʼ��ͼ
{
	// ����Y
	int y = 0;
	for (int i = 0; i <= 6;i++)
	{
		y = (i + 1) * 70;
		SelectObject(g_hdc, g_hPen[i]);         // ѡ���Ӧ�Ļ���
		MoveToEx(g_hdc, 30, y, NULL);
		LineTo(g_hdc, 100, y);
	}
	int x1 = 120;
	int x2 = 190;
	for (int i = 0; i < 7; i++)
	{
		SelectObject(g_hdc, g_hBrush[i]);		// ѡ���Ӧ�Ļ�ˢ
		Rectangle(g_hdc, x1, 70, x2, y);
		x2 += 90;
		x1 += 90;
	}

	// ������֡�Ĭ�ϱ��� Ϊwhite brush
	wchar_t text[] = L"Ҫ�������ص��������ңԶ�����룬��ʱ���캮������������";
	SetTextColor(g_hdc, RGB(255, 0, 0));				// ����������ɫ
	SetBkMode(g_hdc, TRANSPARENT);						// ����͸������  ֻ�е���һ�Σ����������������ö���͸����
	TextOut(g_hdc, 30, 20, text, wcslen(text));			// ������ʾ����
	
	
}
BOOL Game_CleanUp(HWND hwnd)					// ������Դ
{
	for (int i = 0; i < 7; i++)
	{
		DeleteObject(g_hPen[i]);
		DeleteObject(g_hBrush[i]);			// ɾ�����ʶ���ͻ�ˢ����
	}
	return TRUE;
}


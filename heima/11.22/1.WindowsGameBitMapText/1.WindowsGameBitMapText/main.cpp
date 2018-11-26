//---------------------------------������˵����--------------------------------
//�������ƣ� GameCore
//2018-11-21 Create by ����
//window����ѧϰ
//-----------------------------------------------------------------------------
#include <windows.h>
#define WINDOW_WIDTH 800				// ���ڿ��
#define WINDOW_HEIGHT 600				// ���ڿ��
#define WINDOW_TITLE L"[����������Ϩ�����Ϸ��������]"				// ���ڿ��

// ȫ����Ϸ��������ֹ����δ�����Ĵ���
LRESULT CALLBACK WindProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL Game_Init(HWND hwnd);						// ��Դ�ĳ�ʼ��
VOID Game_Paint(HWND hwnd);						// ��ʼ��ͼ
BOOL Game_CleanUp(HWND hwnd);					// ������Դ

// main 

HDC g_hdc = NULL;								// �ͻ���Device context
HDC g_mdc = NULL;								// ����λͼ�ļ������豸����
HBITMAP g_hBitmap = NULL;						// ����ȫ�ֵ�λͼ����

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
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);		// ���û��ɫ��ˢ
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
	PlaySound(L"4250.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	// �ƶ���ʾ�͸���
	MoveWindow(hwnd, 250, 80, WINDOW_WIDTH, WINDOW_HEIGHT, true);    // ����������ʾλ��
	ShowWindow(hwnd, nShowCmd);         // ��ʾ����
	UpdateWindow(hwnd);

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

BOOL Game_Init(HWND hwnd)
{
	g_hdc = GetDC(hwnd);						//��ȡDevice Context

	// ����λͼ����ȡλͼ����
	g_hBitmap = (HBITMAP)LoadImage(NULL, L"timg.bmp",IMAGE_BITMAP,800,600,LR_LOADFROMFILE);

	// ����������Device Context
	g_mdc = CreateCompatibleDC(g_hdc);				// ��ȫ��DC�ӻ�ȡ������DC���ڴ�

	Game_Paint(hwnd);
	ReleaseDC(hwnd, g_hdc);
	return TRUE;
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

VOID Game_Paint(HWND hwnd)						// ��ʼ��ͼ
{
	// ѡ��λͼ����
	SelectObject(g_mdc, g_hBitmap);

	// ��ͼ
	BitBlt(g_hdc, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, g_mdc, 0, 0, SRCCOPY);		// ���ô��ڴ�С����ͼģʽ����

	// �����������
	HFONT hFont = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, GB2312_CHARSET, 0, 0, 0, 0, TEXT("Consolas"));
	SelectObject(g_hdc, hFont);			// ѡ���������
	SetBkMode(g_hdc, TRANSPARENT);
	wchar_t text1[] = L"���ǵ����������ս����棬ֻҪ����������ȥ׷��";
	wchar_t text2[] = L"all our dream can be true, if we have courage to pursue them";
	wchar_t text3[] = L"----------disney";
	// �����һ������
	SetTextColor(g_hdc, RGB(50, 255, 50));
	TextOut(g_hdc, 30, 150, text1, wcslen(text1));

	// ����ڶ�������
	SetTextColor(g_hdc, RGB(50, 50, 255));
	TextOut(g_hdc, 30, 200, text2, wcslen(text2));

	// �������������
	SetTextColor(g_hdc, RGB(255, 150, 50));
	TextOut(g_hdc, 500, 250, text3, wcslen(text3));

	// ɾ���������
	DeleteObject(hFont);
}
BOOL Game_CleanUp(HWND hwnd)					// ������Դ
{
	DeleteObject(g_hBitmap);
	DeleteObject(g_mdc);
	return TRUE;
}

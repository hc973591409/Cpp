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
// main 


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

LRESULT CALLBACK WindProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
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

#include <windows.h>

//#pragma comment(lib, "winmm.lib")	//PlaySound		������⣬���ӿ�
// Ҳ�������������м�����ļ�

int WINAPI WinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd)
{
	PlaySound(L"4250.wav", NULL, SND_FILENAME | SND_ASYNC);  //�첽�Ĵ��ļ��ж�ȡ������
	MessageBox(NULL, L"����Ӫ��", L"yixue", 1);
	//PlaySound();
	/*BOOL
	WINAPI
	PlaySoundW(
	_In_opt_ LPCWSTR pszSound,			ָ����Ҫ���ŵ������ļ�
	_In_opt_ HMODULE hmod,				���������ļ��Ŀ�ִ�о��
	_In_ DWORD fdwSound					���Ʋ��ŵ�һ����־ �кܶ���£���|����
	);*/
	
	// 1. ����������
	WNDCLASSEX wndClass{ 0 };				// ʵ����һ�������࣬ ����֮���ʼ��
	wndClass.cbSize = sizeof(WNDCLASSEXA);	// ��ʼ���ṹ��Ĵ�С
	wndClass.style = CS_HREDRAW | CS_VREDRAW;   //���ô������ͣ������MSDN
	// ��ȫ�ֵĵ�loadimage�б��ؼ����Զ���iconͼ��
	//_T�����ݱ����ַ������Զ��л��ַ�
	wndClass.hIcon = (HICON)::LoadImage(NULL, _T("icon.ico"), IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_LOADFROMFILE);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);			// Ĭ�ϼ�ͷ���
	wndClass.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);    // ����Ϊ��ɫ��ˢ
	wndClass.lpszMenuName = NULL;     // ��������ʶ��˵Ҫ��Ҫ�����˵�������Ҫ��NULL����
	wndClass.lpszClassName = _T("ForTheDreamOfGameDevelop");		// ���ô�������
	// WINDOWS���ڵ������࣬
	typedef struct tagWNDCLASSEXA {
		UINT        cbSize;				// ��ʾ�ṹ���С
		UINT        style;			// 
		WNDPROC     lpfnWndProc;    // ��һ������ָ�룬ָ�򴰿ڹ��̺������ǻص�����������ĳ�����Ժ����
		int         cbClsExtra;		// ������ĸ����ڴ棬һ������Ϊ0����
		int         cbWndExtra;		// ���ڵĸ����ڴ棬һ������Ϊ0����
		HINSTANCE   hInstance;		// ��ʾ��������ʵ�����̵ĳ���ʵ�����ھ���������main�������ģ���main���ľ������
		HICON       hIcon;			// ͼ����
		HCURSOR     hCursor;		// �����
		HBRUSH      hbrBackground;	// 
		LPCSTR      lpszMenuName;
		LPCSTR      lpszClassName;
		/* Win 4.0 */
		HICON       hIconSm;		// ������������Сͼ��
	} WNDCLASSEXA, *PWNDCLASSEXA, NEAR *NPWNDCLASSEXA, FAR *LPWNDCLASSEXA;


	// 2. �������ע��	����֮ǰ��ƵĴ�����ָ��
	RegisterClassEx(&wndClass);

	//3. ����
	CreateWindow();
	HWND
		WINAPI
		CreateWindowExW(
		_In_ DWORD dwExStyle,			
		_In_opt_ LPCWSTR lpClassName,	// ������
		_In_opt_ LPCWSTR lpWindowName,  // ��������		ֲ���ս��ʬ
		_In_ DWORD dwStyle,				// ������ʽ
		_In_ int X,					// ����ˮƽλ��
		_In_ int Y,
		_In_ int nWidth,
		_In_ int nHeight,
		_In_opt_ HWND hWndParent,		// �����ھ��
		_In_opt_ HMENU hMenu,			// ��Դ�͵����
		_In_opt_ HINSTANCE hInstance,	
		_In_opt_ LPVOID lpParam);

	// ���ڵ���ʾ�͸���
	// 1.�ı䴰�ڵĴ�С��λ��
	MoveWindow(HWND, 200, 500, 800, 600, true);
	// 2.��ʾ����
	ShowWindow(HWND, nShowCmd);
//	nShowCmd ��ѡ������SW_HIDE...
	// ���´���
	UpdateWindow(hwnd);

	WindowProc();

	return 0;
}
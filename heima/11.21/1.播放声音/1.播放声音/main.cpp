#include <windows.h>

//#pragma comment(lib, "winmm.lib")	//PlaySound		在这个库，链接库
// 也可以在连接器中加入库文件

int WINAPI WinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd)
{
	PlaySound(L"4250.wav", NULL, SND_FILENAME | SND_ASYNC);  //异步的从文件中读取打开音响
	MessageBox(NULL, L"播放营销", L"yixue", 1);
	//PlaySound();
	/*BOOL
	WINAPI
	PlaySoundW(
	_In_opt_ LPCWSTR pszSound,			指定了要播放的声音文件
	_In_opt_ HMODULE hmod,				播放声音文件的可执行句柄
	_In_ DWORD fdwSound					控制播放的一个标志 有很多标致，用|链接
	);*/
	
	// 1. 窗口类的设计
	WNDCLASSEX wndClass{ 0 };				// 实例化一个窗口类， 用于之后初始化
	wndClass.cbSize = sizeof(WNDCLASSEXA);	// 初始化结构体的大小
	wndClass.style = CS_HREDRAW | CS_VREDRAW;   //设置窗口类型，具体查MSDN
	// 从全局的的loadimage中本地加载自定义icon图标
	//_T宏会根据本地字符环境自动切换字符
	wndClass.hIcon = (HICON)::LoadImage(NULL, _T("icon.ico"), IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_LOADFROMFILE);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);			// 默认箭头光标
	wndClass.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);    // 设置为灰色画刷
	wndClass.lpszMenuName = NULL;     // 参数的意识是说要不要下拉菜单，不需要就NULL即可
	wndClass.lpszClassName = _T("ForTheDreamOfGameDevelop");		// 设置窗口雷鸣
	// WINDOWS窗口的特征类，
	typedef struct tagWNDCLASSEXA {
		UINT        cbSize;				// 表示结构体大小
		UINT        style;			// 
		WNDPROC     lpfnWndProc;    // 是一个函数指针，指向窗口过程函数，是回调函数，发生某件事以后调用
		int         cbClsExtra;		// 窗口类的附加内存，一般设置为0即可
		int         cbWndExtra;		// 窗口的附加内存，一般设置为0即可
		HINSTANCE   hInstance;		// 表示包含窗口实例过程的程序实例窗口句柄，如果是main弹出来的，用main、的句柄即可
		HICON       hIcon;			// 图标句柄
		HCURSOR     hCursor;		// 光标句柄
		HBRUSH      hbrBackground;	// 
		LPCSTR      lpszMenuName;
		LPCSTR      lpszClassName;
		/* Win 4.0 */
		HICON       hIconSm;		// 就是任务栏的小图标
	} WNDCLASSEXA, *PWNDCLASSEXA, NEAR *NPWNDCLASSEXA, FAR *LPWNDCLASSEXA;


	// 2. 窗口类的注册	传入之前设计的窗口类指针
	RegisterClassEx(&wndClass);

	//3. 创建
	CreateWindow();
	HWND
		WINAPI
		CreateWindowExW(
		_In_ DWORD dwExStyle,			
		_In_opt_ LPCWSTR lpClassName,	// 类名称
		_In_opt_ LPCWSTR lpWindowName,  // 窗口名称		植物大战僵尸
		_In_ DWORD dwStyle,				// 窗口样式
		_In_ int X,					// 窗口水平位置
		_In_ int Y,
		_In_ int nWidth,
		_In_ int nHeight,
		_In_opt_ HWND hWndParent,		// 父窗口句柄
		_In_opt_ HMENU hMenu,			// 资源餐单句柄
		_In_opt_ HINSTANCE hInstance,	
		_In_opt_ LPVOID lpParam);

	// 窗口的显示和更新
	// 1.改变窗口的大小和位置
	MoveWindow(HWND, 200, 500, 800, 600, true);
	// 2.显示窗口
	ShowWindow(HWND, nShowCmd);
//	nShowCmd 可选参数，SW_HIDE...
	// 更新窗口
	UpdateWindow(hwnd);

	WindowProc();

	return 0;
}
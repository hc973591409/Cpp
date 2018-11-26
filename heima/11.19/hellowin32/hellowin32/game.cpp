#include <iostream>
#include <windows.h>

using namespace std;
// 史上最简单的Win32程序搞定了     WINAPI 的作用只是告诉编译器这是win而已，可以忽略，也可以写作CALLBACK
//_In_ 是一个宏，告诉我们需要用户自行输入的一个参数
int CALLBACK WinMain(_In_ HINSTANCE hInstance,			// 函数运行的实例句柄  h表示句柄 Instance实例，当一个程序它运行的饿时候，它对应为一个运行实例，这个句柄是给main的
	_In_opt_ HINSTANCE hPrevInstance,					// 表示运行的时候前一个实例句柄，在这里总是null，没啥用
	_In_ LPSTR lpCmdLine,					// 传递给命令行参数，对命令行参数进行肢解
	_In_ int nShowCmd)						// 指定如何显示窗口，最大化，最小化等
{
	auto ib = MessageBox(NULL, L"你好visual studio 2013", L"消息窗口", MB_ABORTRETRYIGNORE|MB_ICONWARNING);
	//MessageBox(NULL, L"你好visual studio 2013", L"消息窗口", MB_OK);
	//MessageBox(NULL, L"你好visual studio 2013", L"消息窗口", MB_OKCANCEL);
	//MessageBox(NULL, L"你好visual studio 2013", L"消息窗口", MB_YESNO);
	//MessageBox(NULL, L"你好visual studio 2013", L"消息窗口", MB_YESNOCANCEL);
	/*     _In_opt_ 输入的可选参数 
	int WINAPI MessageBoxW(
	_In_opt_ HWND hWnd,					表示消息框所属句柄，也就是谁弹出来的
	_In_opt_ LPCWSTR lpText,     字符串  要显示的内容
	_In_opt_ LPCWSTR lpCaption,	标题
	_In_ UINT uType);		类型
	*/
	switch (ib)
	{
	case IDABORT:
		cout << "返回abour" << endl;
		MessageBox(NULL, L"返回abour", L"消息窗口", MB_ABORTRETRYIGNORE | MB_ICONWARNING);
		break;
	case IDCANCEL:
		cout << "返回取消" << endl;
		MessageBox(NULL, L"返回取消", L"消息窗口", MB_ABORTRETRYIGNORE | MB_ICONWARNING);
		break;
	case IDIGNORE:
		cout << "返回忽略" << endl;
		MessageBox(NULL, L"返回忽略", L"消息窗口", MB_ABORTRETRYIGNORE | MB_ICONWARNING);
		break;
	case IDNO:
		cout << "返回no" << endl;
		MessageBox(NULL, L"返回no", L"消息窗口", MB_ABORTRETRYIGNORE | MB_ICONWARNING);
		break;
	case IDRETRY:
		cout << "返回重试" << endl;
		MessageBox(NULL, L"返回重试", L"消息窗口", MB_ABORTRETRYIGNORE | MB_ICONWARNING);
		break;
	case IDYES:
		MessageBox(NULL, L"返回YES", L"消息窗口", MB_ABORTRETRYIGNORE | MB_ICONWARNING);
		break;
	default:
		MessageBox(NULL, L"返回DEFUALT", L"消息窗口", MB_ABORTRETRYIGNORE | MB_ICONWARNING);
		break;
	}

	// 这个函数是有返回值得
	return 0;
}
#include <iostream>
#include <windows.h>

using namespace std;
// ʷ����򵥵�Win32����㶨��     WINAPI ������ֻ�Ǹ��߱���������win���ѣ����Ժ��ԣ�Ҳ����д��CALLBACK
//_In_ ��һ���꣬����������Ҫ�û����������һ������
int CALLBACK WinMain(_In_ HINSTANCE hInstance,			// �������е�ʵ�����  h��ʾ��� Instanceʵ������һ�����������еĶ�ʱ������ӦΪһ������ʵ�����������Ǹ�main��
	_In_opt_ HINSTANCE hPrevInstance,					// ��ʾ���е�ʱ��ǰһ��ʵ�����������������null��ûɶ��
	_In_ LPSTR lpCmdLine,					// ���ݸ������в������������в�������֫��
	_In_ int nShowCmd)						// ָ�������ʾ���ڣ���󻯣���С����
{
	auto ib = MessageBox(NULL, L"���visual studio 2013", L"��Ϣ����", MB_ABORTRETRYIGNORE|MB_ICONWARNING);
	//MessageBox(NULL, L"���visual studio 2013", L"��Ϣ����", MB_OK);
	//MessageBox(NULL, L"���visual studio 2013", L"��Ϣ����", MB_OKCANCEL);
	//MessageBox(NULL, L"���visual studio 2013", L"��Ϣ����", MB_YESNO);
	//MessageBox(NULL, L"���visual studio 2013", L"��Ϣ����", MB_YESNOCANCEL);
	/*     _In_opt_ ����Ŀ�ѡ���� 
	int WINAPI MessageBoxW(
	_In_opt_ HWND hWnd,					��ʾ��Ϣ�����������Ҳ����˭��������
	_In_opt_ LPCWSTR lpText,     �ַ���  Ҫ��ʾ������
	_In_opt_ LPCWSTR lpCaption,	����
	_In_ UINT uType);		����
	*/
	switch (ib)
	{
	case IDABORT:
		cout << "����abour" << endl;
		MessageBox(NULL, L"����abour", L"��Ϣ����", MB_ABORTRETRYIGNORE | MB_ICONWARNING);
		break;
	case IDCANCEL:
		cout << "����ȡ��" << endl;
		MessageBox(NULL, L"����ȡ��", L"��Ϣ����", MB_ABORTRETRYIGNORE | MB_ICONWARNING);
		break;
	case IDIGNORE:
		cout << "���غ���" << endl;
		MessageBox(NULL, L"���غ���", L"��Ϣ����", MB_ABORTRETRYIGNORE | MB_ICONWARNING);
		break;
	case IDNO:
		cout << "����no" << endl;
		MessageBox(NULL, L"����no", L"��Ϣ����", MB_ABORTRETRYIGNORE | MB_ICONWARNING);
		break;
	case IDRETRY:
		cout << "��������" << endl;
		MessageBox(NULL, L"��������", L"��Ϣ����", MB_ABORTRETRYIGNORE | MB_ICONWARNING);
		break;
	case IDYES:
		MessageBox(NULL, L"����YES", L"��Ϣ����", MB_ABORTRETRYIGNORE | MB_ICONWARNING);
		break;
	default:
		MessageBox(NULL, L"����DEFUALT", L"��Ϣ����", MB_ABORTRETRYIGNORE | MB_ICONWARNING);
		break;
	}

	// ����������з���ֵ��
	return 0;
}
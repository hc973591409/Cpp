#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <Windows.h>
#include <wininet.h> 
#pragma comment (lib,"User32.lib")
#pragma comment( lib,"Urlmon.lib")
#pragma comment( lib, "wininet.lib") 
#define MAXBLOCKSIZE 1024

/**-----download(const char *Url,const char *save_as)--------------------
�������ܣ���ָ����Url��ַ���ļ����ص�����
����������
		Url���ļ���ָ��������ַ
		save_as���ļ����浽���ص�·����ַ
-------------------------------------------------------------------------**/
void download(const char *Url, const char *save_as)/*��Urlָ��ĵ�ַ���ļ����ص�save_asָ��ı����ļ�*/
{
	byte Temp[MAXBLOCKSIZE];
	ULONG Number = 1;

	FILE *stream;
	HINTERNET hSession = InternetOpen("RookIE/1.0", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
	if (hSession != NULL)
	{
		HINTERNET handle2 = InternetOpenUrl(hSession, Url, NULL, 0, INTERNET_FLAG_DONT_CACHE, 0);
		if (handle2 != NULL)
		{


			if ((stream = fopen(save_as, "wb")) != NULL)
			{
				while (Number > 0)
				{
					InternetReadFile(handle2, Temp, MAXBLOCKSIZE - 1, &Number);

					fwrite(Temp, sizeof(char), Number, stream);
				}
				fclose(stream);
			}

			InternetCloseHandle(handle2);
			handle2 = NULL;
		}
		InternetCloseHandle(hSession);
		hSession = NULL;
	}
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	/*****��1�֡�ʹ���Դ���WindowsAPI-URLDownloadToFile()���������ļ�******/
	/*char *url = "http://imgsrc.baidu.com/forum/pic/item/596da61ea8d3fd1f750432d8304e251f94ca5f2d.jpg";
	HRESULT hr = URLDownloadToFile(0,url,"mypic.jpg",0,NULL);
	*/
	/*****��2�֡�ʹ��download()���������ļ�******/
	MessageBox(NULL, "��������", "����", MB_OK);
	download("ftp://ygdy8:ygdy8@yg45.dydytt.net:3154/�����Ӱwww.ygdy8.com.а��ѹ��.HD.1080p.��������.mp4", "mypic.jpg");
	MessageBox(NULL, "�������", "����", MB_OK);
	return 0;
}

#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <Windows.h>
#include <wininet.h> 
#pragma comment (lib,"User32.lib")
#pragma comment( lib,"Urlmon.lib")
#pragma comment( lib, "wininet.lib") 
#define MAXBLOCKSIZE 1024

/**-----download(const char *Url,const char *save_as)--------------------
函数功能：将指定的Url地址的文件下载到本地
函数参数：
		Url：文件所指向的网络地址
		save_as：文件保存到本地的路径地址
-------------------------------------------------------------------------**/
void download(const char *Url, const char *save_as)/*将Url指向的地址的文件下载到save_as指向的本地文件*/
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
	/*****第1种、使用自带的WindowsAPI-URLDownloadToFile()函数下载文件******/
	/*char *url = "http://imgsrc.baidu.com/forum/pic/item/596da61ea8d3fd1f750432d8304e251f94ca5f2d.jpg";
	HRESULT hr = URLDownloadToFile(0,url,"mypic.jpg",0,NULL);
	*/
	/*****第2种、使用download()函数下载文件******/
	MessageBox(NULL, "正在下载", "下载", MB_OK);
	download("ftp://ygdy8:ygdy8@yg45.dydytt.net:3154/阳光电影www.ygdy8.com.邪不压正.HD.1080p.国语中字.mp4", "mypic.jpg");
	MessageBox(NULL, "下载完成", "下载", MB_OK);
	return 0;
}

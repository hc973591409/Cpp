#pragma once
#include <Windows.h>
#include "CONSTDEFINE.h"

class GameCore
{
public:
	//1. ����������
	GameCore(HINSTANCE hInstance);
	~GameCore();
	void UpdateWind();
	//BOOL Game_Init();			// ��ʼ��
	//VOID Game_Paint();			// ����
	//VOID Game_CleanUp();		// ������Դ

private:
	HWND hwnd;				// �����ھ��
	HBITMAP m_bitmap;
	HDC m_hdc;
	WNDCLASSEX wndclass;
	HINSTANCE hInstance;
};


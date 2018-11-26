#pragma once
#include <Windows.h>
#include "CONSTDEFINE.h"

class GameCore
{
public:
	//1. 窗口类的设计
	GameCore(HINSTANCE hInstance);
	~GameCore();
	void UpdateWind();
	//BOOL Game_Init();			// 初始化
	//VOID Game_Paint();			// 绘制
	//VOID Game_CleanUp();		// 清理资源

private:
	HWND hwnd;				// 主窗口句柄
	HBITMAP m_bitmap;
	HDC m_hdc;
	WNDCLASSEX wndclass;
	HINSTANCE hInstance;
};


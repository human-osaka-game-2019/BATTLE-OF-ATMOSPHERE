﻿#ifndef MAIN_H
#define MAIN_H

#include <windows.h>
#include <d3d9.h>

#include "../BATTLE-OF-ATMOSPHERE/Main.h"
#include "../BATTLE-OF-ATMOSPHERE/DirectX.h"
#include "../BATTLE-OF-ATMOSPHERE/Draw.h"

enum TEX {
	MAXTEX
};

enum SCENE {
	TITLESCENE,
	HELPSCENE,
	GAMESCENE,
	RESULTSCENE,
};


extern DIRECTX directx;

extern SCENE scene;

extern DRAW draw;

//WinMain関数
INT WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PSTR lpCmdline, _In_ INT nCmdShow);

//ウィンドプロシージャの生成
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

//window作成
HWND GenerateWindow(HWND* hWnd, HINSTANCE* hInstance, const TCHAR* API_NAME);

//メインループ
void Mainloop(MSG* msg);

#endif

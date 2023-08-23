/* 
*	main.cpp
*	エントリーポイントを定義
*/


#include <Windows.h>
#include "System/Window/window.hpp"


// エントリーポイント
int APIENTRY WinMain(
	// _In_, _In_opt_: SALの記法
	
	// インスタンスハンドル: Win32APIの関数呼び出し時の規約
	_In_ HINSTANCE hInstance,
	// 旧仕様のインスタンスハンドル: 常にNULL
	_In_opt_ HINSTANCE hPrevInstance,
	// コマンドライン引数の格納場所
	_In_ LPSTR lpCmdLine,
	// ウィンドウの初期表示方法
	_In_ int nCmdShow)
{	
	// ウィンドウクラス名
	TCHAR WndCN[] = TEXT("TestWindow");

	// ウィンドウクラスの定義
	WNDCLASSEX WindowClassEx =
	{
		// 構造体のサイズ
		sizeof(WNDCLASSEX),
		// ウィンドウのスタイル
		CS_HREDRAW | CS_VREDRAW,	
		// ウィンドウプロシージャ関数の登録
		WndProc,	
		// クラス構造体の後に確保するバイト数
		0,
		// インスタンスの後に確保するバイト数
		0,
		// インスタンスハンドル
		hInstance,
		// アイコン画像
		LoadIcon(NULL, IDI_APPLICATION),
		// カーソル画像
		LoadCursor(NULL, IDC_ARROW),	
		// 背景ブラシ(背景色)
		NULL,
		// メニュー名
		NULL,
		// ウィンドウクラス名
		WndCN,
		// タイトルバーのアイコン
		NULL
	};

	// ウィンドウクラスEXを登録
	if (!RegisterClassEx(&WindowClassEx))
	{
		// 失敗
		return 0;
	}

	// ウィンドウ生成
	HWND WindowHandle = CreateWindow(
		// ウィンドウクラス名
		WndCN,
		// タイトル名
		TEXT("DirectXTest"),
		// ウィンドウスタイル
		(WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME),
		// ウィンドウ左上端のx座標
		CW_USEDEFAULT,
		// ウィンドウ左上端のy座標
		CW_USEDEFAULT,
		// ウィンドウの幅
		Width,
		// ウィンドウの高さ
		Height,
		// 親ハンドル
		NULL,
		// メニューハンドル
		NULL,
		// インスタンスハンドル
		hInstance,
		// WM_CREATEで渡す値
		NULL);

	// ウィンドウ生成の確認
	if (!WindowHandle)
	{
		// 失敗
		return 0;
	}

	// 
	MSG Massage;


	// ウィンドウの表示
	ShowWindow(WindowHandle, nCmdShow);
	// ウィンドウの再描画
	UpdateWindow(WindowHandle);

	while (GetMessage(&Massage, NULL, 0, 0) > 0) {
		TranslateMessage(&Massage);
		DispatchMessage(&Massage);
	}

	return Massage.wParam;

	return 0;
}
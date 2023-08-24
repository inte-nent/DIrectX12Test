/*
*	window.cpp
*	ウィンドウ生成に関する定義と処理
* 
*	ソースコード記述で参考にした資料, サイト等
*	[1] Windows API 入門,
*		URL: http://kaitei.net/winapi/creating-windows/, 取得日: 2023/08/23
*	[2] YTTM WORK,
*		URL: https://yttm-work.jp/directx/directx_0026.html, 取得日: 2023/08/23
*/


// ウィンドウの幅
#define WINDOW_WIDTH		640
// ウィンドウの高さ
#define WINDOW_HEIGHT	480


#include <Windows.h>
#include "window.hpp"


// ウィンドウクラスEX
WNDCLASSEX window_class_ex;
// ウィンドウハンドル
HWND window_handle;
// メッセージ構造体
MSG message_structure;

// ウィンドウクラス名
TCHAR window_class_name[] = TEXT("TestWindow");
// ウィンドウタイトル名
TCHAR window_title_name[] = TEXT("DirectXTest");


// ウィンドウプロシージャ: OSからのメッセージの処理を行う(処理したら0を返す)
LRESULT CALLBACK WindowProcedure(
	// メッセージが送信されるウィンドウのハンドル
	HWND window_handle,
	// 送信されたメッセージ
	UINT message_id,
	// wパラメータ
	WPARAM w_param,
	// lパラメータ
	LPARAM l_param)
{
	// 受け取った各メッセージへの対応
	switch (message_id)
	{
	// ウィンドウが終了
	case WM_CLOSE:
	// ウィンドウが破棄
	case WM_DESTROY:	

		// メッセージループを終了
		PostQuitMessage(0);
		break;
		
	// 対応なし
	default:
		return DefWindowProc(window_handle, message_id, w_param, l_param);
		break;
	}

	return 0;
}


// ウィンドウのリサイズ
BOOL WindowResize(HWND window_handle)
{
	// ウィンドウサイズ用の構造体
	RECT window_rect;
	// 指定したウィンドウハンドルのウィンドウサイズを取得
	if (GetWindowRect(window_handle, &window_rect) == false)
	{
		// 失敗
		return FALSE;
	}

	// クライアント領域サイズ用の構造体
	RECT client_rect;
	// 指定したウィンドウハンドルのクライアント領域サイズを取得
	if (GetClientRect(window_handle, &client_rect) == false)
	{
		// 失敗
		return FALSE;
	}

	// フレームサイズの算出
	int frame_size_x = (window_rect.right - window_rect.left) - (client_rect.right - client_rect.left);
	int frame_size_y = (window_rect.bottom - window_rect.top) - (client_rect.bottom - client_rect.top);

	// リサイズ用サイズ(フレーム+クライアント)の算出
	int resize_width = frame_size_x + WINDOW_WIDTH;
	int resize_height = frame_size_y + WINDOW_HEIGHT;

	// ウィンドウサイズ更新
	SetWindowPos(
		// ウィンドウハンドル
		window_handle,
		// 配置順序ハンドル
		NULL,
		// ウィンドウ左上端のx座標
		CW_USEDEFAULT,
		// ウィンドウ左上端のy座標
		CW_USEDEFAULT,
		// リサイズ後の幅
		resize_width,
		// リサイズ後の高さ
		resize_height,
		// SWP_NOMOVE => 位置変更なし
		SWP_NOMOVE);

	return TRUE;
}


// ウィンドウを定義
BOOL DefineWindow(HINSTANCE h_instance)
{
	// ウィンドウクラスの定義
	WNDCLASSEX window_class_ex =
	{
		// 構造体のサイズ
		sizeof(WNDCLASSEX),
		// ウィンドウのスタイル
		(CS_HREDRAW | CS_VREDRAW),
		// ウィンドウプロシージャ関数の登録
		WindowProcedure,
		// クラス構造体の後に確保するバイト数
		0,
		// インスタンスの後に確保するバイト数
		0,
		// インスタンスハンドル
		h_instance,
		// アイコン画像
		LoadIcon(NULL, IDI_APPLICATION),
		// カーソル画像
		LoadCursor(NULL, IDC_ARROW),
		// 背景ブラシ(背景色)
		NULL,
		// メニュー名
		NULL,
		// ウィンドウクラス名
		window_class_name,
		// タイトルバーのアイコン
		NULL
	};

	// ウィンドウクラスEXを登録
	if (RegisterClassEx(&window_class_ex) == 0)
	{
		// 失敗
		return FALSE;
	}

	return TRUE;
}


// ウィンドウを生成
BOOL MakeWindow(HINSTANCE h_instance)
{
	// ウィンドウ生成
	HWND window_handle = CreateWindow(
		// ウィンドウクラス名
		window_class_name,
		// ウィンドウタイトル名
		window_title_name,
		// ウィンドウスタイル
		(WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME | WS_VISIBLE),
		// ウィンドウ左上端のx座標
		CW_USEDEFAULT,
		// ウィンドウ左上端のy座標
		CW_USEDEFAULT,
		// ウィンドウの幅
		WINDOW_WIDTH,
		// ウィンドウの高さ
		WINDOW_HEIGHT,
		// 親ハンドル
		NULL,
		// メニューハンドル
		NULL,
		// インスタンスハンドル
		h_instance,
		// WM_CREATEで渡す値
		NULL);

	// ウィンドウ生成の確認
	if (window_handle == NULL)
	{
		// 失敗
		return FALSE;
	}

	return TRUE;
}


// ウィンドウの定義と生成
BOOL DefineAndMakeWindow(HINSTANCE h_instance)
{
	// ウィンドウを定義
	if (DefineWindow(h_instance) == FALSE)
	{
		// 失敗
		return FALSE;
	}

	// ウィンドウを生成
	if (MakeWindow(h_instance) == FALSE)
	{
		// 失敗
		return FALSE;
	}

	return TRUE;
}


// ウィンドウハンドルを返す
HWND ReturnWindowHandle(VOID)
{
	return window_handle;
}


// メッセージループの終了確認
BOOL MessageRoopEndCheck()
{
	// WM_QUIT(終了)を調べる(PeekMessage関数は非同期)
	if (PeekMessage(&message_structure, NULL, 0, 0, PM_REMOVE))
	{
		// メッセージがWM_QUITであれば
		if (message_structure.message == WM_QUIT)
		{
			// メインループを抜ける
			return FALSE;
		}
		else
		{
			// メッセージ翻訳
			TranslateMessage(&message_structure);
			// プロシージャ関数へメッセージ送信
			DispatchMessage(&message_structure);
		}
	}

	return TRUE;
}


// メッセージパラメータ(wParam)を返す
unsigned __int64 MessageParam()
{
	return message_structure.wParam;
}

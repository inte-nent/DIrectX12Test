/*
*	window.cpp
*	生成するウィンドウに関する処理を定義
* 
*	ソースコード記述の参考にしたWebサイト
*	[1] Windows API 入門,
*	URL: http://kaitei.net/winapi/creating-windows/, 取得日: 2023/08/23
* 
*	[2] YTTM WORK,
*	URL: https://yttm-work.jp/directx/directx_0026.html, 取得日: 2023/08/23
*/


#include <Windows.h>
#include "window.hpp"


// ウィンドウプロシージャ: OSからのメッセージの処理を行う(処理したら0を返す)
LRESULT CALLBACK WndProc(
	HWND WindowHandle,		// メッセージが送信されるウィンドウのハンドル
	UINT MessageID,			// 送信されたメッセージ
	WPARAM wParam,			// wパラメータ
	LPARAM lParam)			// lパラメータ
{
	// 受け取った各メッセージへの対応
	switch (MessageID)
	{
	case WM_CLOSE:		// ウィンドウが終了
	case WM_DESTROY:		// ウィンドウが破棄

		// メッセージループを終了
		PostQuitMessage(0);
		break;
		
	// 対応なし
	default:
		return DefWindowProc(WindowHandle, MessageID, wParam, lParam);
		break;
	}

	return 0;
}


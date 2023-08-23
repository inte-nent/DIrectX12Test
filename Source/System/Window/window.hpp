/*
*	window.hpp
*/


#pragma once


#include <Windows.h>


// ウィンドウプロシージャ: OSからのメッセージの処理を行う(処理したら0を返す)
LRESULT CALLBACK WndProc(
	HWND WindowHandle,		// メッセージが送信されるウィンドウのハンドル
	UINT MessageID,			// 送信されたメッセージ
	WPARAM wParam,			// wパラメータ
	LPARAM lParam);			// lパラメータ
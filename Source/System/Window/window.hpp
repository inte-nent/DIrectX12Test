/*
*	window.hpp
*/


#pragma once


#include <Windows.h>


// ウィンドウの定義と生成
BOOL DefineAndMakeWindow(HINSTANCE h_instance);

// ウィンドウハンドルを返す
HWND ReturnWindowHandle(VOID);

// メッセージループの終了確認
BOOL MessageRoopEndCheck();

// メッセージパラメータを返す
unsigned __int64 MessageParam();
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
	_In_ HINSTANCE h_instance,
	// 旧仕様のインスタンスハンドル: 常にNULL
	_In_opt_ HINSTANCE h_prev_instance,
	// コマンドライン引数の格納場所
	_In_ LPSTR lp_cmd_line,
	// ウィンドウの初期表示方法
	_In_ int n_cmd_show)
{
	// ウィンドウの定義と生成
	if (DefineAndMakeWindow(h_instance) == FALSE)
	{
		// 失敗
		return 0;
	}

	// ウィンドウの表示
	ShowWindow(ReturnWindowHandle(), n_cmd_show);

	// メインループ
	while (TRUE)
	{
		// メッセージループの終了確認
		if (MessageRoopEndCheck() == FALSE)
		{
			// メインループを抜ける
			break;
		}
	}

	return MessageParam();
}
/*
*	window.hpp
*/


#pragma once


#include <Windows.h>


// �E�B���h�E�v���V�[�W��: OS����̃��b�Z�[�W�̏������s��(����������0��Ԃ�)
LRESULT CALLBACK WndProc(
	HWND WindowHandle,		// ���b�Z�[�W�����M�����E�B���h�E�̃n���h��
	UINT MessageID,			// ���M���ꂽ���b�Z�[�W
	WPARAM wParam,			// w�p�����[�^
	LPARAM lParam);			// l�p�����[�^
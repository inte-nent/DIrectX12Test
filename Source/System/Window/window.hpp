/*
*	window.hpp
*/


#pragma once


#include <Windows.h>


// �E�B���h�E�̒�`�Ɛ���
BOOL DefineAndMakeWindow(HINSTANCE h_instance);

// �E�B���h�E�n���h����Ԃ�
HWND ReturnWindowHandle(VOID);

// ���b�Z�[�W���[�v�̏I���m�F
BOOL MessageRoopEndCheck();

// ���b�Z�[�W�p�����[�^��Ԃ�
unsigned __int64 MessageParam();
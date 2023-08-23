/*
*	window.cpp
*	��������E�B���h�E�Ɋւ��鏈�����`
* 
*	�\�[�X�R�[�h�L�q�̎Q�l�ɂ���Web�T�C�g
*	[1] Windows API ����,
*	URL: http://kaitei.net/winapi/creating-windows/, �擾��: 2023/08/23
* 
*	[2] YTTM WORK,
*	URL: https://yttm-work.jp/directx/directx_0026.html, �擾��: 2023/08/23
*/


#include <Windows.h>
#include "window.hpp"


// �E�B���h�E�v���V�[�W��: OS����̃��b�Z�[�W�̏������s��(����������0��Ԃ�)
LRESULT CALLBACK WndProc(
	HWND WindowHandle,		// ���b�Z�[�W�����M�����E�B���h�E�̃n���h��
	UINT MessageID,			// ���M���ꂽ���b�Z�[�W
	WPARAM wParam,			// w�p�����[�^
	LPARAM lParam)			// l�p�����[�^
{
	// �󂯎�����e���b�Z�[�W�ւ̑Ή�
	switch (MessageID)
	{
	case WM_CLOSE:		// �E�B���h�E���I��
	case WM_DESTROY:		// �E�B���h�E���j��

		// ���b�Z�[�W���[�v���I��
		PostQuitMessage(0);
		break;
		
	// �Ή��Ȃ�
	default:
		return DefWindowProc(WindowHandle, MessageID, wParam, lParam);
		break;
	}

	return 0;
}


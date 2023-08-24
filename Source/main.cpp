/* 
*	main.cpp
*	�G���g���[�|�C���g���`
*/


#include <Windows.h>
#include "System/Window/window.hpp"


// �G���g���[�|�C���g
int APIENTRY WinMain(
	// _In_, _In_opt_: SAL�̋L�@
	
	// �C���X�^���X�n���h��: Win32API�̊֐��Ăяo�����̋K��
	_In_ HINSTANCE h_instance,
	// ���d�l�̃C���X�^���X�n���h��: ���NULL
	_In_opt_ HINSTANCE h_prev_instance,
	// �R�}���h���C�������̊i�[�ꏊ
	_In_ LPSTR lp_cmd_line,
	// �E�B���h�E�̏����\�����@
	_In_ int n_cmd_show)
{
	// �E�B���h�E�̒�`�Ɛ���
	if (DefineAndMakeWindow(h_instance) == FALSE)
	{
		// ���s
		return 0;
	}

	// �E�B���h�E�̕\��
	ShowWindow(ReturnWindowHandle(), n_cmd_show);

	// ���C�����[�v
	while (TRUE)
	{
		// ���b�Z�[�W���[�v�̏I���m�F
		if (MessageRoopEndCheck() == FALSE)
		{
			// ���C�����[�v�𔲂���
			break;
		}
	}

	return MessageParam();
}
/*
*	window.cpp
*	�E�B���h�E�����Ɋւ����`�Ə���
* 
*	�\�[�X�R�[�h�L�q�ŎQ�l�ɂ�������, �T�C�g��
*	[1] Windows API ����,
*		URL: http://kaitei.net/winapi/creating-windows/, �擾��: 2023/08/23
*	[2] YTTM WORK,
*		URL: https://yttm-work.jp/directx/directx_0026.html, �擾��: 2023/08/23
*/


// �E�B���h�E�̕�
#define WINDOW_WIDTH		640
// �E�B���h�E�̍���
#define WINDOW_HEIGHT	480


#include <Windows.h>
#include "window.hpp"


// �E�B���h�E�N���XEX
WNDCLASSEX window_class_ex;
// �E�B���h�E�n���h��
HWND window_handle;
// ���b�Z�[�W�\����
MSG message_structure;

// �E�B���h�E�N���X��
TCHAR window_class_name[] = TEXT("TestWindow");
// �E�B���h�E�^�C�g����
TCHAR window_title_name[] = TEXT("DirectXTest");


// �E�B���h�E�v���V�[�W��: OS����̃��b�Z�[�W�̏������s��(����������0��Ԃ�)
LRESULT CALLBACK WindowProcedure(
	// ���b�Z�[�W�����M�����E�B���h�E�̃n���h��
	HWND window_handle,
	// ���M���ꂽ���b�Z�[�W
	UINT message_id,
	// w�p�����[�^
	WPARAM w_param,
	// l�p�����[�^
	LPARAM l_param)
{
	// �󂯎�����e���b�Z�[�W�ւ̑Ή�
	switch (message_id)
	{
	// �E�B���h�E���I��
	case WM_CLOSE:
	// �E�B���h�E���j��
	case WM_DESTROY:	

		// ���b�Z�[�W���[�v���I��
		PostQuitMessage(0);
		break;
		
	// �Ή��Ȃ�
	default:
		return DefWindowProc(window_handle, message_id, w_param, l_param);
		break;
	}

	return 0;
}


// �E�B���h�E�̃��T�C�Y
BOOL WindowResize(HWND window_handle)
{
	// �E�B���h�E�T�C�Y�p�̍\����
	RECT window_rect;
	// �w�肵���E�B���h�E�n���h���̃E�B���h�E�T�C�Y���擾
	if (GetWindowRect(window_handle, &window_rect) == false)
	{
		// ���s
		return FALSE;
	}

	// �N���C�A���g�̈�T�C�Y�p�̍\����
	RECT client_rect;
	// �w�肵���E�B���h�E�n���h���̃N���C�A���g�̈�T�C�Y���擾
	if (GetClientRect(window_handle, &client_rect) == false)
	{
		// ���s
		return FALSE;
	}

	// �t���[���T�C�Y�̎Z�o
	int frame_size_x = (window_rect.right - window_rect.left) - (client_rect.right - client_rect.left);
	int frame_size_y = (window_rect.bottom - window_rect.top) - (client_rect.bottom - client_rect.top);

	// ���T�C�Y�p�T�C�Y(�t���[��+�N���C�A���g)�̎Z�o
	int resize_width = frame_size_x + WINDOW_WIDTH;
	int resize_height = frame_size_y + WINDOW_HEIGHT;

	// �E�B���h�E�T�C�Y�X�V
	SetWindowPos(
		// �E�B���h�E�n���h��
		window_handle,
		// �z�u�����n���h��
		NULL,
		// �E�B���h�E����[��x���W
		CW_USEDEFAULT,
		// �E�B���h�E����[��y���W
		CW_USEDEFAULT,
		// ���T�C�Y��̕�
		resize_width,
		// ���T�C�Y��̍���
		resize_height,
		// SWP_NOMOVE => �ʒu�ύX�Ȃ�
		SWP_NOMOVE);

	return TRUE;
}


// �E�B���h�E���`
BOOL DefineWindow(HINSTANCE h_instance)
{
	// �E�B���h�E�N���X�̒�`
	WNDCLASSEX window_class_ex =
	{
		// �\���̂̃T�C�Y
		sizeof(WNDCLASSEX),
		// �E�B���h�E�̃X�^�C��
		(CS_HREDRAW | CS_VREDRAW),
		// �E�B���h�E�v���V�[�W���֐��̓o�^
		WindowProcedure,
		// �N���X�\���̂̌�Ɋm�ۂ���o�C�g��
		0,
		// �C���X�^���X�̌�Ɋm�ۂ���o�C�g��
		0,
		// �C���X�^���X�n���h��
		h_instance,
		// �A�C�R���摜
		LoadIcon(NULL, IDI_APPLICATION),
		// �J�[�\���摜
		LoadCursor(NULL, IDC_ARROW),
		// �w�i�u���V(�w�i�F)
		NULL,
		// ���j���[��
		NULL,
		// �E�B���h�E�N���X��
		window_class_name,
		// �^�C�g���o�[�̃A�C�R��
		NULL
	};

	// �E�B���h�E�N���XEX��o�^
	if (RegisterClassEx(&window_class_ex) == 0)
	{
		// ���s
		return FALSE;
	}

	return TRUE;
}


// �E�B���h�E�𐶐�
BOOL MakeWindow(HINSTANCE h_instance)
{
	// �E�B���h�E����
	HWND window_handle = CreateWindow(
		// �E�B���h�E�N���X��
		window_class_name,
		// �E�B���h�E�^�C�g����
		window_title_name,
		// �E�B���h�E�X�^�C��
		(WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME | WS_VISIBLE),
		// �E�B���h�E����[��x���W
		CW_USEDEFAULT,
		// �E�B���h�E����[��y���W
		CW_USEDEFAULT,
		// �E�B���h�E�̕�
		WINDOW_WIDTH,
		// �E�B���h�E�̍���
		WINDOW_HEIGHT,
		// �e�n���h��
		NULL,
		// ���j���[�n���h��
		NULL,
		// �C���X�^���X�n���h��
		h_instance,
		// WM_CREATE�œn���l
		NULL);

	// �E�B���h�E�����̊m�F
	if (window_handle == NULL)
	{
		// ���s
		return FALSE;
	}

	return TRUE;
}


// �E�B���h�E�̒�`�Ɛ���
BOOL DefineAndMakeWindow(HINSTANCE h_instance)
{
	// �E�B���h�E���`
	if (DefineWindow(h_instance) == FALSE)
	{
		// ���s
		return FALSE;
	}

	// �E�B���h�E�𐶐�
	if (MakeWindow(h_instance) == FALSE)
	{
		// ���s
		return FALSE;
	}

	return TRUE;
}


// �E�B���h�E�n���h����Ԃ�
HWND ReturnWindowHandle(VOID)
{
	return window_handle;
}


// ���b�Z�[�W���[�v�̏I���m�F
BOOL MessageRoopEndCheck()
{
	// WM_QUIT(�I��)�𒲂ׂ�(PeekMessage�֐��͔񓯊�)
	if (PeekMessage(&message_structure, NULL, 0, 0, PM_REMOVE))
	{
		// ���b�Z�[�W��WM_QUIT�ł����
		if (message_structure.message == WM_QUIT)
		{
			// ���C�����[�v�𔲂���
			return FALSE;
		}
		else
		{
			// ���b�Z�[�W�|��
			TranslateMessage(&message_structure);
			// �v���V�[�W���֐��փ��b�Z�[�W���M
			DispatchMessage(&message_structure);
		}
	}

	return TRUE;
}


// ���b�Z�[�W�p�����[�^(wParam)��Ԃ�
unsigned __int64 MessageParam()
{
	return message_structure.wParam;
}

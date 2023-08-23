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
	_In_ HINSTANCE hInstance,
	// ���d�l�̃C���X�^���X�n���h��: ���NULL
	_In_opt_ HINSTANCE hPrevInstance,
	// �R�}���h���C�������̊i�[�ꏊ
	_In_ LPSTR lpCmdLine,
	// �E�B���h�E�̏����\�����@
	_In_ int nCmdShow)
{	
	// �E�B���h�E�N���X��
	TCHAR WndCN[] = TEXT("TestWindow");

	// �E�B���h�E�N���X�̒�`
	WNDCLASSEX WindowClassEx =
	{
		// �\���̂̃T�C�Y
		sizeof(WNDCLASSEX),
		// �E�B���h�E�̃X�^�C��
		CS_HREDRAW | CS_VREDRAW,	
		// �E�B���h�E�v���V�[�W���֐��̓o�^
		WndProc,	
		// �N���X�\���̂̌�Ɋm�ۂ���o�C�g��
		0,
		// �C���X�^���X�̌�Ɋm�ۂ���o�C�g��
		0,
		// �C���X�^���X�n���h��
		hInstance,
		// �A�C�R���摜
		LoadIcon(NULL, IDI_APPLICATION),
		// �J�[�\���摜
		LoadCursor(NULL, IDC_ARROW),	
		// �w�i�u���V(�w�i�F)
		NULL,
		// ���j���[��
		NULL,
		// �E�B���h�E�N���X��
		WndCN,
		// �^�C�g���o�[�̃A�C�R��
		NULL
	};

	// �E�B���h�E�N���XEX��o�^
	if (!RegisterClassEx(&WindowClassEx))
	{
		// ���s
		return 0;
	}

	// �E�B���h�E����
	HWND WindowHandle = CreateWindow(
		// �E�B���h�E�N���X��
		WndCN,
		// �^�C�g����
		TEXT("DirectXTest"),
		// �E�B���h�E�X�^�C��
		(WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME),
		// �E�B���h�E����[��x���W
		CW_USEDEFAULT,
		// �E�B���h�E����[��y���W
		CW_USEDEFAULT,
		// �E�B���h�E�̕�
		Width,
		// �E�B���h�E�̍���
		Height,
		// �e�n���h��
		NULL,
		// ���j���[�n���h��
		NULL,
		// �C���X�^���X�n���h��
		hInstance,
		// WM_CREATE�œn���l
		NULL);

	// �E�B���h�E�����̊m�F
	if (!WindowHandle)
	{
		// ���s
		return 0;
	}

	// 
	MSG Massage;


	// �E�B���h�E�̕\��
	ShowWindow(WindowHandle, nCmdShow);
	// �E�B���h�E�̍ĕ`��
	UpdateWindow(WindowHandle);

	while (GetMessage(&Massage, NULL, 0, 0) > 0) {
		TranslateMessage(&Massage);
		DispatchMessage(&Massage);
	}

	return Massage.wParam;

	return 0;
}
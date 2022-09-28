#include "DxLib.h"
#include "main.h"
#include "aim.h"
#include "meteo.h"

//�}�E�X�|�C���^��覐΂̓����蔻��
bool CheckHit(Aim aim,Meteo meteo[4],int i) {

	//X���W���d�Ȃ��Ă��Ȃ��ꍇfalse
	if (meteo[i].GetPosX() > static_cast<float>(aim.GetPosX()) || meteo[i].GetPosX() + meteo[i].GetsizeX() < static_cast<float>(aim.GetPosX())) {
		return false;
	}

	//Y���W���d�Ȃ��Ă��Ȃ��ꍇfalse
	if (meteo[i].GetPosY() > static_cast<float>(aim.GetPosY()) || meteo[i].GetPosY() + meteo[i].GetsizeY() < static_cast<float>(aim.GetPosY())) {
		return false;
	}

	//��̏����N���A��true
	return true;

}

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	ChangeWindowMode(kWindowMode);																//�E�B���h�E���[�h�ɐݒ�

	//SetDrawScreen(DX_SCREEN_BACK);

	SetMainWindowText(kTitleText);																//�E�B���h�E�̃^�C�g����ݒ�

	SetGraphMode(kWindowWidth, kWindowHeight, kColorDepth);										//�E�B���h�E�̃T�C�Y�ƐF��ݒ�


	if (DxLib_Init() == -1)																		// �c�w���C�u��������������
	{
		return -1;																				// �G���[���N�����璼���ɏI��
	}


	//�X�^�[�g��ʂ̎���
	while (ProcessMessage() == 0) {

		if (CheckHitKey(KEY_INPUT_ESCAPE))break;												//ESC�L�[�ŏI��

		ClearDrawScreen();																		//��ʂ��N���A

		SetFontSize(100);																		//�t�H���g�T�C�Y��ݒ�

		//�^�C�g���\��
		DrawFormatString(170, 250, GetColor(255, 255, 255), "�^�C�g��");						//�^�C�g����`��

		SetFontSize(22);																		//�t�H���g�T�C�Y��ݒ�

		DrawFormatString(290, 400, GetColor(255, 255, 255), "START : SPACE");					//�J�n������`��


		if (CheckHitKey(KEY_INPUT_SPACE))break;													//SPACE�L�[�ŊJ�n

		if (CheckHitKey(KEY_INPUT_ESCAPE))break;												//ESC�L�[�ŏI��
	}


	Aim aim1;																					//�G�C���̃f�[�^�ϐ�
	Meteo meteo[4];																				//覐΂̃f�[�^�ϐ�
	int BreakCount = 0;																			//覐΂̔j��
	int mouseDetection[3];																		//�}�E�X�̓��͌��m��p�ϐ�
	int clickcount = 0;																			//�������J�E���g����(mouseDetection�p)�ϐ�


																								//�}�E�X�̓��͌��m��p�ϐ��̏�����
	for (int i = 0; i < 3; i++) {

		mouseDetection[i] = 0;

	}

	SetFontSize(24);																			//�t�H���g�T�C�Y��ݒ�

																								//覐΂̃f�[�^���擾����
	for (int i = 0; i < 4; i++) {
		meteo[i].SetPos();																		//覐΂̍��W�f�[�^���擾
		meteo[i].SetVec();																		//覐΂̃x�N�g�����擾
	}

	while (ProcessMessage() == 0) {


		if (CheckHitKey(KEY_INPUT_ESCAPE))break;												//ESC�L�[��������Ă���Ǝ��s���Ȃ�

		ClearDrawScreen();																		//��ʂ��N���A
		
																								//覐΂̏���
		for (int i = 0; i < 4; i++) {
			meteo[i].SetImage();																//�摜�f�[�^���擾
			meteo[i].SetSize();																	//覐΂̃T�C�Y���擾
			meteo[i].Draw();																	//覐΂�`��
			meteo[i].MoveMeteo();																//覐΂𓮂���
			if (meteo[i].GetPosX() < -(meteo[i].GetsizeX())) {									//覐΂���ʊO�ɍs�����Ƃ�

				meteo[i].SetPos();																//覐΂̍��W�f�[�^���Ď擾
				meteo[i].SetVec();																//覐΂̃x�N�g�����Ď擾

			}
		}
		
		aim1.SetPos();																			//�G�C��(�}�E�X�|�C���^)�̍��W���擾
		aim1.Draw();																			//�Ə���`��

		/*for (int i = 0; i < 4; i++) {
			DrawFormatString(0, i * 15, GetColor(255, 255, 255), "%f", meteo[i].GetVecY());
		}*/

		clickcount++;																			//�������J�E���g
		if (clickcount == 3) {																	//3�ɂȂ��
			clickcount = 0;																		//0�ɖ߂��B
		}

																								//���݂̃}�E�X�̏�Ԃ��擾����
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)											//�N���b�N����Ă���ꍇ��
		{
			mouseDetection[clickcount] = 1;														//1�ɂ���
		}
		else {																					//�N���b�N����Ă��Ȃ��ꍇ��
			mouseDetection[clickcount] = 0;														//0�ɂ���
		}

																								//�N���b�N���ꂽ�u�Ԃ̏���
		if (clickcount == 1 || clickcount == 2) {												
			if (mouseDetection[clickcount - 1] == 0 && mouseDetection[clickcount] == 1) {		//�}�E�X�̓��͌��m��0����1�ɕς�����Ƃ�
				for (int i = 0; i < 4; i++) {													//�G�C����覐΂̓����蔻�菈�������s
					if (CheckHit(aim1, meteo, i) == true) {										//�������Ă���Ƃ�
						meteo[i].Delete();
						meteo[i].SetPos();														//覐΂̍��W�f�[�^���Ď擾
						meteo[i].SetVec();														//覐΂̃x�N�g�����Ď擾
						BreakCount++;															//覐΂̌��j�����J�E���g
						break;																	//�������I��
					}
				}
			}
		}
		else {
			if (mouseDetection[2] == 0 && mouseDetection[0] == 1) {								//��L�̃N���b�N���ꂽ�u�Ԃ̏����Ɠ��l
				for (int i = 0; i < 4; i++) {													//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
					if (CheckHit(aim1, meteo, i) == true) {										//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
						meteo[i].Delete();
						meteo[i].SetPos();														//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
						meteo[i].SetVec();														//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
						BreakCount++;															//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
						break;																	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
					}
				}
			}
		}


		DrawFormatString(0,696, GetColor(255, 255, 255), "���j�� : %d", BreakCount);			//���݂̌��j����`��


		ScreenFlip();


		if (CheckHitKey(KEY_INPUT_ESCAPE))break;												//ESC�L�[�ŏI��
		if (BreakCount == 20)break;																//���j����20�ŏI��
	}

	while (ProcessMessage() == 0) {

		if (CheckHitKey(KEY_INPUT_ESCAPE))break;												//ESC�L�[��������Ă���Ǝ��s���Ȃ�

		ClearDrawScreen();																		//��ʂ��N���A


		SetFontSize(100);																		//�t�H���g�T�C�Y��ݒ�


		DrawFormatString(230, 300, GetColor(255, 255, 255), "CLEAR");							//�N���A��`��

		if (CheckHitKey(KEY_INPUT_ESCAPE))break;												//ESC�L�[�ŏI��		
	}


	for (int i = 0; i < 4; i++) {

		meteo[i].Delete();																		//覐΂̉摜�f�[�^��������������

	}

	WaitKey();																					// �L�[���͑҂�

	DxLib_End();																				// �c�w���C�u�����g�p�̏I������

	return 0;																					// �\�t�g�̏I�� 
}
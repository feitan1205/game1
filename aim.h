#pragma once

//�G�C���̃N���X��
class Aim {

public:

	Aim();								//�G�C��������������֐�
	void SetPos();						//�G�C���̍��W��ݒ肷��֐�
	int GetPosX() { return posX; }		//�G�C���̍��WX���擾����֐�
	int GetPosY() { return posY; }		//�G�C���̍��WY���擾����֐�
	void Draw();						//�G�C����`�悷��֐�

private:

	int posX;							//X���W�̕ϐ�
	int posY;							//Y���W�̕ϐ�

};
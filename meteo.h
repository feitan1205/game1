#pragma once

//覐΂̃N���X��
class Meteo {

public:

	Meteo();							//�������֐�
	void SetPos();						//覐΂̍��W�f�[�^�̐ݒ�֐�
	void SetSize();						//覐΂̃T�C�Y�ݒ�֐�
	void SetVec();						//覐΂̃x�N�g���ݒ�֐�
	void SetImage();					//覐΂̉摜�f�[�^�ݒ�֐�
	void MoveMeteo();					//覐΂̓���ݒ�֐�
	void Draw();						//覐΂̕`��֐�
	void Delete();						//覐΂̉摜�f�[�^������������J������֐�
	float GetPosX() { return posX; }	//覐΂�X���W�f�[�^�擾�֐�
	float GetPosY() { return posY; }	//覐΂�Y���W�f�[�^�擾�֐�
	int GetsizeX() { return sizeX; }	//覐΂̃T�C�YX�擾�֐�
	int GetsizeY() { return sizeY; }	//覐΂̃T�C�YY�擾�֐�
	float GetVecY() { return vecY; }	//覐΂̃x�N�g��Y�擾�֐�

private:

	int handle;							//�摜�f�[�^�ϐ�
	float posX;							//覐΂�X���W�ϐ�
	float posY;							//覐΂�Y���W�ϐ�
	int sizeX;							//覐΂̃T�C�YX�ϐ�
	int sizeY;							//覐΂̃T�C�YY�ϐ�
	float vecX;							//覐΂̃x�N�g��X�ϐ�
	float vecY;							//覐΂̃x�N�g��Y�ϐ�

};
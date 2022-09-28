#pragma once

//隕石のクラス化
class Meteo {

public:

	Meteo();							//初期化関数
	void SetPos();						//隕石の座標データの設定関数
	void SetSize();						//隕石のサイズ設定関数
	void SetVec();						//隕石のベクトル設定関数
	void SetImage();					//隕石の画像データ設定関数
	void MoveMeteo();					//隕石の動作設定関数
	void Draw();						//隕石の描画関数
	void Delete();						//隕石の画像データをメモリから開放する関数
	float GetPosX() { return posX; }	//隕石のX座標データ取得関数
	float GetPosY() { return posY; }	//隕石のY座標データ取得関数
	int GetsizeX() { return sizeX; }	//隕石のサイズX取得関数
	int GetsizeY() { return sizeY; }	//隕石のサイズY取得関数
	float GetVecY() { return vecY; }	//隕石のベクトルY取得関数

private:

	int handle;							//画像データ変数
	float posX;							//隕石のX座標変数
	float posY;							//隕石のY座標変数
	int sizeX;							//隕石のサイズX変数
	int sizeY;							//隕石のサイズY変数
	float vecX;							//隕石のベクトルX変数
	float vecY;							//隕石のベクトルY変数

};
#include "DxLib.h"
#include "meteo.h"
#include "main.h"

namespace{
	constexpr float kSpeed = 3.0;
}

//隕石データの初期化
Meteo::Meteo() {

	handle = 0;
	posX = 0;
	posY = 0;
	sizeX = 0;
	sizeY = 0;
	vecX = 0;
	vecY = 0;

}


//隕石の座標データの設定関数
void Meteo::SetPos() {

	posX = static_cast<float>(GetRand(500)) + 750;						//隕石の初期位置X座標を750から1250の間で取得
	posY = (float)GetRand(kWindowHeight - sizeY);						//隕石の初期位置Y座標を画面内で取得する		

}

//隕石のサイズ設定関数
void Meteo::SetSize() {

	GetGraphSize(handle, &sizeX, &sizeY);								//画像のサイズを取得する

}

//隕石のベクトル設定関数
void Meteo::SetVec() {

	vecX = (float)(GetRand(1) + 1);										//X方向のベクトルを1か2で取得する
	vecY = static_cast<float>(GetRand(100)) / 100 + (float)0.01;		//Y方向のベクトルを0.01から0.99で取得する

	if (posY > 360) {													//隕石の初期位置が画面下半分の時

		vecY = -(vecY);													//Y方向のベクトルを反転する

	}

}

//隕石の画像データ設定関数
void Meteo::SetImage() {

	handle = LoadGraph("data/virus.png");								//handleに隕石の画像のデータを取得する

}

//隕石の動作設定関数
void Meteo::MoveMeteo() {

	posX -= vecX * kSpeed;														//X座標をベクトル分移動させる
	posY += vecY * kSpeed;														//Y座標をベクトル分移動させる

}

void Meteo::Delete() {

	DeleteGraph(handle);												//隕石の画像データをメモリから解放

}

//隕石の描画関数
void Meteo::Draw() {

	DrawGraphF(posX, posY, handle, true);								//隕石を描画する

}
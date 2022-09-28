#pragma once

//エイムのクラス化
class Aim {

public:

	Aim();								//エイムを初期化する関数
	void SetPos();						//エイムの座標を設定する関数
	int GetPosX() { return posX; }		//エイムの座標Xを取得する関数
	int GetPosY() { return posY; }		//エイムの座標Yを取得する関数
	void Draw();						//エイムを描画する関数

private:

	int posX;							//X座標の変数
	int posY;							//Y座標の変数

};
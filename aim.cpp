#include "DxLib.h"
#include "main.h"
#include "aim.h"

//Aimの初期化
Aim::Aim() {

	posX = 0;
	posY = 0;

}

//エイムの座標を取得する関数
void Aim::SetPos() {

	GetMousePoint(&posX, &posY);															//マウスポインタの座標を取得

}


//エイムを描画する関数
void Aim::Draw() {


	DrawLine(posX - 5, posY, posX + 5, posY, GetColor(255, 255, 255), true);				//エイムを描画
	DrawLine(posX, posY - 5, posX, posY + 5, GetColor(255, 255, 255), true);				//~~~~~~~~~~~~
	DrawLine(posX - 20, posY + 20, posX + 20, posY + 20, GetColor(255, 255, 255), true);	//~~~~~~~~~~~~
	DrawLine(posX - 20, posY - 20, posX + 20, posY - 20, GetColor(255, 255, 255), true);	//~~~~~~~~~~~~
	DrawLine(posX + 20, posY - 20, posX + 20, posY + 20, GetColor(255, 255, 255), true);	//~~~~~~~~~~~~
	DrawLine(posX - 20, posY - 20, posX - 20, posY + 20, GetColor(255, 255, 255), true);	//~~~~~~~~~~~~
	DrawLine(posX - 15, posY, posX - 25, posY, GetColor(255, 255, 255), true);				//~~~~~~~~~~~~
	DrawLine(posX, posY - 15, posX, posY - 25, GetColor(255, 255, 255), true);				//~~~~~~~~~~~~
	DrawLine(posX + 15, posY, posX + 25, posY, GetColor(255, 255, 255), true);				//~~~~~~~~~~~~
	DrawLine(posX, posY + 15, posX, posY + 25, GetColor(255, 255, 255), true);				//~~~~~~~~~~~~
	DrawLine(posX, posY,0,720, GetColor(200, 200, 200), true);								//~~~~~~~~~~~~
	DrawLine(posX, posY,720, 720, GetColor(200, 200, 200), true);							//~~~~~~~~~~~~


}
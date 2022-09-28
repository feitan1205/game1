#include "DxLib.h"
#include "main.h"
#include "aim.h"
#include "meteo.h"

//マウスポインタと隕石の当たり判定
bool CheckHit(Aim aim,Meteo meteo[4],int i) {

	//X座標が重なっていない場合false
	if (meteo[i].GetPosX() > static_cast<float>(aim.GetPosX()) || meteo[i].GetPosX() + meteo[i].GetsizeX() < static_cast<float>(aim.GetPosX())) {
		return false;
	}

	//Y座標が重なっていない場合false
	if (meteo[i].GetPosY() > static_cast<float>(aim.GetPosY()) || meteo[i].GetPosY() + meteo[i].GetsizeY() < static_cast<float>(aim.GetPosY())) {
		return false;
	}

	//上の条件クリアでtrue
	return true;

}

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	ChangeWindowMode(kWindowMode);																//ウィンドウモードに設定

	//SetDrawScreen(DX_SCREEN_BACK);

	SetMainWindowText(kTitleText);																//ウィンドウのタイトルを設定

	SetGraphMode(kWindowWidth, kWindowHeight, kColorDepth);										//ウィンドウのサイズと色を設定


	if (DxLib_Init() == -1)																		// ＤＸライブラリ初期化処理
	{
		return -1;																				// エラーが起きたら直ちに終了
	}


	//スタート画面の実装
	while (ProcessMessage() == 0) {

		if (CheckHitKey(KEY_INPUT_ESCAPE))break;												//ESCキーで終了

		ClearDrawScreen();																		//画面をクリア

		SetFontSize(100);																		//フォントサイズを設定

		//タイトル表示
		DrawFormatString(170, 250, GetColor(255, 255, 255), "タイトル");						//タイトルを描画

		SetFontSize(22);																		//フォントサイズを設定

		DrawFormatString(290, 400, GetColor(255, 255, 255), "START : SPACE");					//開始条件を描画


		if (CheckHitKey(KEY_INPUT_SPACE))break;													//SPACEキーで開始

		if (CheckHitKey(KEY_INPUT_ESCAPE))break;												//ESCキーで終了
	}


	Aim aim1;																					//エイムのデータ変数
	Meteo meteo[4];																				//隕石のデータ変数
	int BreakCount = 0;																			//隕石の破壊数
	int mouseDetection[3];																		//マウスの入力検知専用変数
	int clickcount = 0;																			//処理をカウントする(mouseDetection用)変数


																								//マウスの入力検知専用変数の初期化
	for (int i = 0; i < 3; i++) {

		mouseDetection[i] = 0;

	}

	SetFontSize(24);																			//フォントサイズを設定

																								//隕石のデータを取得する
	for (int i = 0; i < 4; i++) {
		meteo[i].SetPos();																		//隕石の座標データを取得
		meteo[i].SetVec();																		//隕石のベクトルを取得
	}

	while (ProcessMessage() == 0) {


		if (CheckHitKey(KEY_INPUT_ESCAPE))break;												//ESCキーが押されていると実行しない

		ClearDrawScreen();																		//画面をクリア
		
																								//隕石の処理
		for (int i = 0; i < 4; i++) {
			meteo[i].SetImage();																//画像データを取得
			meteo[i].SetSize();																	//隕石のサイズを取得
			meteo[i].Draw();																	//隕石を描画
			meteo[i].MoveMeteo();																//隕石を動かす
			if (meteo[i].GetPosX() < -(meteo[i].GetsizeX())) {									//隕石が画面外に行ったとき

				meteo[i].SetPos();																//隕石の座標データを再取得
				meteo[i].SetVec();																//隕石のベクトルを再取得

			}
		}
		
		aim1.SetPos();																			//エイム(マウスポインタ)の座標を取得
		aim1.Draw();																			//照準を描画

		/*for (int i = 0; i < 4; i++) {
			DrawFormatString(0, i * 15, GetColor(255, 255, 255), "%f", meteo[i].GetVecY());
		}*/

		clickcount++;																			//処理をカウント
		if (clickcount == 3) {																	//3になると
			clickcount = 0;																		//0に戻す。
		}

																								//現在のマウスの状態を取得する
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)											//クリックされている場合は
		{
			mouseDetection[clickcount] = 1;														//1にする
		}
		else {																					//クリックされていない場合は
			mouseDetection[clickcount] = 0;														//0にする
		}

																								//クリックされた瞬間の処理
		if (clickcount == 1 || clickcount == 2) {												
			if (mouseDetection[clickcount - 1] == 0 && mouseDetection[clickcount] == 1) {		//マウスの入力検知が0から1に変わったとき
				for (int i = 0; i < 4; i++) {													//エイムと隕石の当たり判定処理を実行
					if (CheckHit(aim1, meteo, i) == true) {										//当たっているとき
						meteo[i].Delete();
						meteo[i].SetPos();														//隕石の座標データを再取得
						meteo[i].SetVec();														//隕石のベクトルを再取得
						BreakCount++;															//隕石の撃破数をカウント
						break;																	//処理を終了
					}
				}
			}
		}
		else {
			if (mouseDetection[2] == 0 && mouseDetection[0] == 1) {								//上記のクリックされた瞬間の処理と同様
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


		DrawFormatString(0,696, GetColor(255, 255, 255), "撃破数 : %d", BreakCount);			//現在の撃破数を描画


		ScreenFlip();


		if (CheckHitKey(KEY_INPUT_ESCAPE))break;												//ESCキーで終了
		if (BreakCount == 20)break;																//撃破数が20で終了
	}

	while (ProcessMessage() == 0) {

		if (CheckHitKey(KEY_INPUT_ESCAPE))break;												//ESCキーが押されていると実行しない

		ClearDrawScreen();																		//画面をクリア


		SetFontSize(100);																		//フォントサイズを設定


		DrawFormatString(230, 300, GetColor(255, 255, 255), "CLEAR");							//クリアを描画

		if (CheckHitKey(KEY_INPUT_ESCAPE))break;												//ESCキーで終了		
	}


	for (int i = 0; i < 4; i++) {

		meteo[i].Delete();																		//隕石の画像データをメモリから解放

	}

	WaitKey();																					// キー入力待ち

	DxLib_End();																				// ＤＸライブラリ使用の終了処理

	return 0;																					// ソフトの終了 
}
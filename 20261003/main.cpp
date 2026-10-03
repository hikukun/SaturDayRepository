#include"Dxlib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	ChangeWindowMode(TRUE);
	SetGraphMode(640, 480, 32);
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	SetDrawScreen(DX_SCREEN_BACK);

	bool gameOver = false;

	//プレイヤー
	int playerx = 300;
	int playery = 420;
	//敵
	int enemyx = 300;
	int enemyy = 0;
	//色
	int white = GetColor(255, 255, 255);
	int blue = GetColor(0, 100, 255);
	int red = GetColor(255, 50, 50);
	//ヒットカウント
	int hitcount = 0;
	if (!gameOver)
	{
		//ゲームループ
		while (ProcessMessage() == 0)
		{
			//画面をクリア
			ClearDrawScreen();

			//左キーを押したら左へ移動
			if (CheckHitKey(KEY_INPUT_LEFT))
			{
				playerx -= 5;
			}
			//右キーを押したら右へ移動
			if (CheckHitKey(KEY_INPUT_RIGHT))
			{
				playerx += 5;
			}
			//上キーを押したらetc
			if (CheckHitKey(KEY_INPUT_UP))
			{
				playery -= 5;
			}
			if (CheckHitKey(KEY_INPUT_DOWN))
			{
				playery += 5;
			}

			//敵を落とす
			enemyy += 3;

			//画面下まで来たら上に戻す
			if (enemyy > 480)
			{
				enemyy = 0;
				enemyx = GetRand(600);
			}

			//プレイヤー
			DrawBox(playerx, playery, playerx + 40, playery + 40, blue, TRUE);

			//敵
			DrawBox(enemyx, enemyy, enemyx + 30, enemyy + 30, red, TRUE);

			if (playery < enemyy + 30 && playerx == enemyx + 30 && playery + 40>enemyy && playerx + 40 && enemyx)
			{
				gameOver = true;
				hitcount++;
			}

			DrawFormatString(10,40,white,"SCORE: % d", hitcount)

			//がめんをこうしん
			ScreenFlip();
		}
	}
	if(hitcount==5)
	{
		
		DrawString(250, 220, "GAMEOVER", white);
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			//DXライブラリの終了処理
			DxLib_End();
		}
	}

	return 0;
}
#include"Dxlib.h"
#include"Config.h"
#include"Map.h"

int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hprevInstance, LPSTR lpCmdLInce, int nCmdShow)
{
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1)return -1;
	SetDrawScreen(DX_SCREEN_BACK);
	//マップを管理するオブジェクト
	Map map;

	//マップが読み込めなかったら
	if (!map.Init())
	{
		map.Finalize();
		DxLib_End();
		return 0-1;
	}
	//ゲームループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE))
	{
		ClearDrawScreen();
		//マップの描画
		map.Draw();

		ScreenFlip();
	}

	map.Finalize();
	DxLib_End();

	return 0;

}
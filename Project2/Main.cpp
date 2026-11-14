#include"Dxlib.h"
#include "Game.h"
#include "Config.h"
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{

	ChangeWindowMode(TRUE);
	SetGraphMode(Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT, 32);

	if (DxLib_Init() == -1)
	{
		return -1;
	}

	SetDrawScreen(DX_SCREEN_BACK);

	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);

	Game game;

	game.Init();

	int previousTime = GetNowCount();

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		int currentTime = GetNowCount();

		float deltaTime = (currentTime - previousTime) / 1000.0f;

		previousTime = currentTime;

		if (deltaTime > 0.1f) { deltaTime = 0.1f; }

		ClearDrawScreen();
		game.Update(deltaTime);
		game.Draw();

		ScreenFlip();

	}

	DxLib_End();

	return 0;
}
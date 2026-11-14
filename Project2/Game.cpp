#include "Game.h"
#include "Config.h"
#include "Dxlib.h"

void Game::Init()
{
	circle.Init();
	sphere.Init();

	//3Dカメラ設定
	SetCameraNearFar(Config::CAMERA_NEAR, Config::CAMERA_FAR);

	//透視投影の設定（視野角60度）
	SetupCamera_Perspective(Config::PI / 30.0f);

	//カメラの位置と注視点
	VECTOR cameraPosition = VGet(0.0f, 0.0f, Config::CAMERA_Z);

	VECTOR cameraTarget = VGet(0.0f, 0.0f, Config::CAMERA_TARGET_Z);

	SetCameraPositionAndTarget_UpVecY(cameraPosition, cameraTarget);

}

void Game::Update(float deltaTime)
{
	circle.Update(deltaTime);
	sphere.Update(deltaTime);
}

void Game::Draw()
{
	//2Dの円を描画
	circle.Draw();
	//3Dの球を描画
	sphere.Draw();
}

void Game::Reset()
{
	circle.Reset();
	sphere.Reset();
}
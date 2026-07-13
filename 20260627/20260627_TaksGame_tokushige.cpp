#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    // DXライブラリ初期化
    ChangeWindowMode(TRUE);
    DxLib_Init();
    SetDrawScreen(DX_SCREEN_BACK);

    // 画像読み込み
    int red = LoadGraph("red.png");
    int yellow = LoadGraph("yellow.png");
    int green = LoadGraph("green.png");

    // ゲームの状態
    int scene = 0;
    // 0:赤 1:黄色 2:青 

    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        ClearDrawScreen();

        switch (scene)
        {
        case 0:
            DrawGraph(0, 0, red, TRUE);
            DrawString(180, 430, "SPACEで次", GetColor(255, 255, 255));

            if (CheckHitKey(KEY_INPUT_SPACE))
            {
                scene = 1;
                while (CheckHitKey(KEY_INPUT_SPACE)); // 押しっぱなし防止
            }
            break;

        case 1:
            DrawGraph(0, 0, yellow, TRUE);
            DrawString(180, 430, "SPACEで次", GetColor(255, 255, 255));

            if (CheckHitKey(KEY_INPUT_SPACE))
            {
                scene = 2;
                while (CheckHitKey(KEY_INPUT_SPACE));
            }
            break;

        case 2:
            DrawGraph(0, 0, green, TRUE);
            DrawString(150, 430, "ESCキーで終了", GetColor(255, 255, 255));
            break;
        }
       
        ScreenFlip();
    }

    // 終了処理
    DeleteGraph(red);
    DeleteGraph(yellow);
    DeleteGraph(green);

    DxLib_End();

    return 0;
}
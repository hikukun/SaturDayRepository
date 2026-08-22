#include "Map.h"
#include "Collision.h"
#include "DxLib.h"


//=======================
//コントラクタ
//=======================

Map::Map()
{
	for (int i = 0; i < Config::Map_IMG_X_NUM * Config::Map_IMG_Y_NUM; i++)
	{
		mapChipImg[i] = -1;
	}
}
//========================
//デストラクタ
//========================

Map::~Map()
{
	for (int i = 0; i < Config::MAP_IMG_X_NUM * Config::MAP_IMG_Y_NNUM; i++)
	{
		if (mapChipImg[i] != -1)
		{
			DeleteGraph(mapChipImg[i]);
			mapChipImg[i] = -1;
		}
	}
}

//=============
//初期化
//=============

bool Map::Init()
{
	int result = LoadDivGraph(
		Config::MAP_IMAGE_PATH,
		Config::MAP_IMG_X_NUM * Config::MAP_IMG_Y_NUM,
		Config::MAP_IMG_X_NUM, Config::MAP_IMG_Y_NUM,
		Config::MAP_CHIP_SIZE, Config::MAP_CHIP_SIZE,
		mapChipImg
	);
	return result == 0;
}

//=======================
//描画
//=======================

void Map::Draw()
{
	for (int y = 0; y < Config::MAP_Y_NUM; y++)
	{
		for
	}
}

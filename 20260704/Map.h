#pragma once
class Map
{
private:
	// The xposition of the object in the world
	float worldX;
	float worldY;
public:
	//======================================
	//コントラクタ
	//======================================
	Map(float worldX, float worldY);
	//======================================
	//描画
	//======================================
	void Draw(float cameraX);
};


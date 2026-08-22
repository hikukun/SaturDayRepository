#pragma once
#include"player.h"
#include"Map.h"

class Game
{
private:

	Player player;
	Map map;

	int nowCount;
	int prevCount;


public:

	Game();
	~Game();
	bool Init();
	void Run();

private:

	void Update(float deltaTime);

	void Draw();
};


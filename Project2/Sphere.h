#pragma once
class Sphere
{
private:
	float x;
	float y;
	float z;

public:

	void Init();

	void Update(float deltaTime);

	void Draw()const;

	void Reset();
};


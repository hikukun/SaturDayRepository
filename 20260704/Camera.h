#pragma once
class Camera
{
private:
	// The xposition of the camera
	float x;
public:

	Camera();

	void Update();

	float GetX() const;
};


#pragma once
class Camera
{
public:
	Camera() {};
	~Camera() {};
	void SetCamPos(float cx, float cy) { x = cx; y = cy; };
	void GetCamPos(float& cx, float& cy) { cx = x; cy = y; };
private:
	float x;
	float y;
};
#pragma once
#include "GameObject.h"

#include "Animation.h"
#include "Animations.h"

#define SOLDIER_WALKING_SPEED		0.1f

#define SOLDIER_STATE_IDLE					0
#define SOLDIER_STATE_WALKING_RIGHT			100
#define SOLDIER_STATE_WALKING_LEFT			200


#pragma region ANIMATION_ID

#define ID_ANI_SOLDIER_IDLE_RIGHT 2000
#define ID_ANI_SOLDIER_IDLE_LEFT 2001

#define ID_ANI_SOLDIER_WALKING_RIGHT 2100
#define ID_ANI_SOLDIER_WALKING_LEFT 2101

class CSoldier : public CGameObject
{
public:
	CSoldier(float x, float y) : CGameObject(x, y)
	{
		state = SOLDIER_STATE_WALKING_RIGHT;
		nx = 1;
		vx = SOLDIER_WALKING_SPEED;
	}
	void RequestState(int state);
	void GetPos(float& x, float& y) { x = this->x; y = this->y; }
private:
	void Update(DWORD dt);
	void Render();
};
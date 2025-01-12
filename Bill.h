#pragma once
#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define BILL_WALKING_SPEED		0.1f

#define BILL_STATE_IDLE					0
#define BILL_STATE_WALKING_RIGHT		100
#define BILL_STATE_WALKING_LEFT			200
#define BILL_STATE_LOOKING_UP			300
#define BILL_STATE_LYING_DOWN			400
#define BILL_STATE_WALKING_LOOK_UP		500
#define BILL_STATE_WALKING_LOOK_DOWN	600


#pragma region ANIMATION_ID

#define ID_ANI_BILL_IDLE_RIGHT 1000
#define ID_ANI_BILL_IDLE_LEFT 1001

#define ID_ANI_BILL_WALKING_RIGHT 1100
#define ID_ANI_BILL_WALKING_LEFT 1101
#define ID_ANI_BILL_LOOKING_UP_RIGHT 1102
#define ID_ANI_BILL_LOOKING_UP_LEFT 1103
#define ID_ANI_BILL_LYING_DOWN_RIGHT 1104
#define ID_ANI_BILL_LYING_DOWN_LEFT	 1105
#define ID_ANI_BILL_WALKING_LOOKING_UP_RIGHT 1106
#define ID_ANI_BILL_WALKING_LOOKING_UP_LEFT 1107
#define ID_ANI_BILL_WALKING_LOOKING_DOWN_RIGHT 1108
#define ID_ANI_BILL_WALKING_LOOKING_DOWN_LEFT 1109

class CBill : public CGameObject
{
public:
	CBill(float x, float y) : CGameObject(x, y)
	{
		ny = 0;
	}
	void RequestState(int state);
	void GetPos(float& x, float& y) { x = this->x; y = this->y; }
	bool fireIsletGo = true;
	void Fire();
private:
	void Update(DWORD dt);
	void Render();
};
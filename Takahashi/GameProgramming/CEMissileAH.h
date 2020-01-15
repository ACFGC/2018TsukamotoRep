#ifndef CEMISSILEAH
#define CEMISSILEAH

#include "CCharacter.h"
#include "CBox.h"
#include "CCollider.h"

class CEMissileAH : public CCharacter {
public:
	//éûä‘
	int ETime = 30 * 60;
	//ë∂ç›éûä‘
	int mELife;
	CCollider mCollider;
	CEMissileAH(CModel *model, float px, float py, float pz, float rx, float ry, float rz, float sx, float sy, float sz);
	void Update();
	void Collision(CCollider *m, CCollider *y);
};

#endif

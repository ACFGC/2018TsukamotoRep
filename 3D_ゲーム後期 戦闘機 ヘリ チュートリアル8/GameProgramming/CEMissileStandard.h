#ifndef CEMISSILESTANDARD
#define CEMISSILESTANDARD

#include "CCharacter.h"
#include "CBox.h"
#include "CCollider.h"

class CEMissileStandard : public CCharacter {
public:
	//時間
	int ETime = 30 * 60;
	//存在時間
	int mELife;
	CCollider mCollider;
	CEMissileStandard(CModel *model, float px, float py, float pz, float rx, float ry, float rz, float sx, float sy, float sz);
	void Update();
	void Collision(CCollider *m, CCollider *y);
};

#endif

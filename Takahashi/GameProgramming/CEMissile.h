#ifndef CEMISSILE
#define CEMISSILE

#include "CCharacter.h"
#include "CBox.h"
#include "CCollider.h"

class CEMissile : public CCharacter {
public:
	//時間
	int ETime = 30 * 60;
	//存在時間
	int mELife;
	CCollider mCollider;
	CEMissile(CModel *model, float px, float py, float pz, float rx, float ry, float rz, float sx, float sy, float sz);
	void Update();
	void Collision(CCollider *m, CCollider *y);
};

#endif

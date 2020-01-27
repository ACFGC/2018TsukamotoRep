#ifndef CMISSILESTANDARD
#define CMISSILESTANDARD

#include "CCharacter.h"
#include "CBox.h"
#include "CCollider.h"

class CMissileStandard : public CCharacter {
public:
	//ŽžŠÔ
	int Time = 30 * 60;
	int mLife;
	CCollider mCollider;
	CModel mAAM;
	CMissileStandard(CModel *model, float px, float py, float pz, float rx, float ry, float rz, float sx, float sy, float sz);
	void Update();
	void Collision(CCollider *m, CCollider *y);
};

#endif

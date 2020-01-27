#ifndef CENEMYSTANDARD
#define CENEMYSTANDARD

#include "CCharacter.h"
#include "CCollider.h"
#include"CTask.h"
class CEnemyStandard : public CCharacter {
public:
	CCollider mCollider;
	//時間
	int EATime = 100 * 60;
	CEnemyStandard(CModel *model, float px, float py, float pz, float rx, float ry, float rz, float sx, float sy, float sz);
	//ミサイルクールタイム
	int mEMissileInterval;
	//フレアクールタイム
	int mEFlareInterval;
	//体力
	//float HP;
	void Update();
	void Collision(CCollider *m, CCollider *y);
};


#endif

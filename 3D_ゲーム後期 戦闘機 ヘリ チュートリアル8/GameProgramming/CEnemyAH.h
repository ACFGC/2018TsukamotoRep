#ifndef CENEMYAH
#define CENEMYAH

#include "CCharacter.h"
#include "CCollider.h"
#include"CTask.h"
class CEnemyAH : public CCharacter {
public:
	int EATime = 100 * 60;
	CCollider mCollider;
	CEnemyAH(CModel *model, float px, float py, float pz, float rx, float ry, float rz, float sx, float sy, float sz);
	//ミサイルクールタイム
	int mEMissileInterval;
	//フレアクールタイム
	int mEFlareInterval;
	void Update();
	void Collision(CCollider *m, CCollider *y);
};


#endif

#ifndef CEMISSILEAH
#define CEMISSILEAH

#include "CCharacter.h"
#include "CBox.h"
#include "CCollider.h"

class CEMissileAH : public CCharacter {
public:
	//����
	int ETime = 30 * 60;
	//���ݎ���
	int mELife;
	CCollider mCollider;
	CEMissileAH(CModel *model, float px, float py, float pz, float rx, float ry, float rz, float sx, float sy, float sz);
	void Update();
	void Collision(CCollider *m, CCollider *y);
};

#endif

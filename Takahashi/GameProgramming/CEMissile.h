#ifndef CEMISSILE
#define CEMISSILE

#include "CCharacter.h"
#include "CBox.h"
#include "CCollider.h"

class CEMissile : public CCharacter {
public:
	//����
	int ETime = 30 * 60;
	//���ݎ���
	int mELife;
	CCollider mCollider;
	CEMissile(CModel *model, float px, float py, float pz, float rx, float ry, float rz, float sx, float sy, float sz);
	void Update();
	void Collision(CCollider *m, CCollider *y);
};

#endif

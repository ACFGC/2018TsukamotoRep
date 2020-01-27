#ifndef CENEMYSTANDARD
#define CENEMYSTANDARD

#include "CCharacter.h"
#include "CCollider.h"
#include"CTask.h"
class CEnemyStandard : public CCharacter {
public:
	CCollider mCollider;
	//����
	int EATime = 100 * 60;
	CEnemyStandard(CModel *model, float px, float py, float pz, float rx, float ry, float rz, float sx, float sy, float sz);
	//�~�T�C���N�[���^�C��
	int mEMissileInterval;
	//�t���A�N�[���^�C��
	int mEFlareInterval;
	//�̗�
	//float HP;
	void Update();
	void Collision(CCollider *m, CCollider *y);
};


#endif

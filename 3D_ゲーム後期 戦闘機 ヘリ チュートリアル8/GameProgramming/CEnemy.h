#ifndef CENEMY
#define CENEMY

#include "CCharacter.h"
#include "CCollider.h"
#include"CTask.h"
class CEnemy : public CCharacter {
public:
	CCollider mCollider;

	CEnemy(CModel *model, float px, float py, float pz, float rx, float ry, float rz, float sx, float sy, float sz);
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

#ifndef CPLAYERAH
#define CPLAYERAH

#include"CCharacter.h"
#include"CCollider.h"
#include"CModel.h"
#include"CMissileAH.h"
class CPlayerAH : public CCharacter {
public:
	static CPlayerAH *mpPlayerAH;
	CPlayerAH();
	~CPlayerAH();
	//�~�T�C���N�[���^�C��
	int mMissileInterval;
	//�t���A�N�[���^�C��
	int mFlareInterval;
	//�����蔻��
	CCollider mPCollider;
	void Update();
	void  Collision(CCollider *m, CCollider *y);
};

#endif

#ifndef CPLAYERSTANDARD
#define CPLAYERSTANDARD

#include "CCharacter.h"
#include "CCollider.h"
#include"CModel.h"
#include"CHpBar.h"
#include"CRadar.h"
class CPlayerStandard : public CCharacter {
public:
	static CPlayerStandard *mPlayerStandard;
	CPlayerStandard();
	~CPlayerStandard();
	//�~�T�C���N�[���^�C��
	int mMissileInterval;
	//�t���A�N�[���^�C��
	int mFlareInterval;
	//�����蔻��
	CCollider mPCollider;
	//���[�_�[
	CRadar mRadar;
	void Update();
	void Render();
	void  Collision(CCollider *m, CCollider *y);
};

#endif

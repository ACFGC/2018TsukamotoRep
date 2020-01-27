#ifndef CPLAYER
#define CPLAYER

#include "CCharacter.h"
#include "CCollider.h"
#include"CModel.h"
#include"CMissile.h"
#include"CHpBar.h"
#include"CRadar.h"
class CPlayer : public CCharacter {
public:
	static CPlayer *mpPlayer;
	CPlayer();
	~CPlayer();
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

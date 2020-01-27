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
	//ミサイルクールタイム
	int mMissileInterval;
	//フレアクールタイム
	int mFlareInterval;
	//当たり判定
	CCollider mPCollider;
	//レーダー
	CRadar mRadar;
	void Update();
	void Render();
	void  Collision(CCollider *m, CCollider *y);
};

#endif

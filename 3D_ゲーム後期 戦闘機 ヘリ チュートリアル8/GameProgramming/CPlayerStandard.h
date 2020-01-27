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

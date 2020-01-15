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
	//ミサイルクールタイム
	int mMissileInterval;
	//フレアクールタイム
	int mFlareInterval;
	//当たり判定
	CCollider mPCollider;
	void Update();
	void  Collision(CCollider *m, CCollider *y);
};

#endif

#ifndef CMISSILE
#define CMISSILE

#include "CCharacter.h"
#include "CBox.h"
#include "CCollider.h"
#include"CEnemy.h"
//“G‚ÌŠO•”•Ï”‚ğŒÄ‚Ô
extern CEnemy*Enemy;
class CMissile : public CCharacter {
public:
	int mLife;
	CCollider mCollider;
	CModel mAAM;
	CEnemy*tenemy;
	CMissile(CModel *model, float px, float py, float pz, float rx, float ry, float rz, float sx, float sy, float sz);
	void Update();
	void Collision(CCollider *m, CCollider *y);
};

#endif

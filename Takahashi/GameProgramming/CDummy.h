#ifndef CDUMMY
#define CDUMMY

#include "CCharacter.h"
#include "CCollider.h"
#include"CTask.h"
class CDummy : public CCharacter {
public:
	CCollider mCollider;
	CDummy(CModel *model, float px, float py, float pz, float rx, float ry, float rz, float sx, float sy, float sz);
	void Update();
	void Collision(CCollider *m, CCollider *y);
};


#endif

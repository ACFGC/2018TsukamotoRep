#ifndef CSPHERECOLLIDER_H
#define CSPHERECOLLIDER_H
#include"CCollider.h"
class CCharacter;
class CSphereCollider :public CCollider{
public:
	CTask*mpTask;
	CVector mPosition;
	CVector mAdjust;
	CCollider*mpNext;
	float mRadius;
	static bool Collision(CSphereCollider *, CSphereCollider *);
};
#endif
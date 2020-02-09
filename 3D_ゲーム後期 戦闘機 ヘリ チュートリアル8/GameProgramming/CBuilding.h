#ifndef CBUILDING_H
#define CBUILDING_H

#include "CCharacter.h"
#include "CBox.h"
#include "CCollider.h"

class CBuilding : public CCharacter {
public:
	CTriangle mT[2];
	CBox mBox;
	int mFLife;
	CCollider mCollider;

	CBuilding();
	void Set(float x, float y, float z, float w, float h, float d);
	void SetDiffuse(float r, float g, float b, float a);
	void Update();
	void Render();
	void Collision(CCollider *m, CCollider *y);
};

#endif

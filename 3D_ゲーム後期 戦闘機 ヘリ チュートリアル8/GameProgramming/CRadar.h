#ifndef CRADAR_H
#define CRADAR_H
#include"CCollider.h"
#include"CCharacter.h"
#include"CBox.h"
#include"CSphereCollider.h"
#include "CEnemy.h"

class CRadar :public CCharacter{
public:
	CTriangle mT[2];
	CBox mBox;
	CCollider mCollider;
	static CEnemy *mptarget;
	CRadar();
	void Set(float x, float y, float z, float w, float h, float d);
	void SetDiffuse(float r, float g, float b, float a);
	void Update();
	void Render();
	void Collision(CCollider *m, CCollider *y);
};
#endif
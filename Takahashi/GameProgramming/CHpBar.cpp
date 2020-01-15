#include "CHpBar.h"
#include"CEnemy.h"
/*
#define LIFE 150
void CHpBar::SetHpBar(CCharacter*task,
	const CVector&pos, const CVector &size,
	float max, float hp){
	//SetVertex(0.0f, size.x, 0.0f, size.y);
	mPosition.mX = pos.mX + -size.mX / 2.0f;
	mPosition.mY = pos.mY;
	mPosition.mZ = pos.mZ;
	mMax = max;
	mHp = hp;
	//mBar.SetVertex(0.0f, size.x, 0.0f, size.y);
	mBar.mScale.mX = mHp / mMax;
	mpTask = task;
}
void CHpBar::SetDiffuse(float r, float g, float b, float a) {
	mBox.mMaterial.mDiffuse[0] = r;
	mBox.mMaterial.mDiffuse[1] = g;
	mBox.mMaterial.mDiffuse[2] = b;
	mBox.mMaterial.mDiffuse[3] = a;
}
void CHpBar::Update(){
	CCharacter::Update();
	mBar.mScale.mX = mHp / mMax;
	mBar.Update();
	CMatrix matrix;
	matrix.Translate(mpTask->mPosition.mX,
		mpTask->mPosition.mY,mpTask->mPosition.mZ);
	mMatrix = matrix*mMatrix;
	mBar.mMatrix = mMatrix*mBar.mMatrix;
	if (mHp <= 0.0f){
		mEnabled = false;
	}
}
void CHpBar::Render(){
	float c[] = { 1.0f, 1.0f, 0.0f, 1.0f };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, c);

	mT[0].Render(mMatrix);
	mT[1].Render(mMatrix);
	//mBox.Render(mMatrix);
	//CCharacter::Render();
	//mBar.Render();
}*/
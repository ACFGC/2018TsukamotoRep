#include "CFire.h"
#include "CPlayer.h"
#include"CPlayerAH.h"
#define LIFE 10

void CFire::SetSize(float w, float h) {
	mT[0].SetVertex(-w, -h, 0.0f, w, -h, 0.0f, w, h, 0.0f);
	mT[1].SetVertex(-w, -h, 0.0f, w, h, 0.0f, -w, h, 0.0f);
	mT[0].SetNormal(0.0f, 0.0f, 1.0f);
	mT[1].SetNormal(0.0f, 0.0f, 1.0f);
	//mT[0].SetVertex(0.0f, -h, -w, 0.0f, -h, w, 0.0f, h, w);
	//mT[1].SetVertex(0.0f, -h, -w, 0.0f, h, w, 0.0f, h, -w);
	//mT[0].SetNormal(-1.0f, 0.0f, 0.0f);
	//mT[1].SetNormal(-1.0f, 0.0f, 0.0f);
	//mTaskTag = EPLAYERBULLET;
}

void CFire::Update() {
	if (mLife > 0) {
		mLife--;
	}
	else {
		mEnabled = false;
	}
	if (CPlayer::mpPlayer) {
		CVector dir = CPlayer::mpPlayer->mPosition + mPosition * -1;
		mRotation.mY = atan2f(dir.mX, dir.mZ) / 2.0f / 3.14f * 360.0f;
		mRotation.mX = -atan2f(dir.mY, dir.mZ) / 2.0f / 3.14f * 360.0f;
		if (mRotation.mX > 90.0f) {
			mRotation.mX = 90.0f - (mRotation.mX - 90.0f);
		}
		else if (mRotation.mX < -90.0f) {
			mRotation.mX = -90.0f - (mRotation.mX + 90.0f);
		}
	}
	if (CPlayerAH::mpPlayerAH) {
		CVector dir = CPlayerAH::mpPlayerAH->mPosition + mPosition * -1;
		mRotation.mY = atan2f(dir.mX, dir.mZ) / 2.0f / 3.14f * 360.0f;
		mRotation.mX = -atan2f(dir.mY, dir.mZ) / 2.0f / 3.14f * 360.0f;
		if (mRotation.mX > 90.0f) {
			mRotation.mX = 90.0f - (mRotation.mX - 90.0f);
		}
		else if (mRotation.mX < -90.0f) {
			mRotation.mX = -90.0f - (mRotation.mX + 90.0f);
		}
	}
	CCharacter::Update();
}

void CFire::Render() {
	mMaterial.SetMaterial();
	mT[0].Render(mMatrix);
	mT[1].Render(mMatrix);
	mMaterial.UnSetMaterial();
}

void CFire::SetTexture(char *tga) {
	mMaterial.mTexture.Load(tga);

	mT[0].mUv[0].mX = 0.0f;
	mT[0].mUv[0].mY = 0.0f;
	mT[0].mUv[1].mX = 1.0f;
	mT[0].mUv[1].mY = 0.0f;
	mT[0].mUv[2].mX = 1.0f;
	mT[0].mUv[2].mY = 1.0f;

	mT[1].mUv[0].mX = 0.0f;
	mT[1].mUv[0].mY = 0.0f;
	mT[1].mUv[1].mX = 1.0f;
	mT[1].mUv[1].mY = 1.0f;
	mT[1].mUv[2].mX = 0.0f;
	mT[1].mUv[2].mY = 1.0f;
}

void CFire::SetDiffuse(float r, float g, float b, float a) {
	mMaterial.mDiffuse[0] = r;
	mMaterial.mDiffuse[1] = g;
	mMaterial.mDiffuse[2] = b;
	mMaterial.mDiffuse[3] = a;
}

CFire::CFire()
	: mLife(LIFE)
{
	SetSize(1.0f, 1.0f);
	SetDiffuse(1.0f, 1.0f, 1.0f, 1.0);
	Update();
}

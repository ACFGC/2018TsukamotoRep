#include "CBullet.h"
#include"CEnemy.h"

#define LIFE 150

CBullet::CBullet()
: mLife(LIFE)
{
	mCollider.mRadius = 1.0f;
	mCollider.mpParent = this;
	//タグ設定
	mTaskTag = EPLAYERBULLET;
}

void CBullet::Set(float x, float y, float z, float w, float h, float d) {
	mT[0].mV[0] = CVector(x + w, y, z + d);
	mT[0].mV[1] = CVector(x + w, y, z - d);
	mT[0].mV[2] = CVector(x - w, y, z - d);
	mT[0].SetNormal(0.0f, 1.0f, 0.0f);
	mT[1].mV[0] = CVector(x + w, y, z + d);
	mT[1].mV[1] = CVector(x - w, y, z - d);
	mT[1].mV[2] = CVector(x - w, y, z + d);
	mT[1].SetNormal(0.0f, 1.0f, 0.0f);
	mBox.Set(x, y, z, w, h, d);
	mCollider.mRadius = d;
	mCollider.mV[0] = CVector(0.0f, 0.0f, 0.0f);
}

void CBullet::SetDiffuse(float r, float g, float b, float a) {
	mBox.mMaterial.mDiffuse[0] = r;
	mBox.mMaterial.mDiffuse[1] = g;
	mBox.mMaterial.mDiffuse[2] = b;
	mBox.mMaterial.mDiffuse[3] = a;
}

void CBullet::Update() {
	if (mLife > 0) {
		mLife--;
//		CCharacter::Update();
		//行列更新
		mMatrix = mMatrix.Scale(mScale.mX, mScale.mY, mScale.mZ) * mMatrixRotation *
			mMatrix.Translate(mPosition.mX, mPosition.mY, mPosition.mZ);
		mPosition = mPosition + CVector(0.0f, 0.0f, 2.0f) * mMatrixRotation;
	}
	else {
		mEnabled = false;
	}
}

void CBullet::Render() {
	float c[] = { 1.0f, 1.0f, 0.0f, 1.0f };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, c);

	mT[0].Render(mMatrix);
	mT[1].Render(mMatrix);
	//mBox.Render(mMatrix);
}
void CBullet::Collision(CCollider *m, CCollider *y) {
		/*switch (y->mpParent->mTaskTag){
		case EENEMY:
			y->mpParent->mEnabled = false;
			m->mEnabled = false;
			break;
	    }*/
}

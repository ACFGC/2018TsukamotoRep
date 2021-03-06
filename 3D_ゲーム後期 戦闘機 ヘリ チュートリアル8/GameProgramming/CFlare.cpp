#include"CFlare.h"
#include"CFire.h"
#include"CSceneGameF22.h"
#define LIFE 300

CFlare::CFlare()
: mFLife(LIFE)
{
	mCollider.mpParent = this;
	mCollider.mRadius = 100.0f;
}

void CFlare::Set(float x, float y, float z, float w, float h, float d) {
	mT[0].SetVertex(x - w, y - h, z + d, x + w, y - h, z + d, x + w, y + h, z + d);
	mT[0].SetNormal(0.0f, 0.0f, 1.0f);
	mT[1].SetVertex(x - w, y - h, z + d, x + w, y + h, z + d, x - w, y + h, z + d);
	mT[1].SetNormal(0.0f, 0.0f, 1.0f);

	mT[2].SetVertex(x + w, y - h, z + d, x + w, y - h, z - d, x + w, y + h, z - d);
	mT[2].SetNormal(1.0f, 0.0f, 0.0f);
	mT[3].SetVertex(x + w, y - h, z + d, x + w, y + h, z - d, x + w, y + h, z + d);
	mT[3].SetNormal(1.0f, 0.0f, 0.0f);

	mT[4].SetVertex(x - w, y - h, z - d, x + w, y + h, z - d, x + w, y - h, z - d);
	mT[4].SetNormal(0.0f, 0.0f, -1.0f);
	mT[5].SetVertex(x - w, y - h, z - d, x - w, y + h, z - d, x + w, y + h, z - d);
	mT[5].SetNormal(0.0f, 0.0f, -1.0f);

	mT[6].SetVertex(x - w, y - h, z + d, x - w, y + h, z - d, x - w, y - h, z - d);
	mT[6].SetNormal(-1.0f, 0.0f, 0.0f);
	mT[7].SetVertex(x - w, y - h, z + d, x - w, y + h, z + d, x - w, y + h, z - d);
	mT[7].SetNormal(-1.0f, 0.0f, 0.0f);

	mT[8].SetVertex(x - w, y + h, z + d, x + w, y + h, z + d, x + w, y + h, z - d);
	mT[8].SetNormal(0.0f, 1.0f, 0.0f);
	mT[9].SetVertex(x - w, y + h, z + d, x + w, y + h, z - d, x - w, y + h, z - d);
	mT[9].SetNormal(0.0f, 1.0f, 0.0f);

	mT[10].SetVertex(x - w, y - h, z + d, x + w, y - h, z - d, x + w, y - h, z + d);
	mT[10].SetNormal(0.0f, -1.0f, 0.0f);
	mT[11].SetVertex(x - w, y - h, z + d, x - w, y - h, z - d, x + w, y - h, z - d);
	mT[11].SetNormal(0.0f, -1.0f, 0.0f);
	/*mT[0].mV[0] = CVector(x + w, y, z + d);
	mT[0].mV[1] = CVector(x + w, y, z - d);
	mT[0].mV[2] = CVector(x - w, y, z - d);
	mT[0].SetNormal(0.0f, 1.0f, 0.0f);
	mT[1].mV[0] = CVector(x + w, y, z + d);
	mT[1].mV[1] = CVector(x - w, y, z - d);
	mT[1].mV[2] = CVector(x - w, y, z + d);
	mT[1].SetNormal(0.0f, 1.0f, 0.0f);*/
	mBox.Set(x, y, z, w, h, d);
	mCollider.mRadius = d;
	mCollider.mV[0] = CVector(0.0f, 0.0f, 0.0f);
}

void CFlare::SetDiffuse(float r, float g, float b, float a) {
	mBox.mMaterial.mDiffuse[0] = r;
	mBox.mMaterial.mDiffuse[1] = g;
	mBox.mMaterial.mDiffuse[2] = b;
	mBox.mMaterial.mDiffuse[3] = a;
}

void CFlare::Update() {
	if (mFLife > 0) {
		mFLife--;
		//行列更新
		mMatrix = mMatrix.Scale(mScale.mX, mScale.mY, mScale.mZ)*
			mMatrixRotation*mMatrix.Translate(mPosition.mX, mPosition.mY, mPosition.mZ);
		mPosition = mPosition - CVector(0.0f, 0.0f, 0.1f) * mMatrixRotation;
	}
	else {
		mEnabled = false;
	}
}

void CFlare::Render() {
	float c[] = { 1.0f, 1.0f, 0.0f, 1.0f };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, c);

	mT[0].Render(mMatrix);
	mT[1].Render(mMatrix);
	mT[2].Render(mMatrix);
	mT[3].Render(mMatrix);
	mT[4].Render(mMatrix);
	mT[5].Render(mMatrix);
	mT[6].Render(mMatrix);
	mT[7].Render(mMatrix);
	mT[8].Render(mMatrix);
	mT[9].Render(mMatrix);
	mT[10].Render(mMatrix);
	mT[11].Render(mMatrix);
	//mBox.Render(mMatrix);
}

void CFlare::Collision(CCollider *m, CCollider *y) {
	//当たったか判定
	if (CCollider::Collision(m, y)){
		switch (y->mpParent->mTaskTag){
		//当たった相手のタグがEENEMYBULLETなら
		case EENEMYBULLET:
			CFire *f = new CFire();
			f->mPosition = y->mpParent->mPosition;
			f->SetTexture("fire.tga");
			TaskManager.Add(f);
			//自分を消す
			m->mpParent->mEnabled = false;
			//当たった相手を消す
			y->mpParent->mEnabled = false;
			break;
		}
	}
}
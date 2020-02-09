#include"CBuilding.h"
#include"CFire.h"
#include"CSceneGameF22.h"
//ファイアの外部変数を呼ぶ
extern CFire *f;
CBuilding::CBuilding()
{
	mCollider.mpParent = this;
	mCollider.mRadius = 100.0f;
}

void CBuilding::Set(float x, float y, float z, float w, float h, float d) {
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

void CBuilding::SetDiffuse(float r, float g, float b, float a) {
	mBox.mMaterial.mDiffuse[0] = r;
	mBox.mMaterial.mDiffuse[1] = g;
	mBox.mMaterial.mDiffuse[2] = b;
	mBox.mMaterial.mDiffuse[3] = a;
}

void CBuilding::Update() {
	CCharacter::Update();
	//mPosition = mPosition + CVector(0.0f, 0.0f, 1.0f) * mMatrixRotation;
}

void CBuilding::Render() {
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

void CBuilding::Collision(CCollider *m, CCollider *y) {
	//当たったか判定
	if (CCollider::Collision(m, y)){
		switch (y->mpParent->mTaskTag){
		//当たった相手のタグがEENEMYBULLETなら
		case EENEMYBULLET:
			f = new CFire();
			f->mPosition = y->mpParent->mPosition;
			f->SetTexture("fire.tga");
			TaskManager.Add(f);
			//当たった相手を消す
			y->mpParent->mEnabled = false;
			break;
		//当たった相手のタグがEENEMYBULLETなら
		case EPLAYERBULLET:
			f = new CFire();
			f->mPosition = y->mpParent->mPosition;
			f->SetTexture("fire.tga");
			TaskManager.Add(f);
			//当たった相手を消す
			y->mpParent->mEnabled = false;
			break;
		}
	}
}
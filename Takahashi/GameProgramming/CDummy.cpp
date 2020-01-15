#include"CDummy.h"
#include"CFire.h"
#include"CSceneGameF22.h"
#include"CTaskManager.h"
CDummy::CDummy(CModel *model, float px, float py, float pz, float rx, float ry, float rz, float sx, float sy, float sz) {
	Init(model, px, py, pz, rx, ry, rz, sx, sy, sz);
	TaskManager.Add(this);
	mCollider.mpParent = this;
	mCollider.mRadius = 1.0f;
}

void CDummy::Update() {
	CCharacter::Update();
}

void CDummy::Collision(CCollider *m, CCollider *y) {
	if (CCollider::Collision(m, y)){
		switch (y->mpParent->mTaskTag){
		//EPLAYERBULLETなら
		case EPLAYERBULLET:
			CFire *f = new CFire();
			f->mPosition = y->mpParent->mPosition;
			f->SetTexture("fire.tga");
			TaskManager.Add(f);
			//m->mpParent->mEnabled = false;
			break;
		}
	}
}


//敵フレアクールタイム
/*if (mEFlareInterval>0){
mEFlareInterval--;
}
if (mEFlareInterval <= 0){
mEFlareInterval = EFLAREINTERVAL_E;
EFlare = new CFlare();
EFlare->Set(0.0f, 0.0f, -1.4f, 0.1f, 0.1f, 0.1f);
EFlare->SetDiffuse(1.0f, 1.0f, 0.0f, 1.0f);
EFlare->mPosition = mPosition;
EFlare->mRotation = mRotation;
TaskManager.Add(EFlare);
EFlare = new CFlare();
EFlare->Set(1.0f, 0.0f, -1.4f, 0.1f, 0.1f, 0.1f);
EFlare->SetDiffuse(1.0f, 1.0f, 0.0f, 1.0f);
EFlare->mPosition = mPosition;
EFlare->mRotation = mRotation;
TaskManager.Add(EFlare);
EFlare = new CFlare();
EFlare->Set(-1.0f, 0.0f, -1.4f, 0.1f, 0.1f, 0.1f);
EFlare->SetDiffuse(1.0f, 1.0f, 0.0f, 1.0f);
EFlare->mPosition = mPosition;
EFlare->mRotation = mRotation;
TaskManager.Add(EFlare);
}*/
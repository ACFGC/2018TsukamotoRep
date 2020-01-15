#include"CEnemy.h"
#include"CEMissile.h"
#include"CSceneGameF22.h"
#include"CFire.h"
#include"CFlare.h"
#include"CHpBar.h"
#define VELOCITY_ENEMY 0.3f
//ミサイルクールタイム
#define mEMissileINTERVAL_E 100
//フレアクールタイム
#define EFLAREINTERVAL_E 60
//フレアの外部変数を作る
CFlare*EFlare;
//敵ミサイルの外部変数を作る
CEMissile*em;
//敵ミサイル(モデル)の外部変数を作る
CModel mAAM;
//ファイアの外部変数を呼ぶ
extern CFire *f;
//時間
int EATime = 100 * 60;
//HPバーの外部変数を作る
CHpBar HP;
CEnemy::CEnemy(CModel *model, float px, float py, float pz, float rx, float ry, float rz, float sx, float sy, float sz) {
	Init(model, px, py, pz, rx, ry, rz, sx, sy, sz);
	TaskManager.Add(this);
	mCollider.mpParent = this;
	mCollider.mRadius = 5.0f;
	//フレアインターバル設定
	mEFlareInterval = EFLAREINTERVAL_E;
	//タグを設定
	mTaskTag = EENEMY;
	//体力を100に設定
	//HP = 100.0f;
	//HPバーの設定を呼ぶ
	HP.Init();
	//ミサイルのモデルを読み込む
	mAAM.Load("AAM.obj", "AAM.mtl");
}

void CEnemy::Update() {
	mPosition = mPosition + CVector(0.0f, 0.0f, VELOCITY_ENEMY) * mMatrixRotation;
	//敵座標
	CVector vPos = CVector(1.0f, 0.0f, 0.0f) * mMatrix - CVector(0.0f, 0.0f, 0.0f) * mMatrix;
	//方向ベクトル
	CVector vDir(10, 10, 10);
	//vPos = vPos.getRotationTowards(vDir);//ミサイル座標更新

	//プレイヤー座標
	CVector vTargetHPos = CPlayer::mpPlayer->mPosition - mPosition;
	//プレイヤー方向に追尾
	float HE = vPos.dot(vTargetHPos);
	//mRotation.mY += 0.5f;
	//追尾処理時間
	if (EATime > 0){
		EATime--;
	}
	if (EATime <= 80){
		//追尾処理
		if (HE > 0.0f){
			mRotation.mY += 1;
		}
		else if (HE < 0.0f){
			mRotation.mY -= 1;
		}
		//X方向へ追尾
		if (CPlayer::mpPlayer->mPosition.mX > CEnemy::mPosition.mX){
			mPosition.mX += 0.1;
		}
		if (CPlayer::mpPlayer->mPosition.mX < CEnemy::mPosition.mX){
			mPosition.mX -= 0.1;
		}
		//Y方向へ追尾
		if (CPlayer::mpPlayer->mPosition.mY > CEnemy::mPosition.mY){
			mPosition.mY += 0.1;
		}
		if (CPlayer::mpPlayer->mPosition.mY < CEnemy::mPosition.mY){
			mPosition.mY -= 0.1;
		}
		//Z方向へ追尾
		if (CPlayer::mpPlayer->mPosition.mZ > CEnemy::mPosition.mZ){
			mPosition.mZ += 0.1;
		}
		if (CPlayer::mpPlayer->mPosition.mZ < CEnemy::mPosition.mZ){
			mPosition.mZ -= 0.1;
		}
		if (CPlayer::mpPlayer->mRotation.mX > CEnemy::mRotation.mX){
			mRotation.mX += 0.1;
		}
		if (CPlayer::mpPlayer->mRotation.mX < CEnemy::mRotation.mX){
			mRotation.mX -= 0.1;
		}
	}
	if (EATime == 0){
		EATime = 100;
	}
	//ミサイルクールタイム
	if (mEMissileInterval>0){
	mEMissileInterval--;
	}
	if (mEMissileInterval <= 0){
		mEMissileInterval = mEMissileINTERVAL_E;
		em = new CEMissile(&mAAM, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f);
		//タグを設定
		em->mTaskTag = EENEMYBULLET;
		em->mPosition = mPosition;
		em->mRotation = mRotation;
		TaskManager.Add(em);
	}
	CCharacter::Update();
}

void CEnemy::Collision(CCollider *m, CCollider *y) {
	//当たったか判定
	if (CCollider::Collision(m, y)){
		switch (y->mpParent->mTaskTag){
		//当たった相手のタグがEPLAYERBULLETなら
		case EPLAYERBULLET:
			HP.HP -= 40.0f;
			if (HP.HP <= 0.0f){
				f = new CFire();
				f->mPosition = y->mpParent->mPosition;
				f->SetTexture("fire.tga");
				TaskManager.Add(f);
				//自分を消す
				m->mpParent->mEnabled = false;
				//当たった相手を消す
				//y->mpParent->mEnabled = false;
			}
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
#include"CPlayerAH.h"
#include"CKey.h"
#include"CBullet.h"
#include"CSceneGameAH.h"
#include"CMissileAH.h"
#include"CFlare.h"
#include"CFire.h"
//ミサイルクールタイム(時間)
#define FIREINTERVAL_E 100
//フレアクールタイム(時間)
#define FLAREINTERVAL_E 60

//ミサイルAHの外部変数を作る
CMissileAH *m;
//ミサイル(モデル)の外部変数を呼ぶ
extern CModel mAAM;
//ファイアの外部変数を呼ぶ
extern CFire *f;
//フレアの外部変数を呼ぶ
extern CFlare*Flare;

CPlayerAH *CPlayerAH::mpPlayerAH = 0;

CPlayerAH::CPlayerAH() {
	mpPlayerAH = this;
	mPCollider.mpParent = this;
	mPCollider.mRadius = 1.0f;
	//タグを決める
	mTaskTag = EPLAYER;
	//ミサイルのモデルを読み込む
	mAAM.Load("AAM.obj", "AAM.mtl");
}

CPlayerAH::~CPlayerAH() {
	mpPlayerAH = 0;
}

void CPlayerAH::Update() {
	//ヘリ操作処理
	//上に傾いた時上方向へ前進
	if (mRotation.mX <= 50){
		mPosition = mPosition + CVector(0.0f, 0.0f, 0.4f) * mMatrixRotation;
	}
	//下に傾いた時下方向へ前進
	if (mRotation.mX >= 50){
		mPosition = mPosition + CVector(0.0f, 0.0f, 0.2f) * mMatrixRotation;
	}
		//上昇
		if (GetKeyState('I') & 0x8000){
			mPosition.mY += 0.5;
		    //mainrotor.mRotation.y += 40;
		    //tellrotor.mRotation.x += 20;
		}
		//下降
		if (GetKeyState('K') & 0x8000){
			//mainrotor.mRotation.y += 80;
			//tellrotor.mRotation.x += 40;
			mPosition.mY -= 0.5;
		}
		//左回り
		if (GetKeyState('A') & 0x8000){
			mRotation.mY++;
		}
		//右回り
		if (GetKeyState('D') & 0x8000){
			mRotation.mY--;
		}
		//水平に戻す
		if (GetKeyState('Y') & 0x8000){
			mRotation.mX = 0;
		}
		//前進
		if (GetKeyState('W') & 0x8000){
			//mainrotor.mRotation.y += 40;
			//mPosition.mX++;
			mPosition = mPosition + CVector(0.0f, 0.0f, 0.4f) * mMatrixRotation;
			//mBox.Forward();
			//mBox.Forward();
			//mBox.Forward();
		}
		//前回り
		if (GetKeyState('W') & 0x8000){
			mRotation.mX += 1;
			if (mRotation.mX > 30){
				mRotation.mX = 30;
			}
		}
		//後進
		if (GetKeyState('S') & 0x8000){
			mPosition = mPosition - CVector(0.0f, 0.0f, 0.2f) * mMatrixRotation;
			//mPosition.mX--;
			//mainrotor.mRotation.y += 40;
			//mBox.Reverse();
			//mBox.Reverse();
		}
		//後ろ回り
		if (GetKeyState('S') & 0x8000){
			mRotation.mX -= 1;
			if (mRotation.mX < -30){
				mRotation.mX = -30;
			}
		}
		//傾いた時傾いた方向へ前進
		if (mRotation.mX >= 1){
			mPosition = mPosition + CVector(0.0f, 0.0f, 0.4f) * mMatrixRotation;
			if (mRotation.mX >= 10){
				mPosition = mPosition + CVector(0.0f, 0.0f, 0.5f) * mMatrixRotation;
				if (mRotation.mX >= 20){
					mPosition = mPosition + CVector(0.0f, 0.0f, 0.6f) * mMatrixRotation;
					if (mRotation.mX >= 30){
						mPosition = mPosition + CVector(0.0f, 0.0f, 0.7f) * mMatrixRotation;
					}
				}
			}
		}
		//傾いた時傾いた方向へ後進
		if (mRotation.mX <= -1){
			mPosition = mPosition - CVector(0.0f, 0.0f, 0.2f) * mMatrixRotation;
			if (mRotation.mX <= -10){
				mPosition = mPosition - CVector(0.0f, 0.0f, 0.3f) * mMatrixRotation;
				if (mRotation.mX <= -20){
					mPosition = mPosition - CVector(0.0f, 0.0f, 0.4f) * mMatrixRotation;
					if (mRotation.mX <= -30){
						mPosition = mPosition - CVector(0.0f, 0.0f, 0.5f) * mMatrixRotation;
					}
				}
			}
		}
		else{
			if (mRotation.mX <= 0){
				mPosition = mPosition + CVector(0.0f, 0.0f, 0.2f) * mMatrixRotation;
				mPosition = mPosition - CVector(0.0f, 0.0f, 0.2f) * mMatrixRotation;
			}
			if (mRotation.mX >= 0){
				mPosition = mPosition + CVector(0.0f, 0.0f, 0.2f) * mMatrixRotation;
				mPosition = mPosition - CVector(0.0f, 0.0f, 0.2f) * mMatrixRotation;
			}
		}
	//平行に戻す
	if (CKey::Push('Y')) {
		mRotation.mX = 0;
		mRotation.mY = 0;
		mRotation.mZ = 0;
	}

	/*if (mRotation.mX > -90){
	mRotation = mRotation + CVector(0.1f, 0.0f, 0.0f) * mMatrixRotation;
	if (mRotation.mX > 90){
	mRotation.mX = 90;
	}
	}*/
	/*if (mRotation.mX < -90){
	mRotation = mRotation - CVector(0.5f, 0.0f, 0.0f) * mMatrixRotation;
	}*/


	//攻撃 (機関砲発射)
	if (CKey::Push(VK_SPACE)) {
		CBullet *b = new CBullet();
		b->mTaskTag = EPLAYERBULLET;
		b->Set(0.0f, 0.0f, 0.0f, 0.03f, 0.03f, 0.3f);
		b->SetDiffuse(1.0f, 1.0f, 0.0f, 1.0f);
		b->mPosition = mPosition;
		b->mRotation = mRotation;
		TaskManager.Add(b);
	}
	//ミサイルクールタイム
	if (mMissileInterval>0){
		mMissileInterval--;
	}
	//ミサイル発射
	if (CKey::Push('M')) {
		if (mMissileInterval <= 0){
			mMissileInterval = FIREINTERVAL_E;
			m = new CMissileAH(&mAAM, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f);
			m->mTaskTag = EPLAYERBULLET;
			m->mPosition = mPosition;
			m->mRotation = mRotation;
			TaskManager.Add(m);
		}
	}


	//フレアクールタイム
	if (mFlareInterval > 0){
		mFlareInterval--;
	}
	//フレア発射
	if (CKey::Push('F')) {
		if (mFlareInterval <= 0){
			mFlareInterval = FLAREINTERVAL_E;

			//フレア
			//フレア1
			Flare = new CFlare();
			Flare->Set(0.0f, 0.0f, -1.4f, 0.1f, 0.1f, 0.1f);
			//タグ設定
			Flare->mTaskTag = EFLARE;
			Flare->SetDiffuse(1.0f, 1.0f, 0.0f, 1.0f);
			Flare->mPosition = mPosition;
			Flare->mRotation = mRotation;
			TaskManager.Add(Flare);

			//フレア2
			Flare = new CFlare();
			Flare->Set(1.0f, 0.0f, -1.4f, 0.1f, 0.1f, 0.1f);
			//タグ設定
			Flare->mTaskTag = EFLARE;
			Flare->SetDiffuse(1.0f, 1.0f, 0.0f, 1.0f);
			Flare->mPosition = mPosition;
			Flare->mRotation = mRotation;
			TaskManager.Add(Flare);

			//フレア3
			Flare = new CFlare();
			Flare->Set(-1.0f, 0.0f, -1.4f, 0.1f, 0.1f, 0.1f);
			//タグ設定
			Flare->mTaskTag = EFLARE;
			Flare->SetDiffuse(1.0f, 1.0f, 0.0f, 1.0f);
			Flare->mPosition = mPosition;
			Flare->mRotation = mRotation;
			TaskManager.Add(Flare);
		}
	}
	CCharacter::Update();
}

void CPlayerAH::Collision(CCollider *m, CCollider *y) {
	if (CCollider::Collision(m, y)) {
		switch (y->mpParent->mTaskTag)
		{
		case EENEMYBULLET:
			f = new CFire();
			f->mPosition = y->mpParent->mPosition;
			f->SetTexture("fire.tga");
			TaskManager.Add(f);
			break;
		}
	}
}
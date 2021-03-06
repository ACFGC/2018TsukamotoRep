#include"CEMissileStandard.h"
#include"CEnemyStandard.h"
#include"CPlayerStandard.h"
#include"CFlare.h"
#include"CFire.h"
#include"CSceneGameF22.h"
//フレアの外部変数を呼ぶ
extern CFlare*Flare;
//ファイアの外部変数を呼ぶ
extern CFire *f;

#define LIFE 600

CEMissileStandard::CEMissileStandard(CModel *model, float px, float py, float pz, float rx, float ry, float rz, float sx, float sy, float sz)
: mELife(LIFE)
{
	Init(model, px, py, pz, rx, ry, rz, sx, sy, sz);
	mCollider.mpParent = this;
	mCollider.mRadius = 1.0f;
}

void CEMissileStandard::Update() {
	//敵ミサイル座標
	CVector vPos = CVector(1.0f, 0.0f, 0.0f) * mMatrix - CVector(0.0f, 0.0f, 0.0f) * mMatrix;
	//敵ミサイル方向ベクトル
	CVector vDir(10, 10, 10);
	//vPos = vPos.getRotationTowards(vDir);//ミサイル座標更新

	//ターゲット座標
	CVector vTargetpPos = CPlayerStandard::mPlayerStandard->mPosition - mPosition;
	//敵ミサイル
	float Emissile = vPos.dot(vTargetpPos);
	//敵ミサイル追尾処理
	if (Emissile > 0.0f){
		mRotation.mY += 1;
	}
	else if (Emissile < 0.0f){
		mRotation.mY -= 1;
	}

	//X方向へ追尾
	if (CPlayerStandard::mPlayerStandard->mPosition.mX > CEMissileStandard::mPosition.mX){
		mPosition.mX += 0.1;
	}
	if (CPlayerStandard::mPlayerStandard->mPosition.mX < CEMissileStandard::mPosition.mX){
		mPosition.mX -= 0.1;
	}
	//Y方向へ追尾
	if (CPlayerStandard::mPlayerStandard->mPosition.mY > CEMissileStandard::mPosition.mY){
		mPosition.mY += 0.1;
	}
	if (CPlayerStandard::mPlayerStandard->mPosition.mY < CEMissileStandard::mPosition.mY){
		mPosition.mY -= 0.1;
	}
	//Z方向へ追尾
	if (CPlayerStandard::mPlayerStandard->mPosition.mZ > CEMissileStandard::mPosition.mZ){
		mPosition.mZ += 0.1;
	}
	if (CPlayerStandard::mPlayerStandard->mPosition.mZ < CEMissileStandard::mPosition.mZ){
		mPosition.mZ -= 0.1;
	}
	if (CPlayerStandard::mPlayerStandard->mRotation.mX > CEMissileStandard::mRotation.mX){
		mRotation.mX += 0.1;
	}
	if (CPlayerStandard::mPlayerStandard->mRotation.mX < CEMissileStandard::mRotation.mX){
		mRotation.mX -= 0.1;
	}

	//敵ミサイル追尾処理時間
	if (ETime > 0){
		ETime--;
	}
	//時間がたったら再計算
	if (ETime == 0){
		//敵ミサイル追尾処理
		if (Emissile > 0.0f){
			mRotation.mY += 1;
		}
		else if (Emissile < 0.0f){
			mRotation.mY -= 1;
		}
		//Y方向へ追尾
		if (CPlayerStandard::mPlayerStandard->mPosition.mY > CEMissileStandard::mPosition.mY){
			mPosition.mY += 0.1;
		}
		if (CPlayerStandard::mPlayerStandard->mPosition.mY < CEMissileStandard::mPosition.mY){
			mPosition.mY -= 0.1;
		}
		//X方向へ追尾
		if (CPlayerStandard::mPlayerStandard->mPosition.mX > CEMissileStandard::mPosition.mX){
			mPosition.mX += 0.1;
		}
		if (CPlayerStandard::mPlayerStandard->mPosition.mX < CEMissileStandard::mPosition.mX){
			mPosition.mX -= 0.1;
		}
		//Z方向へ追尾
		if (CPlayerStandard::mPlayerStandard->mPosition.mZ > CEMissileStandard::mPosition.mZ){
			mPosition.mZ += 0.1;
		}
		if (CPlayerStandard::mPlayerStandard->mPosition.mZ < CEMissileStandard::mPosition.mZ){
			mPosition.mZ -= 0.1;
		}
		if (CPlayerStandard::mPlayerStandard->mRotation.mX > CEMissileStandard::mRotation.mX){
			mRotation.mX += 0.1;
		}
		if (CPlayerStandard::mPlayerStandard->mRotation.mX < CEMissileStandard::mRotation.mX){
			mRotation.mX -= 0.1;
		}
	}
	if (mELife > 0) {
		mELife--;
		CCharacter::Update();
		mPosition = mPosition + CVector(0.0f, 0.0f, 1.0f) * mMatrixRotation;
	}
	else {
		mEnabled = false;
	}
}

void CEMissileStandard::Collision(CCollider *m, CCollider *y) {
	//当たったか判定
	if (CCollider::Collision(m, y)){
		switch (y->mpParent->mTaskTag){
			//当たった相手のタグがEPLAYERなら
		case EPLAYER:
			f = new CFire();
			f->mPosition = y->mpParent->mPosition;
			f->SetTexture("fire.tga");
			TaskManager.Add(f);
			//自分を消す
			m->mpParent->mEnabled = false;
			//当たった相手を消す
			//y->mpParent->mEnabled = false;
			break;

			//当たった相手のタグがEFLAREなら
		case EFLARE:
			f = new CFire();
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
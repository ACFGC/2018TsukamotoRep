#include"CEMissileAH.h"
#include"CEnemyAH.h"
#include"CPlayerAH.h"
#include"CFlare.h"
#include"CFire.h"
#include"CSceneGameAH.h"
//フレアの外部変数を呼ぶ
extern CFlare*Flare;
//ファイアの外部変数を呼ぶ
extern CFire *f;

#define LIFE 600

CEMissileAH::CEMissileAH(CModel *model, float px, float py, float pz, float rx, float ry, float rz, float sx, float sy, float sz)
: mELife(LIFE)
{
	Init(model, px, py, pz, rx, ry, rz, sx, sy, sz);
	mCollider.mpParent = this;
	mCollider.mRadius = 1.0f;
}

void CEMissileAH::Update() {
	//敵ミサイル座標
	CVector vPos = CVector(1.0f, 0.0f, 0.0f) * mMatrix - CVector(0.0f, 0.0f, 0.0f) * mMatrix;
	//敵ミサイル方向ベクトル
	CVector vDir(10, 10, 10);
	//vPos = vPos.getRotationTowards(vDir);//ミサイル座標更新

	//ターゲット座標
	CVector vTargetpPos = CPlayerAH::mpPlayerAH->mPosition - mPosition;
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
	if (CPlayerAH::mpPlayerAH->mPosition.mX > CEMissileAH::mPosition.mX){
		mPosition.mX += 0.1;
	}
	if (CPlayerAH::mpPlayerAH->mPosition.mX < CEMissileAH::mPosition.mX){
		mPosition.mX -= 0.1;
	}
	//Y方向へ追尾
	if (CPlayerAH::mpPlayerAH->mPosition.mY > CEMissileAH::mPosition.mY){
		mPosition.mY += 0.1;
	}
	if (CPlayerAH::mpPlayerAH->mPosition.mY < CEMissileAH::mPosition.mY){
		mPosition.mY -= 0.1;
	}
	//Z方向へ追尾
	if (CPlayerAH::mpPlayerAH->mPosition.mZ > CEMissileAH::mPosition.mZ){
		mPosition.mZ += 0.1;
	}
	if (CPlayerAH::mpPlayerAH->mPosition.mZ < CEMissileAH::mPosition.mZ){
		mPosition.mZ -= 0.1;
	}
	if (CPlayerAH::mpPlayerAH->mRotation.mX > CEMissileAH::mRotation.mX){
		mRotation.mX += 0.1;
	}
	if (CPlayerAH::mpPlayerAH->mRotation.mX < CEMissileAH::mRotation.mX){
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
		if (CPlayerAH::mpPlayerAH->mPosition.mY > CEMissileAH::mPosition.mY){
			mPosition.mY += 0.1;
		}
		if (CPlayerAH::mpPlayerAH->mPosition.mY < CEMissileAH::mPosition.mY){
			mPosition.mY -= 0.1;
		}
		//X方向へ追尾
		if (CPlayerAH::mpPlayerAH->mPosition.mX > CEMissileAH::mPosition.mX){
			mPosition.mX += 0.1;
		}
		if (CPlayerAH::mpPlayerAH->mPosition.mX < CEMissileAH::mPosition.mX){
			mPosition.mX -= 0.1;
		}
		//Z方向へ追尾
		if (CPlayerAH::mpPlayerAH->mPosition.mZ > CEMissileAH::mPosition.mZ){
			mPosition.mZ += 0.1;
		}
		if (CPlayerAH::mpPlayerAH->mPosition.mZ < CEMissileAH::mPosition.mZ){
			mPosition.mZ -= 0.1;
		}
		if (CPlayerAH::mpPlayerAH->mRotation.mX > CEMissileAH::mRotation.mX){
			mRotation.mX += 0.1;
		}
		if (CPlayerAH::mpPlayerAH->mRotation.mX < CEMissileAH::mRotation.mX){
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

void CEMissileAH::Collision(CCollider *m, CCollider *y) {
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
/*//ミサイル座標
CVector vPos = CVector(1.0f, 0.0f, 0.0f) * mMatrix - CVector(0.0f, 0.0f, 0.0f) * mMatrix;

//ミサイル方向ベクトル
CVector vDir(10, 10, 10);
//vPos = vPos.getRotationTowards(vDir);//ミサイル座標更新

//フレア座標
CVector vTargetFPos = Flare->mPosition - mPosition;

//ミサイル
float EFmissile = vPos.dot(vTargetFPos);

//ミサイル追尾処理
if (EFmissile > 0.0f){
mRotation.mY += 1;
}
else if (EFmissile < 0.0f){
mRotation.mY -= 1;
}

//Y方向へ追尾
if (Flare->mPosition.mY > CEMissile::mPosition.mY){
mPosition.mY += 0.1;
}
if (Flare->mPosition.mY < CEMissile::mPosition.mY){
mPosition.mY -= 0.1;
}

//X方向へ追尾
if (Flare->mPosition.mX > CEMissile::mPosition.mX){
mPosition.mX += 0.1;
}
if (Flare->mPosition.mX < CEMissile::mPosition.mX){
mPosition.mX -= 0.1;
}

//Z方向へ追尾
if (Flare->mPosition.mZ > CEMissile::mPosition.mZ){
mPosition.mZ += 0.1;
}
if (Flare->mPosition.mZ < CEMissile::mPosition.mZ){
mPosition.mZ -= 0.1;
}
if (Flare->mRotation.mX > CEMissile::mRotation.mX){
mRotation.mX += 0.1;
}
if (Flare->mRotation.mX < CEMissile::mRotation.mX){
mRotation.mX -= 0.1;
}
if (ETime <= 100){
if (Flare->mEnabled = true){
//フレア座標
CVector vTargetFPos = Flare->mPosition - mPosition;
//フレア追尾
float EFmissile = vPos.dot(vTargetFPos);
if (EFmissile > 0.0f){
mRotation.mY += 1;
}
else if (EFmissile < 0.0f){
mRotation.mY -= 1;
}

//フレア追尾処理
//X方向へ追尾
if (Flare->mPosition.mX > CEMissile::mPosition.mX){
mPosition.mX += 0.1;
}
if (Flare->mPosition.mX < CEMissile::mPosition.mX){
mPosition.mX -= 0.1;
}

//Y方向へ追尾
if (Flare->mPosition.mY > CEMissile::mPosition.mY){
mPosition.mY += 0.1;
}
if (Flare->mPosition.mY < CEMissile::mPosition.mY){
mPosition.mY -= 0.1;
}

//Z方向へ追尾
if (Flare->mPosition.mZ > CEMissile::mPosition.mZ){
mPosition.mZ += 0.1;
}
if (Flare->mPosition.mZ < CEMissile::mPosition.mZ){
mPosition.mZ -= 0.1;
}
if (Flare->mRotation.mX > CEMissile::mRotation.mX){
mRotation.mX += 0.1;
}
if (Flare->mRotation.mX < CEMissile::mRotation.mX){
mRotation.mX -= 0.1;
}
}
}
else{
//ミサイル追尾処理
if (Emissile > 0.0f){
mRotation.mY += 1;
}
else if (Emissile < 0.0f){
mRotation.mY -= 1;
}
//Y方向へ追尾
if (CPlayer::mpPlayer->mPosition.mY > CEMissile::mPosition.mY){
mPosition.mY += 0.1;
}
if (CPlayer::mpPlayer->mPosition.mY < CEMissile::mPosition.mY){
mPosition.mY -= 0.1;
}
//X方向へ追尾
if (CPlayer::mpPlayer->mPosition.mX > CEMissile::mPosition.mX){
mPosition.mX += 0.1;
}
if (CPlayer::mpPlayer->mPosition.mX < CEMissile::mPosition.mX){
mPosition.mX -= 0.1;
}
//Z方向へ追尾
if (CPlayer::mpPlayer->mPosition.mZ > CEMissile::mPosition.mZ){
mPosition.mZ += 0.1;
}
if (CPlayer::mpPlayer->mPosition.mZ < CEMissile::mPosition.mZ){
mPosition.mZ -= 0.1;
}
if (CPlayer::mpPlayer->mRotation.mX > CEMissile::mRotation.mX){
mRotation.mX += 0.1;
}
if (CPlayer::mpPlayer->mRotation.mX < CEMissile::mRotation.mX){
mRotation.mX -= 0.1;
}
}
*/
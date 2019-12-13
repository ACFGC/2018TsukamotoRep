#include"CMissile.h"
#include"CEnemy.h"
#include"CPlayer.h"

//敵の外部変数を呼ぶ
extern CEnemy*Enemy;
#define LIFE 600
//時間
int Time = 30 * 60;

CMissile::CMissile(CModel *model, float px, float py, float pz, float rx, float ry, float rz, float sx, float sy, float sz)
: mLife(LIFE)
{
	Init(model, px, py, pz, rx, ry, rz, sx, sy, sz);
	mCollider.mpParent = this;
	mCollider.mRadius = 1.0f;
}

void CMissile::Update() {
	CVector vPos = CVector(1.0f, 0.0f, 0.0f) * mMatrix - CVector(0.0f, 0.0f, 0.0f) * mMatrix;//ミサイル座標
	CVector vDir(0, 10, 0); //ミサイル方向ベクトル
	//vPos = vPos.getRotationTowards(vDir);//ミサイル座標更新

	CEnemy*tenemy = Enemy;//敵の座標を持たせる
	CVector vTargetPos = tenemy->mPosition - mPosition;//ターゲット座標
	//CVector vtargetppos = CPlayer::mpPlayer->mPosition - mPosition;
	float missile = vPos.dot(vTargetPos);//ミサイル
	//ミサイル追尾処理
	if (missile > 0.0f){
		mRotation.mY += 1;
	}
	else if (missile < 0.0f){
		mRotation.mY -= 1;
	}
	//Y方向へ追尾
	if (tenemy->mPosition.mY > CMissile::mPosition.mY){
	mPosition.mY += 0.1;
	}
	if (tenemy->mPosition.mY < CMissile::mPosition.mY){
	mPosition.mY -= 0.1;
	}
	//X方向へ追尾
	if (tenemy->mPosition.mX > CMissile::mPosition.mX){
		mPosition.mX += 0.1;
	}
	if (tenemy->mPosition.mX < CMissile::mPosition.mX){
		mPosition.mX -= 0.1;
	}
	//Z方向へ追尾
	if (tenemy->mPosition.mZ > CMissile::mPosition.mZ){
		mPosition.mZ += 0.1;
	}
	if (tenemy->mPosition.mZ < CMissile::mPosition.mZ){
		mPosition.mZ -= 0.1;
	}
	if (tenemy->mRotation.mX > CMissile::mRotation.mX){
		mRotation.mX += 0.1;
	}
	if (tenemy->mRotation.mX < CMissile::mRotation.mX){
		mRotation.mX -= 0.1;
	}
	//ミサイル追尾処理時間
	if (Time > 0){
		Time--;
	}
	//時間がたったら再計算
	if (Time == 0){
		if (missile < 0.0f){
			mRotation.mY += 1;
		}
		else if (missile > 0.0f){
			mRotation.mY -= 1;
		}
		if (tenemy->mPosition.mY > CMissile::mPosition.mY){
			mPosition.mY += 0.1;
		}
		if (tenemy->mPosition.mY < CMissile::mPosition.mY){
			mPosition.mY -= 0.1;
		}
		if (tenemy->mPosition.mX > CMissile::mPosition.mX){
			mPosition.mX += 0.1;
		}
		if (tenemy->mPosition.mX < CMissile::mPosition.mX){
			mPosition.mX -= 0.1;
		}
		if (tenemy->mRotation.mX > CMissile::mRotation.mX){
			mRotation.mX += 0.1;
		}
		if (tenemy->mRotation.mX < CMissile::mRotation.mX){
			mRotation.mX -= 0.1;
		}
	}
	if (mLife > 0) {
		mLife--;
		//CCharacter::Update();
		//mPosition = mPosition + CVector(0.0f, 0.0f, 1.0f) * mMatrixRotation;
		//行列更新
		mMatrix = mMatrix.Scale(mScale.mX, mScale.mY, mScale.mZ) * mMatrixRotation * 
			mMatrix.Translate(mPosition.mX, mPosition.mY, mPosition.mZ);
		mPosition = mPosition + CVector(0.0f, 0.0f, 1.0f) * mMatrixRotation;
	}
	else {
		mEnabled = false;
	}
}
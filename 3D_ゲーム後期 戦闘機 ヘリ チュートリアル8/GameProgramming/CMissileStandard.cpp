#include"CMissileStandard.h"
#include"CEnemyStandard.h"
#include"CPlayerStandard.h"
#include"CFire.h"
#include"CSceneGameF22.h"
//敵の外部変数を呼ぶ
extern CEnemyStandard*EnemySD;
//ファイアの外部変数を呼ぶ
extern CFire *f;
#define LIFE 600

CMissileStandard::CMissileStandard(CModel *model, float px, float py, float pz, float rx, float ry, float rz, float sx, float sy, float sz)
: mLife(LIFE)
{
	Init(model, px, py, pz, rx, ry, rz, sx, sy, sz);
	mCollider.mpParent = this;
	mCollider.mRadius = 1.0f;
}

void CMissileStandard::Update() {
	CVector vPos = CVector(1.0f, 0.0f, 0.0f) * mMatrix - CVector(0.0f, 0.0f, 0.0f) * mMatrix;//ミサイル座標
	CVector vPosX = CVector(0.0f, 1.0f, 0.0f) * mMatrix - CVector(0.0f, 0.0f, 0.0f) * mMatrix;//ミサイルX座標
	CVector vDir(mPosition.mX, 10, mPosition.mZ); //ミサイル方向ベクトル
	//vPos = vPos.getRotationTowards(vDir);//ミサイル座標更新

	CEnemyStandard*tenemy = EnemySD;//敵の座標を持たせる
	CVector vTargetPos = tenemy->mPosition - mPosition;//ターゲット座標
	//CVector vtargetppos = CPlayer::mpPlayer->mPosition - mPosition;
	float missile = vPos.dot(vTargetPos);//ミサイル
	//ミサイル追尾処理
	if (missile > tenemy->mPosition.mX){
		//mRotation.mY += 1;
		mMatrixRotation = mMatrixRotation*CMatrix().RotateY(1);
	}
	else if (missile < tenemy->mPosition.mX){
		//mRotation.mY -= 1;
		mMatrixRotation = mMatrixRotation*CMatrix().RotateY(-1);
	}
	float missileX = vPosX.dot(vTargetPos);
	//ミサイル追尾処理
	if (missileX > tenemy->mPosition.mY){
		//mRotation.mY += 1;
		mMatrixRotation = mMatrixRotation*CMatrix().RotateX(-1);
	}
	else if (missileX < tenemy->mPosition.mY){
		//mRotation.mY -= 1;
		mMatrixRotation = mMatrixRotation*CMatrix().RotateX(1);
	}
	//ミサイル追尾処理時間
	if (Time > 0){
		Time--;
	}
	//時間がたったら再計算
	/*if (Time == 0){
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
	}*/
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
void CMissileStandard::Collision(CCollider *m, CCollider *y) {
	//当たったか判定
	if (CCollider::Collision(m, y)){
		switch (y->mpParent->mTaskTag){
			//当たった相手のタグがEENEMYなら
		case EENEMY:
			f = new CFire();
			f->mPosition = y->mpParent->mPosition;
			f->SetTexture("fire.tga");
			TaskManager.Add(f);
			//自分を消す
			m->mpParent->mEnabled = false;
			//当たった相手を消す
			//y->mpParent->mEnabled = false;
			break;
		}
	}
}
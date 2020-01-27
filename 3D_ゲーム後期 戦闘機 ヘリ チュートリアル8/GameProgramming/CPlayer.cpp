#include"CPlayer.h"
#include"CKey.h"
#include"CBullet.h"
#include"CSceneGameF22.h"
#include"CMissile.h"
#include"CFlare.h"
#include"CFire.h"
#include"CHpBar.h"
//ミサイルクールタイム(時間)
#define FIREINTERVAL_E 100
//フレアクールタイム(時間)
#define FLAREINTERVAL_E 60
//フレアの外部変数を作る
CFlare*Flare;
//ミサイルの外部変数を作る
CMissile *m;
//ファイアの外部変数を作る
CFire *f;
//ミサイル(モデル)の外部変数を呼ぶ
extern CModel mAAM;
//HPバーの外部変数を呼ぶ
extern CHpBar HP;
CPlayer *CPlayer::mpPlayer = 0;

CPlayer::CPlayer() {
	mpPlayer = this;
	mPCollider.mpParent = this;
	mPCollider.mRadius = 1.0f;
	//タグを設定
	mTaskTag = EPLAYER;
	//ミサイルのモデルを読み込む
	mAAM.Load("AAM.obj", "AAM.mtl");
	//HP = 100;
	HP.Init();
}

CPlayer::~CPlayer() {
	mpPlayer = 0;
}

void CPlayer::Update() {
	//戦闘機操作処理
	//mPosition = CVector(0.0f, 0.0f, 1.5f) * mMatrix;
	//前進 (スロットルアップ)
	if (CKey::Push('I')) {
		mPosition = CVector(0.0f, 0.0f, 3.0f) * mMatrix;
	}
	//後進 (スロットルダウン)
	if (CKey::Push('K')) {
		mPosition = CVector(0.0f, 0.0f, -2.0f) * mMatrix;
	}
	//任意軸回転での操作
	CMatrix mx, mz, my;
	CVector vz = CVector(0.0f, 0.0f, 1.0f)*mMatrixRotation;
	CVector vx = CVector(1.0f, 0.0f, 0.0f)*mMatrixRotation;
	CVector vy = CVector(0.0f, 1.0f, 0.0f)*mMatrixRotation;

	//ロール
	//左ロール
	if (CKey::Push('A')){
		mz.Axis(-2.0f,vz.mX, vz.mY, vz.mZ);
	}
	//右ロール
	if (CKey::Push('D')){
		mz.Axis(2.0f,vz.mX, vz.mY, vz.mZ);
	}

	//ピッチ
	//ピッチダウン
	if (CKey::Push('W')){
		mx.Axis(1.0f, vx.mX, vx.mY, vx.mZ);
	}
	//ピッチアップ
	if (CKey::Push('S')){
		mx.Axis(-1.0f, vx.mX, vx.mY, vx.mZ);
	}

	//ヨー
	//左ヨー
	if (CKey::Push('J')){
		my.Axis(1.0f, vy.mX, vy.mY, vy.mZ);
	}
	//右ヨー
	if (CKey::Push('L')){
		my.Axis(-1.0f, vy.mX, vy.mY, vy.mZ);
	}

	//水平に戻す
	/*if (CKey::Push('Y')) {

	}*/

	//マニューバ
	//クルビット
	if (CKey::Push('Z')) {
		mx.Axis(-5.0f, vx.mX, vx.mY, vx.mZ);
	}
	//コブラ
	if (CKey::Push('X')){
		vz.mZ++;
		vy.mY++;
		vx.mX++;
	}

	mMatrixRotation = mMatrixRotation * mx * mz * my;
	mMatrix = mMatrix.Scale(mScale.mX, mScale.mY, mScale.mZ) * mMatrixRotation * 
		mMatrix.Translate(mPosition.mX, mPosition.mY, mPosition.mZ);

	//攻撃 
	//機関砲発射
	if (CKey::Push(VK_SPACE)){
		CBullet*b = new CBullet();
		b->Set(-0.5f, 0.0f, 0.2f, 0.03f, 0.03f, 0.3f);
		b->SetDiffuse(1.0f, 1.0f, 0.0f, 1.0f);
		b->mPosition = mPosition;
		
		//回転行列を設定
		b->mMatrixRotation = mMatrixRotation;
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
			m = new CMissile(&mAAM, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 3.0f, 3.0f, 3.0f);
			m->mTaskTag = EPLAYERMISSILE;
			m->mPosition = mPosition;
			//m->mRotation = mRotation;
			//回転行列を設定
			m->mMatrixRotation = mMatrixRotation;
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
		    Flare= new CFlare();
		    Flare->Set(0.0f, 0.0f, -1.4f, 0.1f, 0.1f, 0.1f);
			//タグ設定
			Flare->mTaskTag = EFLARE;
		    Flare->SetDiffuse(1.0f, 1.0f, 0.0f, 1.0f);
			Flare->mPosition = mPosition;
			//回転行列を設定
			Flare->mMatrixRotation = mMatrixRotation;
			TaskManager.Add(Flare);
			//フレア2
			Flare = new CFlare();
			Flare->Set(1.0f, 0.0f, -1.4f, 0.1f, 0.1f, 0.1f);
			//タグ設定
			Flare->mTaskTag = EFLARE;
			Flare->SetDiffuse(1.0f, 1.0f, 0.0f, 1.0f);
			Flare->mPosition = mPosition;
			//回転行列を設定
			Flare->mMatrixRotation = mMatrixRotation;
			TaskManager.Add(Flare);
			//フレア3
			Flare = new CFlare();
			Flare->Set(-1.0f, 0.0f, -1.4f, 0.1f, 0.1f, 0.1f);
			//タグ設定
			Flare->mTaskTag = EFLARE;
			Flare->SetDiffuse(1.0f, 1.0f, 0.0f, 1.0f);
			Flare->mPosition = mPosition;
			//回転行列を設定
			Flare->mMatrixRotation = mMatrixRotation;
			TaskManager.Add(Flare);
		}
	}
	mRadar.mPosition = mPosition + CVector(0.0f, 0.0f, 10.0f);
	mRadar.Update();
	/*if (CKey::Push('Q')){
		f = new CFire();
		f->SetSize(0.5f, 0.5f);
		f->mPosition = mPosition;
		f->SetTexture("notenecbw_L.tga");
		TaskManager.Add(f);
	}*/
	//mHpBar.Update();
	//CCharacter::Update();
}
void CPlayer::Render(){
	CCharacter::Render();
	mRadar.Render();
}
void CPlayer::Collision(CCollider *m, CCollider *y) {
	if (CCollider::Collision(m, y)) {
		switch (y->mpParent->mTaskTag)
		{
		case EENEMYBULLET:
			/*f = new CFire();
			f->mPosition = y->mpParent->mPosition;
			f->SetTexture("fire.tga");
			TaskManager.Add(f);*/
			HP.HP -= 40.0f;
			if (HP.HP <= 0.0f){
				mState = EDESTORY;
				switch (m->mpParent->mState)
				{
				case EDESTORY:
					m->mpParent->mEnabled = false;
					break;
				}
				//自分を消す
				m->mpParent->mEnabled = false;
				//当たった相手を消す
				//y->mpParent->mEnabled = false;
			}
			break;
		/*case EPLAYERBULLET:
			f = new CFire();
			f->SetSize(0.5f, 0.5f);
			f->mPosition = y->mpParent->mPosition;
			f->SetTexture("Autocannon.tga");
			TaskManager.Add(f);
			break;*/
		}
	}
}

/*//上に傾いた時上方向へ前進
if (mRotation.mX <= 50){
mPosition = mPosition + CVector(0.0f, 0.0f, 0.4f) * mMatrixRotation;
}
//下に傾いた時下方向へ前進
if (mRotation.mX >= 50){
mPosition = mPosition + CVector(0.0f, 0.0f, 0.2f) * mMatrixRotation;
}*/
//上昇
/*if (GetKeyState('I') & 0x8000){
//mainrotor.mRotation.y += 40;
//tellrotor.mRotation.x += 20;
mPosition.mY += 5;
}
//下降
if (GetKeyState('K') & 0x8000){
//mainrotor.mRotation.y += 80;
//tellrotor.mRotation.x += 40;
mPosition.mY -= 5;
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
}*/
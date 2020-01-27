#include"CTutorialStandard.h"
#include"glut.h"
#include"CTriangle.h"
#include"CKey.h"
#include"CEnemyStandard.h"
#include<math.h>
//タスクマネージャーの外部変数を呼ぶ
extern CTaskManager TaskManager;
//コリジョンマネージャーの外部変数を呼ぶ
extern CCollisionManager CollisionManager;
//敵の外部変数を作る
 CEnemyStandard*Enemy;
//テキストの外部変数を呼ぶ
extern CText*mText;
//時間
//int mTime = 30 * 60;
#define Time 100
void CTutorialStandard::Init() {
	//シーン設定
	mScene = ETUTORIALSTANDARD;
	//航空機(モデル)読み込み
	mModel.Load("F15.obj", "F15.mtl");
	mSky.Load("sky.obj", "sky.mtl");
	mC5.Load("C5.obj", "C5.mtl");
	//モデル割り当て
	mPlayer.Init(&mModel, 0.0f, 5.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.2f, 0.2f, 0.2f);
	Enemy = new CEnemyStandard(&mC5, 0.0f, 5.0f, 6.0f, 0.0f, 0.0f, 0.0f, 0.2f, 0.2f, 0.2f);
	Enemy = new CEnemyStandard(&mC5, 0.0f, 17.0f, 6.0f, 0.0f, 0.0f, 0.0f, 0.2f, 0.2f, 0.2f);
}

void CTutorialStandard::Update() {

	mPlayer.Update();
	TaskManager.Update();
	CollisionManager.Update();
	TaskManager.Delete();
	/*if (mTime > 0){
	mTime--;
	}
	if (mTime <= 0){
	mTime = Time;
	}
	if (mTime <= 0&&Enemy->mEnabled==false){
	mTime = Time;
	Enemy = new CEnemy(&mF15, 0.0f, 13.0f, 6.0f, 0.0f, 0.0f, 0.0f, 0.2f, 0.2f, 0.2f);
	Enemy = new CEnemy(&mSu57, 0.0f, 17.0f, 6.0f, 0.0f, 0.0f, 0.0f, 0.2f, 0.2f, 0.2f);
	}*/
	//カメラ設定
	mCamera.mEye = mPlayer.mPosition + CVector(0.0f, 0.6f, -2.5f) * mPlayer.mMatrixRotation;
	mCamera.mCenter = mPlayer.mPosition;
	mCamera.mUp = CVector(0.0f, 1.0f, 0.0f) * mPlayer.mMatrixRotation;
	//後ろを向く
	if (CKey::Push('C')) {
		mCamera.mEye = mPlayer.mPosition - CVector(0.0f, -0.6f, -3.0f) * mPlayer.mMatrixRotation;
	}
	if (CKey::Once(VK_BACK)){
		//ゲームオーバー
		mScene = EGAMEOVER;
	}
	/*if(CPlayer::mpPlayer->mState == CPlayer::EState::EDESTORY){
	mScene = EGAMEOVER;
	}*/
	mCamera.Render();

	mSky.Render(CMatrix());
	//mSky.Render(CMatrix().Scale(10.0f,10.0f,10.0f));
	mPlayer.Render();
	TaskManager.Render();
	//2D座標でUIを描画
	//行列をプロジェクションモードへ変更
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();		//プロジェクション行列を退避
	glLoadIdentity();	//プロジェクション行列を初期化
	//プロジェクション行列を800×600に設定
	gluOrtho2D(-400, 400, -300, 300);
	//行列をモデルビューモードへ変更
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();		//モデルビュー行列を退避
	glLoadIdentity();	//モデルビュー行列を初期化

	glDisable(GL_LIGHTING);	//ライト無効
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);	//描画色

	//文字列設定
	//文字列描画
	//操作表示
	if (CKey::Push('Q')){
		//前後入力
		mText->DrawString("K Key:Throttle Down", -350, -150, 7, 15);
		mText->DrawString("I Key:Throttle UP", -350, -100, 7, 15);
		//上下入力
		mText->DrawString("W Key:PitchDown", -100, -200, 7, 15);
		mText->DrawString("S Key:PitchUp", -100, 200, 7, 15);
		//右入力
		mText->DrawString("J Key:Left Yaw", -350, 100, 7, 15);
		mText->DrawString("A Key:Left Roll", -350, 50, 7, 15);
		//左入力
		mText->DrawString("L Key:Right Yaw", 170, 100, 7, 15);
		mText->DrawString("D Key:Right Roll", 170, 50, 7, 15);
		//攻撃入力
		mText->DrawString("SPACE Key:Cannon", 170, -150, 7, 15);
		mText->DrawString("M Key:Missile", 170, -100, 7, 15);
		//mText->DrawString("I Key:Throttle UP  K Key:Throttle Down", -350, -210, 7, 15);//文字列描画
	}//"SPACE:Missile W:PitUP A:LeftROLL S:PitDOWN D:RightROLL"
	glEnable(GL_LIGHTING);	//ライド有効

	glPopMatrix();	//モデルビュー描画行列を戻す
	//行列をプロジェクションモードへ変更
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();	//プロジェクション行列を戻す
	//行列をモデルビューモードへ変更
	glMatrixMode(GL_MODELVIEW);
}

//デストラクタ
CTutorialStandard::~CTutorialStandard() {
	TaskManager.Destory();
}

#include"CTutorial.h"
#include "glut.h"
#include "CTriangle.h"
#include "CKey.h"
#include "CEnemy.h"
#include "CFire.h"
#include <math.h>
//敵の外部変数を呼ぶ
extern CEnemy*Enemy;
//テキストの外部変数を呼ぶ
extern CText*mText;
CTutorial*mTutorial;
void CTutorial::Init() {
	//シーン設定
	mScene = ETUTORIAL;
	//航空機(モデル)読み込み
	mModel.Load("F15C.obj", "F15C.mtl");
	mSky.Load("sky.obj", "sky.mtl");
	mC5.Load("C5.obj", "C5.mtl");
	//モデル割り当て
	mPlayer.Init(&mModel, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.4f, 0.4f, 0.4f);
	new CDummy(&mC5, 16.0f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.1f, 0.1f, 0.1f);
}

void CTutorial::Update() {

	mPlayer.Update();
	TaskManager.Update();
	CollisionManager.Update();
	TaskManager.Delete();

	//カメラ設定
	mCamera.mEye = mPlayer.mPosition + CVector(0.0f, 2.0f, -8.0f) * mPlayer.mMatrixRotation;
	mCamera.mCenter = mPlayer.mPosition;
	mCamera.mUp = CVector(0.0f, 1.0f, 0.0f) * mPlayer.mMatrixRotation;
	//後ろを向く
	if (CKey::Push('C')) {
		mCamera.mEye = mPlayer.mPosition - CVector(0.0f, -2.0f, -8.0f) * mPlayer.mMatrixRotation;
	}
	if (CKey::Once(VK_BACK)){
		//タイトルに戻る
		mScene = ETITLE;
	}
	mCamera.Render();

	mSky.Render(CMatrix());
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
	mText->DrawString("M:Missile W:PitUP A:< S:PitDOWN D:>", -350, 250, 10, 20);//文字列描画
	if (CKey::Once('H')){
		//mText->DrawString("AAAAA", -250, 150, 10, 20);//文字列描画
	}
	//"SPACE:Missile W:PitUP A:LeftROLL S:PitDOWN D:RightROLL"
	glEnable(GL_LIGHTING);	//ライド有効

	glPopMatrix();	//モデルビュー描画行列を戻す
	//行列をプロジェクションモードへ変更
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();	//プロジェクション行列を戻す
	//行列をモデルビューモードへ変更
	glMatrixMode(GL_MODELVIEW);
}
//デストラクタ
CTutorial::~CTutorial() {
	TaskManager.Destory();
}
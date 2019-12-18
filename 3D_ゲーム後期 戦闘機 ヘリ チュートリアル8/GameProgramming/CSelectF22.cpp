#include"CSelectF22.h"
//初期化処理のオーバーライド
void CSelectF22::Init(){
	//フォントの設定
	//テクスチャファイルを読み込む
	CText::mFont.Load("font.tga");
	mScene = ESELECTF22;
	mF22.Load("F22.obj", "F22.mtl");
	mSDummy = new CDummy(&mF22, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.9f, 0.9f, 0.9f);
}
//更新処理のオーバーライド
void CSelectF22::Update(){
	TaskManager.Update();
	CollisionManager.Update();
	TaskManager.Delete();
	mSDummy->mRotation = mSDummy->mRotation + CVector(0.0f, 2.0f, 0.0f);
	if (CKey::Once('D')){
		//次のシーンはF15
		mScene = ESELECTF15;
	}
	if (CKey::Once('A')){
		//次のシーンはAH6
		mScene = ESELECTAH6;
	}
	if (CKey::Once(VK_BACK)){
		//次のシーンはタイトル
		mScene = ETITLE;
	}
	mCamera.Render();
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
	//文字列の描画
	//航空機
	mText->DrawString("F22<", -350, 270, 20, 20);
	mText->DrawString("F15", -350, 235, 15, 15);
	mText->DrawString("Su57", -350, 200, 15, 15);
	mText->DrawString("AH1", -350, 165, 15, 15);
	mText->DrawString("AH6", -350, 130, 15, 15);
	//次の航空機
	mText->DrawString("<<NEXT", -380, 25, 10, 10);
	mText->DrawString("Push A Key", -380, 0, 8, 8);
	mText->DrawString("NEXT>>", 290, 25, 10, 10);
	mText->DrawString("Push D Key", 250, 0, 8, 8);
	//決定
	mText->DrawString("Play this AirCraft!", -250, -100, 16, 16);
	mText->DrawString("Push ENTER Key", -200, -200, 16, 16);
	if (CKey::Once(VK_RETURN)){
		//次のシーンはゲーム
		mScene = EGAMEF22;
	}
	glEnable(GL_LIGHTING);	//ライド有効

	glPopMatrix();	//モデルビュー描画行列を戻す
	//行列をプロジェクションモードへ変更
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();	//プロジェクション行列を戻す
	//行列をモデルビューモードへ変更
	glMatrixMode(GL_MODELVIEW);
}

//デストラクタ
CSelectF22::~CSelectF22() {
	TaskManager.Destory();
}
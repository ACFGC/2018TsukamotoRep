#include"CScene.h"//シーンクラスのインクルード
#include"CText.h"//テキストクラスのインクルード
#include"CKey.h"//キークラスのインクルード
#include<Windows.h>
extern CText*mText;
/*
ゲームオーバーシーン
*/
//CSceneクラスを継承する
class CGameOver :public CScene{
public:
	//次のシーンの取得
	EScene GetNextScene(){
		return mScene;
	}
	//初期化処理のオーバーライド
	void Init(){
		//フォントの設定
		//テクスチャファイルを読み込む
		CText::mFont.Load("font.tga");
		mScene = EGAMEOVER;
	}
	//更新処理のオーバーライド
	void Update(){
		if (CKey::Once(VK_RETURN)){
			//次はタイトル
			mScene = ETITLE;
		}
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
		mText->DrawString("GAME OVER", -200, 100, 25, 25);
		glEnable(GL_LIGHTING);	//ライド有効

		glPopMatrix();	//モデルビュー描画行列を戻す
		//行列をプロジェクションモードへ変更
		glMatrixMode(GL_PROJECTION);
		glPopMatrix();	//プロジェクション行列を戻す
		//行列をモデルビューモードへ変更
		glMatrixMode(GL_MODELVIEW);
	}
};
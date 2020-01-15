#ifndef CSELECTSu57_H
#define CSELECTSu57_H
#include"CScene.h"//シーンクラスのインクルード
#include"CText.h"//テキストクラスのインクルード
#include"CKey.h"//キークラスのインクルード
#include"CDummy.h"
#include"CCamera.h"
#include"CCollisionManager.h"
extern CText*mText;
extern CTaskManager TaskManager;
extern CCollisionManager CollisionManager;
/*
タイトルシーン
*/
//CSceneクラスを継承する
class CSelectSu57 :public CScene{
public:
	CModel mSu57;
	CDummy*mSDummy;
	//カメラ
	CCamera mCamera;
	//次のシーンの取得
	EScene GetNextScene(){
		return mScene;
	}
	//初期化処理のオーバーライド
	void Init();
	//更新処理のオーバーライド
	void Update();
	//デストラクタの宣言
	~CSelectSu57();
};
#endif
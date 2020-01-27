#ifndef CSELECTAH1SD_H
#define CSELECTAH1SD_H
#include"CScene.h"//シーンクラスのインクルード
#include"CText.h"//テキストクラスのインクルード
#include"CKey.h"//キークラスのインクルード
#include"CDummy.h"
#include"CCollisionManager.h"
#include"CCamera.h"
extern CText*mText;
extern CTaskManager TaskManager;
extern CCollisionManager CollisionManager;

/*
タイトルシーン
*/
//CSceneクラスを継承する
class CSelectAH1SD :public CScene{
public:
	CModel mAH1;
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
	~CSelectAH1SD();
};
#endif
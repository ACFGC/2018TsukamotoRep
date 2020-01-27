#ifndef CSELECTAH6SD_H
#define CSELECTAH6SD_H
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
class CSelectAH6SD :public CScene{
public:
	CModel mAH6;
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
	~CSelectAH6SD();
};
#endif
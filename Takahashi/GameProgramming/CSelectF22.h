#ifndef CSELECTF22_H
#define CSELECTF22_H
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
class CSelectF22 :public CScene{
public:
	CModel mF22;
	CDummy*mSDummy;
	CSelectF22*mSelectF22;
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
	~CSelectF22();
};
#endif
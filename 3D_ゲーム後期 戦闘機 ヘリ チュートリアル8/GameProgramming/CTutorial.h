#ifndef CTUTORIAL_H
#define CTUTORIAL_H
#include"CScene.h"
#include"CVector.h"
#include"CMatrix.h"
#include"CModel.h"
#include"CCamera.h"
#include"CCharacter.h"
#include"CPlayer.h"
#include"CTaskManager.h"
#include"CCollisionManager.h"
#include"CDummy.h"
#include"CText.h"
/*
ゲームのシーン
*/
//CSceneクラスを継承する
class CTutorial : public CScene {
public:
	CModel mModel;
	CModel mSky;
	//航空機(モデル)
	CModel mC5;
	//カメラ
	CCamera mCamera;
	//プレイヤー
	CPlayer mPlayer;
	//次のシーンの取得
	EScene GetNextScene(){
		return mScene;
	}
	//初期化処理のオーバーライド
	void Init();
	//更新処理のオーバーライド
	void Update();
	//デストラクタの宣言
	~CTutorial();
};
extern CTaskManager TaskManager;
extern CCollisionManager CollisionManager;
#endif
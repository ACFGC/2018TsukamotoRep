#ifndef CTUTORIALSTANDARD_H
#define CTUTORIALSTANDARD_H
#include"CScene.h"
#include"CVector.h"
#include"CMatrix.h"
#include"CModel.h"
#include"CCamera.h"
#include"CCharacter.h"
#include"CTaskManager.h"
#include"CCollisionManager.h"
#include"CMissileStandard.h"
#include"CText.h"
#include"CPlayerStandard.h"
/*
ゲームのシーン
*/
//CSceneクラスを継承する
class CTutorialStandard : public CScene {
public:
	CModel mModel;
	CModel mSky;
	//航空機(モデル)
	CModel mC5;
	//カメラ
	CCamera mCamera;
	//プレイヤー
	CPlayerStandard mPlayer;
	//次のシーンの取得
	EScene GetNextScene(){
		return mScene;
	}
	//初期化処理のオーバーライド
	void Init();
	//更新処理のオーバーライド
	void Update();
	//デストラクタの宣言
	~CTutorialStandard();
};
extern CTaskManager TaskManager;
extern CCollisionManager CollisionManager;
#endif
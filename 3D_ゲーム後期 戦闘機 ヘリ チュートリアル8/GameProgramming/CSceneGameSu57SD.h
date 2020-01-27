#ifndef CSCENEGAMESu57SD_H
#define CSCENEGAMESu57SD_H
#include"CScene.h"
#include"CVector.h"
#include"CMatrix.h"
#include"CModel.h"
#include"CCamera.h"
#include"CCharacter.h"
#include"CPlayerStandard.h"
#include"CTaskManager.h"
#include"CCollisionManager.h"
#include"CDummy.h"
#include"CText.h"
/*
ゲームのシーン
*/
//CSceneクラスを継承する
class CSceneGameSu57SD : public CScene {
public:
	CModel mModel;
	CModel mSky;

	//航空機(モデル)
	CModel mF16;
	CModel mF15;
	CModel mF22;
	CModel mAH6;
	CModel mC5;
	CModel mSu57;
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
	~CSceneGameSu57SD();
};

extern CTaskManager TaskManager;
extern CCollisionManager CollisionManager;

#endif

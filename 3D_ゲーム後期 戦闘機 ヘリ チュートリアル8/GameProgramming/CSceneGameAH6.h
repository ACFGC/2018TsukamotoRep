#ifndef CSCENEGAMEAH6_H
#define CSCENEGAMEAH6_H
#include "CScene.h"
#include "CVector.h"
#include "CTriangle.h"
#include "CRectangle.h"
#include "CMatrix.h"
#include "CBox.h"
#include "CModel.h"
#include "CCamera.h"
#include "CCharacter.h"
#include "CPlayerAH.h"
#include "CBullet.h"
#include "CTaskManager.h"
#include "CCollisionManager.h"
#include"CMissileAH.h"
#include"CDummy.h"
#include"CText.h"
/*
ゲームのシーン
*/
//CSceneクラスを継承する
class CSceneGameAH6 : public CScene {
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
	CPlayerAH mPlayer;
	//次のシーンの取得
	EScene GetNextScene(){
		return mScene;
	}
	//初期化処理のオーバーライド
	void Init();
	//更新処理のオーバーライド
	void Update();
	//デストラクタの宣言
	~CSceneGameAH6();
};

extern CTaskManager TaskManager;
extern CCollisionManager CollisionManager;

#endif

#include"CSceneManager.h"
//タイトル
#include"CTitle.h"
//ネクストシーン
#include"CNextScene.h"
//ゲームオーバー
#include"CGameOver.h"

//チュートリアル
#include"CTutorial.h"
#include"CTutorialStandard.h"

//操作選択
#include"CTutorialOperation.h"
#include"CGameOperation.h"

//操作難易度(高)
//戦闘機(セレクト)
#include"CSelectF22.h"
#include"CSelectF15.h"
#include"CSelectSu57.h"
//戦闘機(ゲーム)
#include"CSceneGameF22.h"
#include"CSceneGameF15.h"
#include"CSceneGameSu57.h"

//操作難易度(低)
//戦闘機(セレクト)
#include"CSelectF22SD.h"
#include"CSelectF15SD.h"
#include"CSelectSu57SD.h"
//戦闘機(ゲーム)
#include"CSceneGameF22SD.h"
#include"CSceneGameF15SD.h"
#include"CSceneGameSu57SD.h"

//ヘリ(セレクト)
#include"CSelectAH1.h"
#include"CSelectAH1SD.h"
#include"CSelectAH6.h"
#include"CSelectAH6SD.h"
//ヘリ(ゲーム)
#include"CSceneGameAH.h"
#include"CSceneGameAH6.h"
//コンストラクタ
CSceneManager::CSceneManager()
: mpScene(0)
{}
//デストラクタ（削除されるときに実行されます）
CSceneManager::~CSceneManager() {
	//シーンがあれば削除
	if (mpScene)
		//シーンの削除
		delete mpScene;
	mpScene = 0;
}
//初期化処理
void CSceneManager::Init() {
	//シーンを生成し、ポインタを設定する
	mpScene = new Title();
	//生成したクラスのメソッドが呼ばれる
	mpScene->Init();
}
//更新処理
void CSceneManager::Update() {
	//ポインタのUpdateを呼ぶ
	mpScene->Update();
	//次のシーンを取得し異なるか判定
	if (mScene != mpScene->GetNextScene()){
		mScene = mpScene->GetNextScene();
		delete mpScene;//今のシーン削除
		//該当するシーンを生成
		switch (mScene){
        //タイトル生成
		case CScene::ETITLE:
			mpScene = new Title();
			mpScene->Init();
			break;
		//チュートリアル生成
		case CScene::ETUTORIAL:
			mpScene = new CTutorial();
			mpScene->Init();
			break;
		case CScene::ETUTORIALSTANDARD:
			mpScene = new CTutorialStandard();
			mpScene->Init();
			break;

		//操作選択生成
		case CScene::ETUTORIALOPERATION:
			mpScene = new CTutorialOperation();
			mpScene->Init();
			break;
		case CScene::EGAMEOPERATION:
			mpScene = new CGameOperation();
			mpScene->Init();
			break;

		//操作難易度(高)
		//戦闘機(セレクト)
		case CScene::ESELECTF22:
			mpScene = new CSelectF22();
			mpScene->Init();
			break;
		case CScene::ESELECTF15:
			mpScene = new CSelectF15();
			mpScene->Init();
			break;
		case CScene::ESELECTSu57:
			mpScene = new CSelectSu57();
			mpScene->Init();
			break;
		//戦闘機(ゲーム)
		case CScene::EGAMEF22:
			mpScene = new CSceneGameF22();
			mpScene->Init();
			break;
		case CScene::EGAMEF15:
			mpScene = new CSceneGameF15();
			mpScene->Init();
			break;
		case CScene::EGAMESu57:
			mpScene = new CSceneGameSu57();
			mpScene->Init();
			break;

		//操作難易度(低)
		//戦闘機(セレクト)
		case CScene::ESELECTF22SD:
			mpScene = new CSelectF22SD();
			mpScene->Init();
			break;
		case CScene::ESELECTF15SD:
			mpScene = new CSelectF15SD();
			mpScene->Init();
			break;
		case CScene::ESELECTSu57SD:
			mpScene = new CSelectSu57SD();
			mpScene->Init();
			break;
		//戦闘機(ゲーム)
		case CScene::EGAMEF22SD:
			mpScene = new CSceneGameF22SD();
			mpScene->Init();
			break;
		case CScene::EGAMEF15SD:
			mpScene = new CSceneGameF15SD();
			mpScene->Init();
			break;
		case CScene::EGAMESu57SD:
			mpScene = new CSceneGameSu57SD();
			mpScene->Init();
			break;

		//ヘリ(セレクト)
		case CScene::ESELECTAH1:
			mpScene = new CSelectAH1();
			mpScene->Init();
			break;
		case CScene::ESELECTAH1SD:
			mpScene = new CSelectAH1SD();
			mpScene->Init();
			break;
		case CScene::ESELECTAH6:
			mpScene = new CSelectAH6();
			mpScene->Init();
			break;
		case CScene::ESELECTAH6SD:
			mpScene = new CSelectAH6SD();
			mpScene->Init();
			break;
		//ヘリ(ゲーム)
		case CScene::EGAMEAH1:
			mpScene = new CSceneGameAH();
			mpScene->Init();
			break;
		case CScene::EGAMEAH6:
			mpScene = new CSceneGameAH6();
			mpScene->Init();
			break;

		//ゲームオーバー
		case CScene::EGAMEOVER:
			mpScene = new CGameOver();
			mpScene->Init();
			break;
		/*
		case CScene::EGAMECLEAR:
			mpScene = new CGameclear();
			mpScene->Init();
			break;*/
		}
	}
}

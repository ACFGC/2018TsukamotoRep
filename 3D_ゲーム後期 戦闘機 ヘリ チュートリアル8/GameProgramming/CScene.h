#ifndef CSCENE_H
#define CSCENE_H

/*
シーンの基底クラス
*/
class CScene {
public:
	//シーンの識別子
	enum EScene{
		//タイトル
		ETITLE,
		//ゲームクリア
		EGAMEOVER,
		//ゲームオーバー
		EGAMECLEAR,
		//チュートリアル
		ETUTORIAL,
		//戦闘機(セレクト画面)
		ESELECTF22,
		ESELECTF15,
		ESELECTSu57,
		//戦闘機(ゲーム画面)
		EGAMEF22,
		EGAMEF15,
		EGAMESu57,
		//ヘリコプター(セレクト画面)
		ESELECTAH1,
		ESELECTAH6,
		//ヘリコプター(ゲーム画面)
		EGAMEAH1,
		EGAMEAH6,
	};
	//次のシーン
	EScene mScene;
	//virtual 仮想関数
	//ポリモーフィズムの実装
	//=0 純粋仮想関数の設定
	virtual void Init() = 0;	//純粋仮想関数 初期化処理
	virtual void Update() = 0; //純粋仮想関数 更新処理
	//次のシーンの取得
	virtual EScene GetNextScene() = 0;
	virtual ~CScene() {}	//デストラクタの定義
};


#endif

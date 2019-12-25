#ifndef CNEXTSCENE_H
#define CNEXTSCENE_H
//シーンクラス
#include"CScene.h"
//動的配列
#include<vector>
//キャラクタクラス
#include"CCharacter.h"
#include"CTask.h"
#define DISP_XS 16*8//画面の開始X相対位置
#define DISP_W 400*2//画面の幅（半分）
#define DISP_H 300*2//画面の高さ（半分）

/*
ゲームシーンの基底クラス
キャラクターのリストを保持する
リストのメンバーを更新する
リストのメンバー同士を衝突判定する
リストのメンバーを描画する
リストから無効なメンバーを削除する
リストのメンバーを全削除する
*/
class CNextScene :public CScene{
	//衝突判定
	void Collision();
	//描画
	void Render();
	//無効なメンバを削除
	void Remove();
	//メンバ全削除
	void Destroy();
public:
	~CNextScene(){
		Destroy();
	}
	//vector 動的配列
	//キャラクタのリスト
	static std::vector<CTask*>mCharacters;
	//カメラの設定
	//left: ワールド座標の左 bottom:ワールド座標の下
	void SetCamera(int left, int bottom);
	//初期化処理
	void Init();
	//更新処理
	void Update();
	//シーン切り替え
	EScene GetNextScene();
};
#endif
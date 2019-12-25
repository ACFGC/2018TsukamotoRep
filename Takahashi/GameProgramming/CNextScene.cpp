#include"CNextScene.h"
//キャラクターのリスト
std::vector<CTask*>CNextScene::mCharacters;
//初期化処理のオーバーライド
void CNextScene::Init(){
}
//更新処理のオーバーライド
void CNextScene::Update(){
	//更新処理
	for (int i = 0; i<mCharacters.size(); i++){
		mCharacters[i]->Update();
	}
	//衝突処理
	Collision();
	//描画処理
	Render();
	//削除処理
	Remove();
}
//次のシーンの取得
CScene::EScene CNextScene::GetNextScene(){
	return mScene;
}
/*
カメラの設定
*/
void CNextScene::SetCamera(int left, int bottom){
	glMatrixMode(GL_PROJECTION);//行列をプロジェクションモードへ変更
	glLoadIdentity();//行列を初期化
	//2D画面表示領域を設定
	//画面の左座標，画面の右座標，画面の下座標，画面の上座標
	gluOrtho2D(
		left, left + DISP_W
		, bottom, bottom + DISP_H);//2Dの画面を設定
	glMatrixMode(GL_MODELVIEW);//行列をモデルビューモードへ変更
}
void CNextScene::Collision(){
	for (int i = 0; i<mCharacters.size() - 1; i++){
		for (int j = i + 1; j<mCharacters.size(); j++){
			mCharacters[i]->Collision(mCharacters[i], mCharacters[j]);
			mCharacters[j]->Collision(mCharacters[j], mCharacters[i]);
		}
	}
}
void CNextScene::Render(){
	for (int i = 0; i<mCharacters.size(); i++){
		mCharacters[i]->Render();
	}
}
void CNextScene::Remove(){
	//イテレータの生成
	std::vector<CTask*>::iterator itr;
	//イテレータを先頭
	itr = mCharacters.begin();
	//最後まで繰り返し
	while (itr != mCharacters.end()){
		if ((*itr)->mEnabled){
			//次へ
			itr++;
		}
		else{
			//falseのインスタンスを削除
			delete*itr;
			//リストからも削除
			itr = mCharacters.erase(itr);
		}
	}
}
void CNextScene::Destroy(){
	for (int i = 0; i<mCharacters.size(); i++){
		delete mCharacters[i];
	}
	mCharacters.clear();
}
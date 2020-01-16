#include"CSceneManager.h"
//�^�C�g��
#include"CTitle.h"
//�l�N�X�g�V�[��
#include"CNextScene.h"
//�Q�[���I�[�o�[
#include"CGameOver.h"
//�`���[�g���A��
#include"CTutorial.h"
//�퓬�@(�Z���N�g)
#include"CSelectF22.h"
#include"CSelectF15.h"
#include"CSelectSu57.h"
//�퓬�@(�Q�[��)
#include"CSceneGameF22.h"
#include"CSceneGameF15.h"
#include"CSceneGameSu57.h"
//�w��(�Z���N�g)
#include"CSelectAH1.h"
#include"CSelectAH6.h"
//�w��(�Q�[��)
#include"CSceneGameAH.h"
#include"CSceneGameAH6.h"
//�R���X�g���N�^
CSceneManager::CSceneManager()
: mpScene(0)
{}
//�f�X�g���N�^�i�폜�����Ƃ��Ɏ��s����܂��j
CSceneManager::~CSceneManager() {
	//�V�[��������΍폜
	if (mpScene)
		//�V�[���̍폜
		delete mpScene;
	mpScene = 0;
}
//����������
void CSceneManager::Init() {
	//�V�[���𐶐����A�|�C���^��ݒ肷��
	mpScene = new Title();
	//���������N���X�̃��\�b�h���Ă΂��
	mpScene->Init();
}
//�X�V����
void CSceneManager::Update() {
	//�|�C���^��Update���Ă�
	mpScene->Update();
	//���̃V�[�����擾���قȂ邩����
	if (mScene != mpScene->GetNextScene()){
		mScene = mpScene->GetNextScene();
		delete mpScene;//���̃V�[���폜
		//�Y������V�[���𐶐�
		switch (mScene){
        //�^�C�g������
		case CScene::ETITLE:
			mpScene = new Title();
			mpScene->Init();
			break;
		//�`���[�g���A������
		case CScene::ETUTORIAL:
			mpScene = new CTutorial();
			mpScene->Init();
			break;
		//�퓬�@(�Z���N�g)
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
		//�퓬�@(�Q�[��)
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
		//�w��(�Z���N�g)
		case CScene::ESELECTAH1:
			mpScene = new CSelectAH1();
			mpScene->Init();
			break;
		case CScene::ESELECTAH6:
			mpScene = new CSelectAH6();
			mpScene->Init();
			break;
		//�w��(�Q�[��)
		case CScene::EGAMEAH1:
			mpScene = new CSceneGameAH();
			mpScene->Init();
			break;
		case CScene::EGAMEAH6:
			mpScene = new CSceneGameAH6();
			mpScene->Init();
			break;
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

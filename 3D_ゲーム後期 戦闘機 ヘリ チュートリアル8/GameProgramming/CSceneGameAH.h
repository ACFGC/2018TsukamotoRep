#ifndef CSCENEGAMEAH_H
#define CSCENEGAMEAH_H
#include"CScene.h"
#include"CVector.h"
#include"CMatrix.h"
#include"CModel.h"
#include"CCamera.h"
#include"CCharacter.h"
#include"CPlayerAH.h"
#include"CTaskManager.h"
#include"CCollisionManager.h"
#include"CDummy.h"
#include"CText.h"
/*
�Q�[���̃V�[��
*/
//CScene�N���X���p������
class CSceneGameAH : public CScene {
public:
	CModel mModel;
	CModel mSky;

	//�q��@(���f��)
	CModel mF16;
	CModel mF15;
	CModel mF22;
	CModel mAH6;
	CModel mC5;
	CModel mSu57;
	//�J����
	CCamera mCamera;
	//�v���C���[
	CPlayerAH mPlayer;
	//���̃V�[���̎擾
	EScene GetNextScene(){
		return mScene;
	}
	//�����������̃I�[�o�[���C�h
	void Init();
	//�X�V�����̃I�[�o�[���C�h
	void Update();
	//�f�X�g���N�^�̐錾
	~CSceneGameAH();
};

extern CTaskManager TaskManager;
extern CCollisionManager CollisionManager;

#endif

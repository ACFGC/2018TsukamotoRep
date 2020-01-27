#ifndef CSCENEGAMEF22SD_H
#define CSCENEGAMEF22SD_H
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
�Q�[���̃V�[��
*/
//CScene�N���X���p������
class CSceneGameF22SD : public CScene {
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
	CModel mAAM;
	//�J����
	CCamera mCamera;
	//�v���C���[
	CPlayerStandard mPlayer;
	//���̃V�[���̎擾
	EScene GetNextScene(){
		return mScene;
	}
	//����
	int mTime = 30 * 60;
	//�����������̃I�[�o�[���C�h
	void Init();
	//�X�V�����̃I�[�o�[���C�h
	void Update();
	//�f�X�g���N�^�̐錾
	~CSceneGameF22SD();
};

extern CTaskManager TaskManager;
extern CCollisionManager CollisionManager;

#endif

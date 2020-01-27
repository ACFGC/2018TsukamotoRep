#ifndef CTUTORIAL_H
#define CTUTORIAL_H
#include"CScene.h"
#include"CVector.h"
#include"CMatrix.h"
#include"CModel.h"
#include"CCamera.h"
#include"CCharacter.h"
#include"CPlayer.h"
#include"CTaskManager.h"
#include"CCollisionManager.h"
#include"CDummy.h"
#include"CText.h"
/*
�Q�[���̃V�[��
*/
//CScene�N���X���p������
class CTutorial : public CScene {
public:
	CModel mModel;
	CModel mSky;
	//�q��@(���f��)
	CModel mC5;
	//�J����
	CCamera mCamera;
	//�v���C���[
	CPlayer mPlayer;
	//���̃V�[���̎擾
	EScene GetNextScene(){
		return mScene;
	}
	//�����������̃I�[�o�[���C�h
	void Init();
	//�X�V�����̃I�[�o�[���C�h
	void Update();
	//�f�X�g���N�^�̐錾
	~CTutorial();
};
extern CTaskManager TaskManager;
extern CCollisionManager CollisionManager;
#endif
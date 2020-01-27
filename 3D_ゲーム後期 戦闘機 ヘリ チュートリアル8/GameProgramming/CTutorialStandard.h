#ifndef CTUTORIALSTANDARD_H
#define CTUTORIALSTANDARD_H
#include"CScene.h"
#include"CVector.h"
#include"CMatrix.h"
#include"CModel.h"
#include"CCamera.h"
#include"CCharacter.h"
#include"CTaskManager.h"
#include"CCollisionManager.h"
#include"CMissileStandard.h"
#include"CText.h"
#include"CPlayerStandard.h"
/*
�Q�[���̃V�[��
*/
//CScene�N���X���p������
class CTutorialStandard : public CScene {
public:
	CModel mModel;
	CModel mSky;
	//�q��@(���f��)
	CModel mC5;
	//�J����
	CCamera mCamera;
	//�v���C���[
	CPlayerStandard mPlayer;
	//���̃V�[���̎擾
	EScene GetNextScene(){
		return mScene;
	}
	//�����������̃I�[�o�[���C�h
	void Init();
	//�X�V�����̃I�[�o�[���C�h
	void Update();
	//�f�X�g���N�^�̐錾
	~CTutorialStandard();
};
extern CTaskManager TaskManager;
extern CCollisionManager CollisionManager;
#endif
#ifndef CSCENEGAMESu57_H
#define CSCENEGAMESu57_H
#include "CScene.h"
#include "CVector.h"
#include "CTriangle.h"
#include "CRectangle.h"
#include "CMatrix.h"
#include "CBox.h"
#include "CModel.h"
#include "CCamera.h"
#include "CCharacter.h"
#include "CPlayer.h"
#include "CBullet.h"
#include "CTaskManager.h"
#include "CCollisionManager.h"
#include"CMissile.h"
#include"CDummy.h"
#include"CText.h"
/*
�Q�[���̃V�[��
*/
//CScene�N���X���p������
class CSceneGameSu57 : public CScene {
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
	~CSceneGameSu57();
};

extern CTaskManager TaskManager;
extern CCollisionManager CollisionManager;

#endif
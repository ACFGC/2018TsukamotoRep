#ifndef CSELECTAH6SD_H
#define CSELECTAH6SD_H
#include"CScene.h"//�V�[���N���X�̃C���N���[�h
#include"CText.h"//�e�L�X�g�N���X�̃C���N���[�h
#include"CKey.h"//�L�[�N���X�̃C���N���[�h
#include"CDummy.h"
#include"CCollisionManager.h"
#include"CCamera.h"
extern CText*mText;
extern CTaskManager TaskManager;
extern CCollisionManager CollisionManager;
/*
�^�C�g���V�[��
*/
//CScene�N���X���p������
class CSelectAH6SD :public CScene{
public:
	CModel mAH6;
	CDummy*mSDummy;
	//�J����
	CCamera mCamera;
	//���̃V�[���̎擾
	EScene GetNextScene(){
		return mScene;
	}
	//�����������̃I�[�o�[���C�h
	void Init();
	//�X�V�����̃I�[�o�[���C�h
	void Update();
	//�f�X�g���N�^�̐錾
	~CSelectAH6SD();
};
#endif
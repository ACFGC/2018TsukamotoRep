#ifndef CSELECTF15SD_H
#define CSELECTF15SD_H
#include"CScene.h"//�V�[���N���X�̃C���N���[�h
#include"CText.h"//�e�L�X�g�N���X�̃C���N���[�h
#include"CKey.h"//�L�[�N���X�̃C���N���[�h
#include"CDummy.h"
#include"CCamera.h"
#include"CCollisionManager.h"
extern CText*mText;
extern CTaskManager TaskManager;
extern CCollisionManager CollisionManager;
/*
�^�C�g���V�[��
*/
//CScene�N���X���p������
class CSelectF15SD :public CScene{
public:
	CModel mF15;
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
	~CSelectF15SD();
};
#endif
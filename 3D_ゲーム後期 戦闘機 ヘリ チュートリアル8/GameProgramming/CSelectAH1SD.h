#ifndef CSELECTAH1SD_H
#define CSELECTAH1SD_H
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
class CSelectAH1SD :public CScene{
public:
	CModel mAH1;
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
	~CSelectAH1SD();
};
#endif
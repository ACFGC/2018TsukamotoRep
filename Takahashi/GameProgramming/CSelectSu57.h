#ifndef CSELECTSu57_H
#define CSELECTSu57_H
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
class CSelectSu57 :public CScene{
public:
	CModel mSu57;
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
	~CSelectSu57();
};
#endif
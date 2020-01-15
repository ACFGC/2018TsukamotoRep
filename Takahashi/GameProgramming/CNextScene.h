#ifndef CNEXTSCENE_H
#define CNEXTSCENE_H
//�V�[���N���X
#include"CScene.h"
//���I�z��
#include<vector>
//�L�����N�^�N���X
#include"CCharacter.h"
#include"CTask.h"
#define DISP_XS 16*8//��ʂ̊J�nX���Έʒu
#define DISP_W 400*2//��ʂ̕��i�����j
#define DISP_H 300*2//��ʂ̍����i�����j

/*
�Q�[���V�[���̊��N���X
�L�����N�^�[�̃��X�g��ێ�����
���X�g�̃����o�[���X�V����
���X�g�̃����o�[���m���Փ˔��肷��
���X�g�̃����o�[��`�悷��
���X�g���疳���ȃ����o�[���폜����
���X�g�̃����o�[��S�폜����
*/
class CNextScene :public CScene{
	//�Փ˔���
	void Collision();
	//�`��
	void Render();
	//�����ȃ����o���폜
	void Remove();
	//�����o�S�폜
	void Destroy();
public:
	~CNextScene(){
		Destroy();
	}
	//vector ���I�z��
	//�L�����N�^�̃��X�g
	static std::vector<CTask*>mCharacters;
	//�J�����̐ݒ�
	//left: ���[���h���W�̍� bottom:���[���h���W�̉�
	void SetCamera(int left, int bottom);
	//����������
	void Init();
	//�X�V����
	void Update();
	//�V�[���؂�ւ�
	EScene GetNextScene();
};
#endif
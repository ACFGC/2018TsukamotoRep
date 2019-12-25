#ifndef CSCENE_H
#define CSCENE_H

/*
�V�[���̊��N���X
*/
class CScene {
public:
	//�V�[���̎��ʎq
	enum EScene{
		//�^�C�g��
		ETITLE,
		//�Q�[���N���A
		EGAMEOVER,
		//�Q�[���I�[�o�[
		EGAMECLEAR,
		//�`���[�g���A��
		ETUTORIAL,
		//�퓬�@(�Z���N�g���)
		ESELECTF22,
		ESELECTF15,
		ESELECTSu57,
		//�퓬�@(�Q�[�����)
		EGAMEF22,
		EGAMEF15,
		EGAMESu57,
		//�w���R�v�^�[(�Z���N�g���)
		ESELECTAH1,
		ESELECTAH6,
		//�w���R�v�^�[(�Q�[�����)
		EGAMEAH1,
		EGAMEAH6,
	};
	//���̃V�[��
	EScene mScene;
	//virtual ���z�֐�
	//�|�����[�t�B�Y���̎���
	//=0 �������z�֐��̐ݒ�
	virtual void Init() = 0;	//�������z�֐� ����������
	virtual void Update() = 0; //�������z�֐� �X�V����
	//���̃V�[���̎擾
	virtual EScene GetNextScene() = 0;
	virtual ~CScene() {}	//�f�X�g���N�^�̒�`
};


#endif

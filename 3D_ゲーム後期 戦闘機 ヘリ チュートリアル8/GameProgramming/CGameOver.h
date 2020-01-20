#include"CScene.h"//�V�[���N���X�̃C���N���[�h
#include"CText.h"//�e�L�X�g�N���X�̃C���N���[�h
#include"CKey.h"//�L�[�N���X�̃C���N���[�h
#include<Windows.h>
extern CText*mText;
/*
�Q�[���I�[�o�[�V�[��
*/
//CScene�N���X���p������
class CGameOver :public CScene{
public:
	//���̃V�[���̎擾
	EScene GetNextScene(){
		return mScene;
	}
	//�����������̃I�[�o�[���C�h
	void Init(){
		//�t�H���g�̐ݒ�
		//�e�N�X�`���t�@�C����ǂݍ���
		CText::mFont.Load("font.tga");
		mScene = EGAMEOVER;
	}
	//�X�V�����̃I�[�o�[���C�h
	void Update(){
		if (CKey::Once(VK_RETURN)){
			//���̓^�C�g��
			mScene = ETITLE;
		}
		//2D���W��UI��`��
		//�s����v���W�F�N�V�������[�h�֕ύX
		glMatrixMode(GL_PROJECTION);
		glPushMatrix();		//�v���W�F�N�V�����s���ޔ�
		glLoadIdentity();	//�v���W�F�N�V�����s���������
		//�v���W�F�N�V�����s���800�~600�ɐݒ�
		gluOrtho2D(-400, 400, -300, 300);
		//�s������f���r���[���[�h�֕ύX
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();		//���f���r���[�s���ޔ�
		glLoadIdentity();	//���f���r���[�s���������

		glDisable(GL_LIGHTING);	//���C�g����
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);	//�`��F

		//������ݒ�
		//������̕`��
		mText->DrawString("GAME OVER", -200, 100, 25, 25);
		glEnable(GL_LIGHTING);	//���C�h�L��

		glPopMatrix();	//���f���r���[�`��s���߂�
		//�s����v���W�F�N�V�������[�h�֕ύX
		glMatrixMode(GL_PROJECTION);
		glPopMatrix();	//�v���W�F�N�V�����s���߂�
		//�s������f���r���[���[�h�֕ύX
		glMatrixMode(GL_MODELVIEW);
	}
};
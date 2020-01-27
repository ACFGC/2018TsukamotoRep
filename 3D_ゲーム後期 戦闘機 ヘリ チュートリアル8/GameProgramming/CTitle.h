#include"CScene.h"//�V�[���N���X�̃C���N���[�h
#include"CText.h"//�e�L�X�g�N���X�̃C���N���[�h
#include"CKey.h"//�L�[�N���X�̃C���N���[�h
#include<Windows.h>
extern CText*mText;
/*
�^�C�g���V�[��
*/
//CScene�N���X���p������
class Title :public CScene{
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
		mScene = ETITLE;
	}
	//�X�V�����̃I�[�o�[���C�h
	void Update(){
		if (CKey::Once(VK_RETURN)){
			//���͑���I��
			mScene = EGAMEOPERATION;
		}
		if (CKey::Once(' ')){
			//���̓`���[�g���A��
			mScene = ETUTORIALOPERATION;
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
		mText->DrawString("Aerial warfare", -320, 200, 25, 25);
		mText->DrawString("Play the Game", -250, 50, 20, 20);
		mText->DrawString("Push ENTER Key", -200, 0, 14, 14);
		mText->DrawString("Tutorial", -150, -150, 20, 20);
		mText->DrawString("Push SPACE Key", -200, -200, 16, 16);
		glEnable(GL_LIGHTING);	//���C�h�L��

		glPopMatrix();	//���f���r���[�`��s���߂�
		//�s����v���W�F�N�V�������[�h�֕ύX
		glMatrixMode(GL_PROJECTION);
		glPopMatrix();	//�v���W�F�N�V�����s���߂�
		//�s������f���r���[���[�h�֕ύX
		glMatrixMode(GL_MODELVIEW);
	}
};
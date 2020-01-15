#include"CSelectAH6.h"
//�����������̃I�[�o�[���C�h
void CSelectAH6::Init(){
	//�t�H���g�̐ݒ�
	//�e�N�X�`���t�@�C����ǂݍ���
	CText::mFont.Load("font.tga");
	mScene = ESELECTAH6;
	//mKeyInterval = KeyInterval;
	mAH6.Load("AH6.obj", "AH6.mtl");
	mSDummy = new CDummy(&mAH6, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.9f, 0.9f, 0.9f);
}
//�X�V�����̃I�[�o�[���C�h
void CSelectAH6::Update(){
	TaskManager.Update();
	CollisionManager.Update();
	TaskManager.Delete();
	mSDummy->mRotation = mSDummy->mRotation + CVector(0.0f, 2.0f, 0.0f);
	if (CKey::Once(VK_BACK)){
		//���̃V�[���̓^�C�g��
		mScene = ETITLE;
	}
	if (CKey::Once('A')){
		//���̃V�[����AH1
		mScene = ESELECTAH1;
	}
	if (CKey::Once('D')){
		//���̃V�[����F22
		mScene = ESELECTF22;
	}
	if (CKey::Once(VK_RETURN)){
		//���̃V�[���̓Q�[��AH
		mScene = EGAMEAH6;
	}
	mCamera.Render();
	TaskManager.Render();
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
	//�q��@
	mText->DrawString("F22", -350, 270, 15, 15);
	mText->DrawString("F15", -350, 235, 15, 15);
	mText->DrawString("Su50", -350, 200, 15, 15);
	mText->DrawString("AH1", -350, 165, 15, 15);
	mText->DrawString("AH6<", -350, 130, 20, 20);
	//���̍q��@
	mText->DrawString("<<NEXT", -380, 25, 10, 10);
	mText->DrawString("Push A Key", -380, 0, 8, 8);
	mText->DrawString("NEXT>>", 290, 25, 10, 10);
	mText->DrawString("Push D Key", 250, 0, 8, 8);
	//����
	mText->DrawString("Play this AirCraft!", -250, -100, 16, 16);
	mText->DrawString("Push ENTER Key", -200, -200, 16, 16);
	glEnable(GL_LIGHTING);	//���C�h�L��

	glPopMatrix();	//���f���r���[�`��s���߂�
	//�s����v���W�F�N�V�������[�h�֕ύX
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();	//�v���W�F�N�V�����s���߂�
	//�s������f���r���[���[�h�֕ύX
	glMatrixMode(GL_MODELVIEW);
}
//�f�X�g���N�^
CSelectAH6::~CSelectAH6() {
	TaskManager.Destory();
}

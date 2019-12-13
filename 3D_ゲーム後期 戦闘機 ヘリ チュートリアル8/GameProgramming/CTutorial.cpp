#include"CTutorial.h"
#include "glut.h"
#include "CTriangle.h"
#include "CKey.h"
#include "CEnemy.h"
#include "CFire.h"
#include <math.h>
//�G�̊O���ϐ����Ă�
extern CEnemy*Enemy;
//�e�L�X�g�̊O���ϐ����Ă�
extern CText*mText;
CTutorial*mTutorial;
void CTutorial::Init() {
	//�V�[���ݒ�
	mScene = ETUTORIAL;
	//�q��@(���f��)�ǂݍ���
	mModel.Load("F15C.obj", "F15C.mtl");
	mSky.Load("sky.obj", "sky.mtl");
	mC5.Load("C5.obj", "C5.mtl");
	//���f�����蓖��
	mPlayer.Init(&mModel, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.4f, 0.4f, 0.4f);
	new CDummy(&mC5, 16.0f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.1f, 0.1f, 0.1f);
}

void CTutorial::Update() {

	mPlayer.Update();
	TaskManager.Update();
	CollisionManager.Update();
	TaskManager.Delete();

	//�J�����ݒ�
	mCamera.mEye = mPlayer.mPosition + CVector(0.0f, 2.0f, -8.0f) * mPlayer.mMatrixRotation;
	mCamera.mCenter = mPlayer.mPosition;
	mCamera.mUp = CVector(0.0f, 1.0f, 0.0f) * mPlayer.mMatrixRotation;
	//��������
	if (CKey::Push('C')) {
		mCamera.mEye = mPlayer.mPosition - CVector(0.0f, -2.0f, -8.0f) * mPlayer.mMatrixRotation;
	}
	if (CKey::Once(VK_BACK)){
		//�^�C�g���ɖ߂�
		mScene = ETITLE;
	}
	mCamera.Render();

	mSky.Render(CMatrix());
	mPlayer.Render();
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
	mText->DrawString("M:Missile W:PitUP A:< S:PitDOWN D:>", -350, 250, 10, 20);//������`��
	if (CKey::Once('H')){
		//mText->DrawString("AAAAA", -250, 150, 10, 20);//������`��
	}
	//"SPACE:Missile W:PitUP A:LeftROLL S:PitDOWN D:RightROLL"
	glEnable(GL_LIGHTING);	//���C�h�L��

	glPopMatrix();	//���f���r���[�`��s���߂�
	//�s����v���W�F�N�V�������[�h�֕ύX
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();	//�v���W�F�N�V�����s���߂�
	//�s������f���r���[���[�h�֕ύX
	glMatrixMode(GL_MODELVIEW);
}
//�f�X�g���N�^
CTutorial::~CTutorial() {
	TaskManager.Destory();
}
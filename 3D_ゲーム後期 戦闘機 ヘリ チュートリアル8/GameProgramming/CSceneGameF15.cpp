#include "CSceneGameF15.h"
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
void CSceneGameF15::Init() {
	//�V�[���ݒ�
	mScene = EGAMEF15;
	//�q��@(���f��)�ǂݍ���
	mModel.Load("F15.obj", "F15.mtl");
	mSky.Load("sky.obj", "sky.mtl");
	mF16.Load("f16.obj", "f16.mtl");
	mF15.Load("F15.obj", "F15.mtl");
	mF22.Load("F22.obj", "F22.mtl");
	mSu57.Load("Su57.obj", "Su57.mtl");
	mAH6.Load("AH6.obj", "AH6.mtl");
	mC5.Load("C5.obj", "C5.mtl");
	//���f�����蓖��
	mPlayer.Init(&mModel, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.1f, 0.1f, 0.1f);
	Enemy = new CEnemy(&mF22, 0.0f, 13.0f, 6.0f, 0.0f, 0.0f, 0.0f, 0.2f, 0.2f, 0.2f);
	Enemy = new CEnemy(&mSu57, 0.0f, 17.0f, 6.0f, 0.0f, 0.0f, 0.0f, 0.2f, 0.2f, 0.2f);
}

void CSceneGameF15::Update() {

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
CSceneGameF15::~CSceneGameF15() {
	TaskManager.Destory();
}

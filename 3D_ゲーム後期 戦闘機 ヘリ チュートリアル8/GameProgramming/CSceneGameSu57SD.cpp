#include"CSceneGameSu57SD.h"
#include"glut.h"
#include"CTriangle.h"
#include"CKey.h"
#include"CEnemyStandard.h"
#include<math.h>
//�^�X�N�}�l�[�W���[�̊O���ϐ����Ă�
extern CTaskManager TaskManager;
//�R���W�����}�l�[�W���[�̊O���ϐ����Ă�
extern CCollisionManager CollisionManager;
//�G�̊O���ϐ����Ă�
extern CEnemyStandard*Enemy;
//�e�L�X�g�̊O���ϐ����Ă�
extern CText*mText;
//����
//int mTime = 30 * 60;
#define Time 100
void CSceneGameSu57SD::Init() {
	//�V�[���ݒ�
	mScene = EGAMESu57SD;
	//��(���f��)
	mSky.Load("sky.obj", "sky.mtl");
	//�q��@(���f��)�ǂݍ���
	mModel.Load("Su57.obj", "Su57.mtl");
	mSu57.Load("Su57.obj", "Su57.mtl");
	/*
	mF16.Load("f16.obj", "f16.mtl");
	mF15.Load("F15.obj", "F15.mtl");
	mF22.Load("F22.obj", "F22.mtl");
	mAH6.Load("AH6.obj", "AH6.mtl");
	mC5.Load("C5.obj", "C5.mtl");*/
	//���f�����蓖��
	mPlayer.Init(&mModel, 0.0f, 5.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.2f, 0.2f, 0.2f);
	Enemy = new CEnemyStandard(&mSu57, 0.0f, 13.0f, 6.0f, 0.0f, 0.0f, 0.0f, 0.2f, 0.2f, 0.2f);
	Enemy = new CEnemyStandard(&mSu57, 0.0f, 17.0f, 6.0f, 0.0f, 0.0f, 0.0f, 0.2f, 0.2f, 0.2f);
}

void CSceneGameSu57SD::Update() {

	mPlayer.Update();
	TaskManager.Update();
	CollisionManager.Update();
	TaskManager.Delete();
	/*if (mTime > 0){
	mTime--;
	}
	if (mTime <= 0){
	mTime = Time;
	}
	if (mTime <= 0&&Enemy->mEnabled==false){
	mTime = Time;
	Enemy = new CEnemy(&mF15, 0.0f, 13.0f, 6.0f, 0.0f, 0.0f, 0.0f, 0.2f, 0.2f, 0.2f);
	Enemy = new CEnemy(&mSu57, 0.0f, 17.0f, 6.0f, 0.0f, 0.0f, 0.0f, 0.2f, 0.2f, 0.2f);
	}*/
	//�J�����ݒ�
	mCamera.mEye = mPlayer.mPosition + CVector(0.0f, 0.6f, -2.7f) * mPlayer.mMatrixRotation;
	mCamera.mCenter = mPlayer.mPosition;
	mCamera.mUp = CVector(0.0f, 1.0f, 0.0f) * mPlayer.mMatrixRotation;
	//��������
	if (CKey::Push('C')) {
		mCamera.mEye = mPlayer.mPosition - CVector(0.0f, -0.6f, -3.3f) * mPlayer.mMatrixRotation;
	}
	if (CKey::Once(VK_BACK)){
		//�Q�[���I�[�o�[
		mScene = EGAMEOVER;
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
	mText->DrawString("SCORE", -350, 270, 7, 15);//������`��
	if (CKey::Push('Q')){
		mText->DrawString("M Key:Missile         W Key:PitchDown S Key:PitchUp", -350, -130, 7, 15);//������`��
		mText->DrawString("A Key:L Roll  D Key:R Roll", -350, -170, 7, 15);//������`��
		mText->DrawString("I Key:Throttle UP  K Key:Throttle Down", -350, -210, 7, 15);//������`��
		mText->DrawString("J Key:L Yaw  K Key:R Yaw", -350, -250, 7, 15);//������`��
	}//"SPACE:Missile W:PitUP A:LeftROLL S:PitDOWN D:RightROLL"
	glEnable(GL_LIGHTING);	//���C�h�L��

	glPopMatrix();	//���f���r���[�`��s���߂�
	//�s����v���W�F�N�V�������[�h�֕ύX
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();	//�v���W�F�N�V�����s���߂�
	//�s������f���r���[���[�h�֕ύX
	glMatrixMode(GL_MODELVIEW);
}

//�f�X�g���N�^
CSceneGameSu57SD::~CSceneGameSu57SD() {
	TaskManager.Destory();
}

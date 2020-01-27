#include"CTutorialStandard.h"
#include"glut.h"
#include"CTriangle.h"
#include"CKey.h"
#include"CEnemyStandard.h"
#include<math.h>
//�^�X�N�}�l�[�W���[�̊O���ϐ����Ă�
extern CTaskManager TaskManager;
//�R���W�����}�l�[�W���[�̊O���ϐ����Ă�
extern CCollisionManager CollisionManager;
//�G�̊O���ϐ������
 CEnemyStandard*Enemy;
//�e�L�X�g�̊O���ϐ����Ă�
extern CText*mText;
//����
//int mTime = 30 * 60;
#define Time 100
void CTutorialStandard::Init() {
	//�V�[���ݒ�
	mScene = ETUTORIALSTANDARD;
	//�q��@(���f��)�ǂݍ���
	mModel.Load("F15.obj", "F15.mtl");
	mSky.Load("sky.obj", "sky.mtl");
	mC5.Load("C5.obj", "C5.mtl");
	//���f�����蓖��
	mPlayer.Init(&mModel, 0.0f, 5.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.2f, 0.2f, 0.2f);
	Enemy = new CEnemyStandard(&mC5, 0.0f, 5.0f, 6.0f, 0.0f, 0.0f, 0.0f, 0.2f, 0.2f, 0.2f);
	Enemy = new CEnemyStandard(&mC5, 0.0f, 17.0f, 6.0f, 0.0f, 0.0f, 0.0f, 0.2f, 0.2f, 0.2f);
}

void CTutorialStandard::Update() {

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
	mCamera.mEye = mPlayer.mPosition + CVector(0.0f, 0.6f, -2.5f) * mPlayer.mMatrixRotation;
	mCamera.mCenter = mPlayer.mPosition;
	mCamera.mUp = CVector(0.0f, 1.0f, 0.0f) * mPlayer.mMatrixRotation;
	//��������
	if (CKey::Push('C')) {
		mCamera.mEye = mPlayer.mPosition - CVector(0.0f, -0.6f, -3.0f) * mPlayer.mMatrixRotation;
	}
	if (CKey::Once(VK_BACK)){
		//�Q�[���I�[�o�[
		mScene = EGAMEOVER;
	}
	/*if(CPlayer::mpPlayer->mState == CPlayer::EState::EDESTORY){
	mScene = EGAMEOVER;
	}*/
	mCamera.Render();

	mSky.Render(CMatrix());
	//mSky.Render(CMatrix().Scale(10.0f,10.0f,10.0f));
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
	//������`��
	//����\��
	if (CKey::Push('Q')){
		//�O�����
		mText->DrawString("K Key:Throttle Down", -350, -150, 7, 15);
		mText->DrawString("I Key:Throttle UP", -350, -100, 7, 15);
		//�㉺����
		mText->DrawString("W Key:PitchDown", -100, -200, 7, 15);
		mText->DrawString("S Key:PitchUp", -100, 200, 7, 15);
		//�E����
		mText->DrawString("J Key:Left Yaw", -350, 100, 7, 15);
		mText->DrawString("A Key:Left Roll", -350, 50, 7, 15);
		//������
		mText->DrawString("L Key:Right Yaw", 170, 100, 7, 15);
		mText->DrawString("D Key:Right Roll", 170, 50, 7, 15);
		//�U������
		mText->DrawString("SPACE Key:Cannon", 170, -150, 7, 15);
		mText->DrawString("M Key:Missile", 170, -100, 7, 15);
		//mText->DrawString("I Key:Throttle UP  K Key:Throttle Down", -350, -210, 7, 15);//������`��
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
CTutorialStandard::~CTutorialStandard() {
	TaskManager.Destory();
}

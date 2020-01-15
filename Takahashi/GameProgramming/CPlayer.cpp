#include"CPlayer.h"
#include"CKey.h"
#include"CBullet.h"
#include"CSceneGameF22.h"
#include"CMissile.h"
#include"CFlare.h"
#include"CFire.h"
//�~�T�C���N�[���^�C��(����)
#define FIREINTERVAL_E 100
//�t���A�N�[���^�C��(����)
#define FLAREINTERVAL_E 60
//�t���A�̊O���ϐ������
CFlare*Flare;
//�~�T�C���̊O���ϐ������
CMissile *m;
//�t�@�C�A�̊O���ϐ������
CFire *f;
//�~�T�C��(���f��)�̊O���ϐ����Ă�
extern CModel mAAM;
CPlayer *CPlayer::mpPlayer = 0;

CPlayer::CPlayer() {
	mpPlayer = this;
	mPCollider.mpParent = this;
	mPCollider.mRadius = 1.0f;
	//�^�O��ݒ�
	mTaskTag = EPLAYER;
	//�~�T�C���̃��f����ǂݍ���
	mAAM.Load("AAM.obj", "AAM.mtl");
	//HP = 100;
	/*CHpBar*hp = new CHpBar();
	hp->SetHpBar(this, CVector(0.0f,0.0f,0.0f),CVector(0.0f,0.0f,0.0f), 100.0f, 100.0f);
	hp->SetDiffuse(1.0f, 1.0f, 0.0f, 1.0f);
	hp->mPosition = mPosition;
	//��]�s���ݒ�
	hp->mMatrixRotation = mMatrixRotation;
	//TaskManager.Add(hp);*/
	/*mHpBar.Init(this, CVector(0.0f, -35.0f,0.0f),
		CVector(50.0f, 8.0f,0.0f),100,100);*/
}

CPlayer::~CPlayer() {
	mpPlayer = 0;
}

void CPlayer::Update() {
	//�퓬�@���쏈��
	//mPosition = CVector(0.0f, 0.0f, 1.5f) * mMatrix;
	//�O�i (�X���b�g���A�b�v)
	if (CKey::Push('I')) {
		mPosition = CVector(0.0f, 0.0f, 3.0f) * mMatrix;
	}
	//��i (�X���b�g���_�E��)
	if (CKey::Push('K')) {
		mPosition = CVector(0.0f, 0.0f, -2.0f) * mMatrix;
	}
	//�C�ӎ���]�ł̑���
	CMatrix mx, mz, my;
	CVector vz = CVector(0.0f, 0.0f, 1.0f)*mMatrixRotation;
	CVector vx = CVector(1.0f, 0.0f, 0.0f)*mMatrixRotation;
	CVector vy = CVector(0.0f, 1.0f, 0.0f)*mMatrixRotation;

	//���[��
	//�����[��
	if (CKey::Push('A')){
		mz.Axis(-2.0f,vz.mX, vz.mY, vz.mZ);
	}
	//�E���[��
	if (CKey::Push('D')){
		mz.Axis(2.0f,vz.mX, vz.mY, vz.mZ);
	}

	//�s�b�`
	//�s�b�`�_�E��
	if (CKey::Push('W')){
		mx.Axis(1.0f, vx.mX, vx.mY, vx.mZ);
	}
	//�s�b�`�A�b�v
	if (CKey::Push('S')){
		mx.Axis(-1.0f, vx.mX, vx.mY, vx.mZ);
	}

	//���[
	//�����[
	if (CKey::Push('J')){
		my.Axis(1.0f, vy.mX, vy.mY, vy.mZ);
	}
	//�E���[
	if (CKey::Push('L')){
		my.Axis(-1.0f, vy.mX, vy.mY, vy.mZ);
	}

	//�����ɖ߂�
	/*if (CKey::Push('Y')) {

	}*/

	//�}�j���[�o
	//�N���r�b�g
	if (CKey::Push('Z')) {
		mx.Axis(-5.0f, vx.mX, vx.mY, vx.mZ);
	}
	//�R�u��
	if (CKey::Push('X')){
		vz.mZ++;
		vy.mY++;
		vx.mX++;
	}

	mMatrixRotation = mMatrixRotation * mx * mz * my;
	mMatrix = mMatrix.Scale(mScale.mX, mScale.mY, mScale.mZ) * mMatrixRotation * 
		mMatrix.Translate(mPosition.mX, mPosition.mY, mPosition.mZ);

	//�U�� 
	//�@�֖C����
	if (CKey::Push(VK_SPACE)){
		CBullet*b = new CBullet();
		b->Set(0.0f, 0.0f, 0.0f, 0.03f, 0.03f, 0.3f);
		b->SetDiffuse(1.0f, 1.0f, 0.0f, 1.0f);
		b->mPosition = mPosition;
		//��]�s���ݒ�
		b->mMatrixRotation = mMatrixRotation;
		TaskManager.Add(b);
	}
	//�~�T�C���N�[���^�C��
	if (mMissileInterval>0){
		mMissileInterval--;
	}
	//�~�T�C������
	if (CKey::Push('M')) {
		if (mMissileInterval <= 0){
			mMissileInterval = FIREINTERVAL_E;
			m = new CMissile(&mAAM, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 3.0f, 3.0f, 3.0f);
			m->mTaskTag = EPLAYERBULLET;
			m->mPosition = mPosition;
			//m->mRotation = mRotation;
			//��]�s���ݒ�
			m->mMatrixRotation = mMatrixRotation;
			TaskManager.Add(m);
		}
	}

	//�t���A�N�[���^�C��
	if (mFlareInterval > 0){
		mFlareInterval--;
	}
	//�t���A����
	if (CKey::Push('F')) {
		if (mFlareInterval <= 0){
			mFlareInterval = FLAREINTERVAL_E;

			//�t���A
			//�t���A1
		    Flare= new CFlare();
		    Flare->Set(0.0f, 0.0f, -1.4f, 0.1f, 0.1f, 0.1f);
			//�^�O�ݒ�
			Flare->mTaskTag = EFLARE;
		    Flare->SetDiffuse(1.0f, 1.0f, 0.0f, 1.0f);
			Flare->mPosition = mPosition;
			//��]�s���ݒ�
			Flare->mMatrixRotation = mMatrixRotation;
			TaskManager.Add(Flare);
			//�t���A2
			Flare = new CFlare();
			Flare->Set(1.0f, 0.0f, -1.4f, 0.1f, 0.1f, 0.1f);
			//�^�O�ݒ�
			Flare->mTaskTag = EFLARE;
			Flare->SetDiffuse(1.0f, 1.0f, 0.0f, 1.0f);
			Flare->mPosition = mPosition;
			//��]�s���ݒ�
			Flare->mMatrixRotation = mMatrixRotation;
			TaskManager.Add(Flare);
			//�t���A3
			Flare = new CFlare();
			Flare->Set(-1.0f, 0.0f, -1.4f, 0.1f, 0.1f, 0.1f);
			//�^�O�ݒ�
			Flare->mTaskTag = EFLARE;
			Flare->SetDiffuse(1.0f, 1.0f, 0.0f, 1.0f);
			Flare->mPosition = mPosition;
			//��]�s���ݒ�
			Flare->mMatrixRotation = mMatrixRotation;
			TaskManager.Add(Flare);
		}
	}
	//mHpBar.Update();
	//CCharacter::Update();
}

void CPlayer::Collision(CCollider *m, CCollider *y) {
	if (CCollider::Collision(m, y)) {
		switch (y->mpParent->mTaskTag)
		{
		case EENEMYBULLET:
			f = new CFire();
			f->mPosition = y->mpParent->mPosition;
			f->SetTexture("fire.tga");
			TaskManager.Add(f);
			/*mHpBar.mHp -= 40.0f;
			if (mHpBar.mHp <= 0.0f){
			mEnabled = false;
			}*/
			/*HP -= 40;
			if (HP <= 0){
				//����������
				m->mpParent->mEnabled = false;
				//�����������������
				y->mpParent->mEnabled = false;
			}*/
			//����������
			m->mpParent->mEnabled = false;
			//�����������������
			y->mpParent->mEnabled = false;
			break;
		}
	}
}

/*//��ɌX������������֑O�i
if (mRotation.mX <= 50){
mPosition = mPosition + CVector(0.0f, 0.0f, 0.4f) * mMatrixRotation;
}
//���ɌX�������������֑O�i
if (mRotation.mX >= 50){
mPosition = mPosition + CVector(0.0f, 0.0f, 0.2f) * mMatrixRotation;
}*/
//�㏸
/*if (GetKeyState('I') & 0x8000){
//mainrotor.mRotation.y += 40;
//tellrotor.mRotation.x += 20;
mPosition.mY += 5;
}
//���~
if (GetKeyState('K') & 0x8000){
//mainrotor.mRotation.y += 80;
//tellrotor.mRotation.x += 40;
mPosition.mY -= 5;
}
//�����
if (GetKeyState('A') & 0x8000){
mRotation.mY++;
}
//�E���
if (GetKeyState('D') & 0x8000){
mRotation.mY--;
}
//�����ɖ߂�
if (GetKeyState('Y') & 0x8000){
mRotation.mX = 0;
}
//�O�i
if (GetKeyState('W') & 0x8000){
//mainrotor.mRotation.y += 40;
//mPosition.mX++;
mPosition = mPosition + CVector(0.0f, 0.0f, 0.4f) * mMatrixRotation;
//mBox.Forward();
//mBox.Forward();
//mBox.Forward();
}
//�O���
if (GetKeyState('W') & 0x8000){
mRotation.mX += 1;
if (mRotation.mX > 30){
mRotation.mX = 30;
}
}
//��i
if (GetKeyState('S') & 0x8000){
mPosition = mPosition - CVector(0.0f, 0.0f, 0.2f) * mMatrixRotation;
//mPosition.mX--;
//mainrotor.mRotation.y += 40;
//mBox.Reverse();
//mBox.Reverse();
}
//�����
if (GetKeyState('S') & 0x8000){
mRotation.mX -= 1;
if (mRotation.mX < -30){
mRotation.mX = -30;
}
}
//�X�������X���������֑O�i
if (mRotation.mX >= 1){
mPosition = mPosition + CVector(0.0f, 0.0f, 0.4f) * mMatrixRotation;
if (mRotation.mX >= 10){
mPosition = mPosition + CVector(0.0f, 0.0f, 0.5f) * mMatrixRotation;
if (mRotation.mX >= 20){
mPosition = mPosition + CVector(0.0f, 0.0f, 0.6f) * mMatrixRotation;
if (mRotation.mX >= 30){
mPosition = mPosition + CVector(0.0f, 0.0f, 0.7f) * mMatrixRotation;
}
}
}
}
//�X�������X���������֌�i
if (mRotation.mX <= -1){
mPosition = mPosition - CVector(0.0f, 0.0f, 0.2f) * mMatrixRotation;
if (mRotation.mX <= -10){
mPosition = mPosition - CVector(0.0f, 0.0f, 0.3f) * mMatrixRotation;
if (mRotation.mX <= -20){
mPosition = mPosition - CVector(0.0f, 0.0f, 0.4f) * mMatrixRotation;
if (mRotation.mX <= -30){
mPosition = mPosition - CVector(0.0f, 0.0f, 0.5f) * mMatrixRotation;
}
}
}
}
else{
if (mRotation.mX <= 0){
mPosition = mPosition + CVector(0.0f, 0.0f, 0.2f) * mMatrixRotation;
mPosition = mPosition - CVector(0.0f, 0.0f, 0.2f) * mMatrixRotation;
}
if (mRotation.mX >= 0){
mPosition = mPosition + CVector(0.0f, 0.0f, 0.2f) * mMatrixRotation;
mPosition = mPosition - CVector(0.0f, 0.0f, 0.2f) * mMatrixRotation;
}
}*/
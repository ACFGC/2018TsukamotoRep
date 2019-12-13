#include"CPlayerAH.h"
#include"CKey.h"
#include"CBullet.h"
#include"CSceneGameAH.h"
#include"CMissileAH.h"
#include"CFlare.h"
#include"CFire.h"
//�~�T�C���N�[���^�C��(����)
#define FIREINTERVAL_E 100
//�t���A�N�[���^�C��(����)
#define FLAREINTERVAL_E 60

//�~�T�C��AH�̊O���ϐ������
CMissileAH *m;
//�~�T�C��(���f��)�̊O���ϐ����Ă�
extern CModel mAAM;
//�t�@�C�A�̊O���ϐ����Ă�
extern CFire *f;
//�t���A�̊O���ϐ����Ă�
extern CFlare*Flare;

CPlayerAH *CPlayerAH::mpPlayerAH = 0;

CPlayerAH::CPlayerAH() {
	mpPlayerAH = this;
	mPCollider.mpParent = this;
	mPCollider.mRadius = 1.0f;
	//�^�O�����߂�
	mTaskTag = EPLAYER;
	//�~�T�C���̃��f����ǂݍ���
	mAAM.Load("AAM.obj", "AAM.mtl");
}

CPlayerAH::~CPlayerAH() {
	mpPlayerAH = 0;
}

void CPlayerAH::Update() {
	//�w�����쏈��
	//��ɌX������������֑O�i
	if (mRotation.mX <= 50){
		mPosition = mPosition + CVector(0.0f, 0.0f, 0.4f) * mMatrixRotation;
	}
	//���ɌX�������������֑O�i
	if (mRotation.mX >= 50){
		mPosition = mPosition + CVector(0.0f, 0.0f, 0.2f) * mMatrixRotation;
	}
		//�㏸
		if (GetKeyState('I') & 0x8000){
			mPosition.mY += 0.5;
		    //mainrotor.mRotation.y += 40;
		    //tellrotor.mRotation.x += 20;
		}
		//���~
		if (GetKeyState('K') & 0x8000){
			//mainrotor.mRotation.y += 80;
			//tellrotor.mRotation.x += 40;
			mPosition.mY -= 0.5;
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
		}
	//���s�ɖ߂�
	if (CKey::Push('Y')) {
		mRotation.mX = 0;
		mRotation.mY = 0;
		mRotation.mZ = 0;
	}

	/*if (mRotation.mX > -90){
	mRotation = mRotation + CVector(0.1f, 0.0f, 0.0f) * mMatrixRotation;
	if (mRotation.mX > 90){
	mRotation.mX = 90;
	}
	}*/
	/*if (mRotation.mX < -90){
	mRotation = mRotation - CVector(0.5f, 0.0f, 0.0f) * mMatrixRotation;
	}*/


	//�U�� (�@�֖C����)
	if (CKey::Push(VK_SPACE)) {
		CBullet *b = new CBullet();
		b->mTaskTag = EPLAYERBULLET;
		b->Set(0.0f, 0.0f, 0.0f, 0.03f, 0.03f, 0.3f);
		b->SetDiffuse(1.0f, 1.0f, 0.0f, 1.0f);
		b->mPosition = mPosition;
		b->mRotation = mRotation;
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
			m = new CMissileAH(&mAAM, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f);
			m->mTaskTag = EPLAYERBULLET;
			m->mPosition = mPosition;
			m->mRotation = mRotation;
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
			Flare = new CFlare();
			Flare->Set(0.0f, 0.0f, -1.4f, 0.1f, 0.1f, 0.1f);
			//�^�O�ݒ�
			Flare->mTaskTag = EFLARE;
			Flare->SetDiffuse(1.0f, 1.0f, 0.0f, 1.0f);
			Flare->mPosition = mPosition;
			Flare->mRotation = mRotation;
			TaskManager.Add(Flare);

			//�t���A2
			Flare = new CFlare();
			Flare->Set(1.0f, 0.0f, -1.4f, 0.1f, 0.1f, 0.1f);
			//�^�O�ݒ�
			Flare->mTaskTag = EFLARE;
			Flare->SetDiffuse(1.0f, 1.0f, 0.0f, 1.0f);
			Flare->mPosition = mPosition;
			Flare->mRotation = mRotation;
			TaskManager.Add(Flare);

			//�t���A3
			Flare = new CFlare();
			Flare->Set(-1.0f, 0.0f, -1.4f, 0.1f, 0.1f, 0.1f);
			//�^�O�ݒ�
			Flare->mTaskTag = EFLARE;
			Flare->SetDiffuse(1.0f, 1.0f, 0.0f, 1.0f);
			Flare->mPosition = mPosition;
			Flare->mRotation = mRotation;
			TaskManager.Add(Flare);
		}
	}
	CCharacter::Update();
}

void CPlayerAH::Collision(CCollider *m, CCollider *y) {
	if (CCollider::Collision(m, y)) {
		switch (y->mpParent->mTaskTag)
		{
		case EENEMYBULLET:
			f = new CFire();
			f->mPosition = y->mpParent->mPosition;
			f->SetTexture("fire.tga");
			TaskManager.Add(f);
			break;
		}
	}
}
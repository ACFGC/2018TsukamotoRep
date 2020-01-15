#include"CEnemyAH.h"
#include"CEMissileAH.h"
#include"CFire.h"
#include"CFlare.h"
#include"CPlayerAH.h"
#include"CSceneGameAH.h"

#define VELOCITY_ENEMY 0.3f
//�~�T�C���N�[���^�C��
#define MISSILEINTERVAL_E 100
//�t���A�N�[���^�C��
#define EFLAREINTERVAL_E 60
//�G�~�T�C��AH�̊O���ϐ������
CEMissileAH*em;
//�G�~�T�C��(���f��)�̊O���ϐ����Ă�
extern CModel mAAM;
//�t���A�̊O���ϐ����Ă�
extern CFlare*EFlare;
//�t�@�C�A�̊O���ϐ����Ă�
extern CFire *f;
CEnemyAH::CEnemyAH(CModel *model, float px, float py, float pz, float rx, float ry, float rz, float sx, float sy, float sz) {
	Init(model, px, py, pz, rx, ry, rz, sx, sy, sz);
	TaskManager.Add(this);
	mCollider.mpParent = this;
	mCollider.mRadius = 1.0f;
	mEFlareInterval = EFLAREINTERVAL_E;
	//�^�O��ݒ�
	mTaskTag = EENEMY;
	//�~�T�C���̃��f����ǂݍ���
	mAAM.Load("AAM.obj", "AAM.mtl");
}

void CEnemyAH::Update() {
	mPosition = mPosition + CVector(0.0f, 0.0f, VELOCITY_ENEMY) * mMatrixRotation;
	//�G���W
	CVector vPos = CVector(1.0f, 0.0f, 0.0f) * mMatrix - CVector(0.0f, 0.0f, 0.0f) * mMatrix;
	//�����x�N�g��
	CVector vDir(10, 10, 10);
	//vPos = vPos.getRotationTowards(vDir);//�~�T�C�����W�X�V

	//�v���C���[���W
	CVector vTargetHPos = CPlayerAH::mpPlayerAH->mPosition - mPosition;
	//�v���C���[�����ɒǔ�
	float HE = vPos.dot(vTargetHPos);
	//mRotation.mY += 0.5f;
	//�ǔ���������
	if (EATime > 0){
		EATime--;
	}
	if (EATime <= 80){
		//�ǔ�����
		if (HE > 0.0f){
			mRotation.mY += 1;
		}
		else if (HE < 0.0f){
			mRotation.mY -= 1;
		}
		//X�����֒ǔ�
		if (CPlayerAH::mpPlayerAH->mPosition.mX > CEnemyAH::mPosition.mX){
			mPosition.mX += 0.1;
		}
		if (CPlayerAH::mpPlayerAH->mPosition.mX < CEnemyAH::mPosition.mX){
			mPosition.mX -= 0.1;
		}
		//Y�����֒ǔ�
		if (CPlayerAH::mpPlayerAH->mPosition.mY > CEnemyAH::mPosition.mY){
			mPosition.mY += 0.1;
		}
		if (CPlayerAH::mpPlayerAH->mPosition.mY < CEnemyAH::mPosition.mY){
			mPosition.mY -= 0.1;
		}
		//Z�����֒ǔ�
		if (CPlayerAH::mpPlayerAH->mPosition.mZ > CEnemyAH::mPosition.mZ){
			mPosition.mZ += 0.1;
		}
		if (CPlayerAH::mpPlayerAH->mPosition.mZ < CEnemyAH::mPosition.mZ){
			mPosition.mZ -= 0.1;
		}
		if (CPlayerAH::mpPlayerAH->mRotation.mX > CEnemyAH::mRotation.mX){
			mRotation.mX += 0.1;
		}
		if (CPlayerAH::mpPlayerAH->mRotation.mX < CEnemyAH::mRotation.mX){
			mRotation.mX -= 0.1;
		}
	}
	if (EATime == 0){
		EATime = 100;
	}
	//�~�T�C���N�[���^�C��
	if (mEMissileInterval>0){
		mEMissileInterval--;
	}
	if (mEMissileInterval <= 0){
		mEMissileInterval = MISSILEINTERVAL_E;
		em = new CEMissileAH(&mAAM, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f);
		em->mTaskTag = EENEMYBULLET;
		em->mPosition = mPosition;
		em->mRotation = mRotation;
		TaskManager.Add(em);
	}
	CCharacter::Update();
}

void CEnemyAH::Collision(CCollider *m, CCollider *y) {
	//��������������
	if (CCollider::Collision(m, y)){
		switch (y->mpParent->mTaskTag){
			//������������̃^�O��EPLAYERBULLET�Ȃ�
		case EPLAYERBULLET:
			f = new CFire();
			f->mPosition = y->mpParent->mPosition;
			f->SetTexture("fire.tga");
			TaskManager.Add(f);
			//����������
			m->mpParent->mEnabled = false;
			//�����������������
			y->mpParent->mEnabled = false;
			break;
		}
	}
}


//�G�t���A�N�[���^�C��
/*if (mEFlareInterval>0){
mEFlareInterval--;
}
if (mEFlareInterval <= 0){
mEFlareInterval = EFLAREINTERVAL_E;
EFlare = new CFlare();
EFlare->Set(0.0f, 0.0f, -1.4f, 0.1f, 0.1f, 0.1f);
EFlare->SetDiffuse(1.0f, 1.0f, 0.0f, 1.0f);
EFlare->mPosition = mPosition;
EFlare->mRotation = mRotation;
TaskManager.Add(EFlare);
EFlare = new CFlare();
EFlare->Set(1.0f, 0.0f, -1.4f, 0.1f, 0.1f, 0.1f);
EFlare->SetDiffuse(1.0f, 1.0f, 0.0f, 1.0f);
EFlare->mPosition = mPosition;
EFlare->mRotation = mRotation;
TaskManager.Add(EFlare);
EFlare = new CFlare();
EFlare->Set(-1.0f, 0.0f, -1.4f, 0.1f, 0.1f, 0.1f);
EFlare->SetDiffuse(1.0f, 1.0f, 0.0f, 1.0f);
EFlare->mPosition = mPosition;
EFlare->mRotation = mRotation;
TaskManager.Add(EFlare);
}*/
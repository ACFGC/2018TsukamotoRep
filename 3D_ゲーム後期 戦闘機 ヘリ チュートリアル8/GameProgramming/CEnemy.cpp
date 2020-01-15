#include"CEnemy.h"
#include"CEMissile.h"
#include"CSceneGameF22.h"
#include"CFire.h"
#include"CFlare.h"
#include"CHpBar.h"
#define VELOCITY_ENEMY 0.3f
//�~�T�C���N�[���^�C��
#define mEMissileINTERVAL_E 100
//�t���A�N�[���^�C��
#define EFLAREINTERVAL_E 60
//�t���A�̊O���ϐ������
CFlare*EFlare;
//�G�~�T�C���̊O���ϐ������
CEMissile*em;
//�G�~�T�C��(���f��)�̊O���ϐ������
CModel mAAM;
//�t�@�C�A�̊O���ϐ����Ă�
extern CFire *f;
//����
int EATime = 100 * 60;
//HP�o�[�̊O���ϐ������
CHpBar HP;
CEnemy::CEnemy(CModel *model, float px, float py, float pz, float rx, float ry, float rz, float sx, float sy, float sz) {
	Init(model, px, py, pz, rx, ry, rz, sx, sy, sz);
	TaskManager.Add(this);
	mCollider.mpParent = this;
	mCollider.mRadius = 5.0f;
	//�t���A�C���^�[�o���ݒ�
	mEFlareInterval = EFLAREINTERVAL_E;
	//�^�O��ݒ�
	mTaskTag = EENEMY;
	//�̗͂�100�ɐݒ�
	//HP = 100.0f;
	//HP�o�[�̐ݒ���Ă�
	HP.Init();
	//�~�T�C���̃��f����ǂݍ���
	mAAM.Load("AAM.obj", "AAM.mtl");
}

void CEnemy::Update() {
	mPosition = mPosition + CVector(0.0f, 0.0f, VELOCITY_ENEMY) * mMatrixRotation;
	//�G���W
	CVector vPos = CVector(1.0f, 0.0f, 0.0f) * mMatrix - CVector(0.0f, 0.0f, 0.0f) * mMatrix;
	//�����x�N�g��
	CVector vDir(10, 10, 10);
	//vPos = vPos.getRotationTowards(vDir);//�~�T�C�����W�X�V

	//�v���C���[���W
	CVector vTargetHPos = CPlayer::mpPlayer->mPosition - mPosition;
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
		if (CPlayer::mpPlayer->mPosition.mX > CEnemy::mPosition.mX){
			mPosition.mX += 0.1;
		}
		if (CPlayer::mpPlayer->mPosition.mX < CEnemy::mPosition.mX){
			mPosition.mX -= 0.1;
		}
		//Y�����֒ǔ�
		if (CPlayer::mpPlayer->mPosition.mY > CEnemy::mPosition.mY){
			mPosition.mY += 0.1;
		}
		if (CPlayer::mpPlayer->mPosition.mY < CEnemy::mPosition.mY){
			mPosition.mY -= 0.1;
		}
		//Z�����֒ǔ�
		if (CPlayer::mpPlayer->mPosition.mZ > CEnemy::mPosition.mZ){
			mPosition.mZ += 0.1;
		}
		if (CPlayer::mpPlayer->mPosition.mZ < CEnemy::mPosition.mZ){
			mPosition.mZ -= 0.1;
		}
		if (CPlayer::mpPlayer->mRotation.mX > CEnemy::mRotation.mX){
			mRotation.mX += 0.1;
		}
		if (CPlayer::mpPlayer->mRotation.mX < CEnemy::mRotation.mX){
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
		mEMissileInterval = mEMissileINTERVAL_E;
		em = new CEMissile(&mAAM, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f);
		//�^�O��ݒ�
		em->mTaskTag = EENEMYBULLET;
		em->mPosition = mPosition;
		em->mRotation = mRotation;
		TaskManager.Add(em);
	}
	CCharacter::Update();
}

void CEnemy::Collision(CCollider *m, CCollider *y) {
	//��������������
	if (CCollider::Collision(m, y)){
		switch (y->mpParent->mTaskTag){
		//������������̃^�O��EPLAYERBULLET�Ȃ�
		case EPLAYERBULLET:
			HP.HP -= 40.0f;
			if (HP.HP <= 0.0f){
				f = new CFire();
				f->mPosition = y->mpParent->mPosition;
				f->SetTexture("fire.tga");
				TaskManager.Add(f);
				//����������
				m->mpParent->mEnabled = false;
				//�����������������
				//y->mpParent->mEnabled = false;
			}
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
#include"CEMissileStandard.h"
#include"CEnemyStandard.h"
#include"CPlayerStandard.h"
#include"CFlare.h"
#include"CFire.h"
#include"CSceneGameF22.h"
//�t���A�̊O���ϐ����Ă�
extern CFlare*Flare;
//�t�@�C�A�̊O���ϐ����Ă�
extern CFire *f;

#define LIFE 600

CEMissileStandard::CEMissileStandard(CModel *model, float px, float py, float pz, float rx, float ry, float rz, float sx, float sy, float sz)
: mELife(LIFE)
{
	Init(model, px, py, pz, rx, ry, rz, sx, sy, sz);
	mCollider.mpParent = this;
	mCollider.mRadius = 1.0f;
}

void CEMissileStandard::Update() {
	//�G�~�T�C�����W
	CVector vPos = CVector(1.0f, 0.0f, 0.0f) * mMatrix - CVector(0.0f, 0.0f, 0.0f) * mMatrix;
	//�G�~�T�C�������x�N�g��
	CVector vDir(10, 10, 10);
	//vPos = vPos.getRotationTowards(vDir);//�~�T�C�����W�X�V

	//�^�[�Q�b�g���W
	CVector vTargetpPos = CPlayerStandard::mPlayerStandard->mPosition - mPosition;
	//�G�~�T�C��
	float Emissile = vPos.dot(vTargetpPos);
	//�G�~�T�C���ǔ�����
	if (Emissile > 0.0f){
		mRotation.mY += 1;
	}
	else if (Emissile < 0.0f){
		mRotation.mY -= 1;
	}

	//X�����֒ǔ�
	if (CPlayerStandard::mPlayerStandard->mPosition.mX > CEMissileStandard::mPosition.mX){
		mPosition.mX += 0.1;
	}
	if (CPlayerStandard::mPlayerStandard->mPosition.mX < CEMissileStandard::mPosition.mX){
		mPosition.mX -= 0.1;
	}
	//Y�����֒ǔ�
	if (CPlayerStandard::mPlayerStandard->mPosition.mY > CEMissileStandard::mPosition.mY){
		mPosition.mY += 0.1;
	}
	if (CPlayerStandard::mPlayerStandard->mPosition.mY < CEMissileStandard::mPosition.mY){
		mPosition.mY -= 0.1;
	}
	//Z�����֒ǔ�
	if (CPlayerStandard::mPlayerStandard->mPosition.mZ > CEMissileStandard::mPosition.mZ){
		mPosition.mZ += 0.1;
	}
	if (CPlayerStandard::mPlayerStandard->mPosition.mZ < CEMissileStandard::mPosition.mZ){
		mPosition.mZ -= 0.1;
	}
	if (CPlayerStandard::mPlayerStandard->mRotation.mX > CEMissileStandard::mRotation.mX){
		mRotation.mX += 0.1;
	}
	if (CPlayerStandard::mPlayerStandard->mRotation.mX < CEMissileStandard::mRotation.mX){
		mRotation.mX -= 0.1;
	}

	//�G�~�T�C���ǔ���������
	if (ETime > 0){
		ETime--;
	}
	//���Ԃ���������Čv�Z
	if (ETime == 0){
		//�G�~�T�C���ǔ�����
		if (Emissile > 0.0f){
			mRotation.mY += 1;
		}
		else if (Emissile < 0.0f){
			mRotation.mY -= 1;
		}
		//Y�����֒ǔ�
		if (CPlayerStandard::mPlayerStandard->mPosition.mY > CEMissileStandard::mPosition.mY){
			mPosition.mY += 0.1;
		}
		if (CPlayerStandard::mPlayerStandard->mPosition.mY < CEMissileStandard::mPosition.mY){
			mPosition.mY -= 0.1;
		}
		//X�����֒ǔ�
		if (CPlayerStandard::mPlayerStandard->mPosition.mX > CEMissileStandard::mPosition.mX){
			mPosition.mX += 0.1;
		}
		if (CPlayerStandard::mPlayerStandard->mPosition.mX < CEMissileStandard::mPosition.mX){
			mPosition.mX -= 0.1;
		}
		//Z�����֒ǔ�
		if (CPlayerStandard::mPlayerStandard->mPosition.mZ > CEMissileStandard::mPosition.mZ){
			mPosition.mZ += 0.1;
		}
		if (CPlayerStandard::mPlayerStandard->mPosition.mZ < CEMissileStandard::mPosition.mZ){
			mPosition.mZ -= 0.1;
		}
		if (CPlayerStandard::mPlayerStandard->mRotation.mX > CEMissileStandard::mRotation.mX){
			mRotation.mX += 0.1;
		}
		if (CPlayerStandard::mPlayerStandard->mRotation.mX < CEMissileStandard::mRotation.mX){
			mRotation.mX -= 0.1;
		}
	}
	if (mELife > 0) {
		mELife--;
		CCharacter::Update();
		mPosition = mPosition + CVector(0.0f, 0.0f, 1.0f) * mMatrixRotation;
	}
	else {
		mEnabled = false;
	}
}

void CEMissileStandard::Collision(CCollider *m, CCollider *y) {
	//��������������
	if (CCollider::Collision(m, y)){
		switch (y->mpParent->mTaskTag){
			//������������̃^�O��EPLAYER�Ȃ�
		case EPLAYER:
			f = new CFire();
			f->mPosition = y->mpParent->mPosition;
			f->SetTexture("fire.tga");
			TaskManager.Add(f);
			//����������
			m->mpParent->mEnabled = false;
			//�����������������
			//y->mpParent->mEnabled = false;
			break;

			//������������̃^�O��EFLARE�Ȃ�
		case EFLARE:
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
#include"CEMissileAH.h"
#include"CEnemyAH.h"
#include"CPlayerAH.h"
#include"CFlare.h"
#include"CFire.h"
#include"CSceneGameAH.h"
//�t���A�̊O���ϐ����Ă�
extern CFlare*Flare;
//�t�@�C�A�̊O���ϐ����Ă�
extern CFire *f;

#define LIFE 600

CEMissileAH::CEMissileAH(CModel *model, float px, float py, float pz, float rx, float ry, float rz, float sx, float sy, float sz)
: mELife(LIFE)
{
	Init(model, px, py, pz, rx, ry, rz, sx, sy, sz);
	mCollider.mpParent = this;
	mCollider.mRadius = 1.0f;
}

void CEMissileAH::Update() {
	//�G�~�T�C�����W
	CVector vPos = CVector(1.0f, 0.0f, 0.0f) * mMatrix - CVector(0.0f, 0.0f, 0.0f) * mMatrix;
	//�G�~�T�C�������x�N�g��
	CVector vDir(10, 10, 10);
	//vPos = vPos.getRotationTowards(vDir);//�~�T�C�����W�X�V

	//�^�[�Q�b�g���W
	CVector vTargetpPos = CPlayerAH::mpPlayerAH->mPosition - mPosition;
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
	if (CPlayerAH::mpPlayerAH->mPosition.mX > CEMissileAH::mPosition.mX){
		mPosition.mX += 0.1;
	}
	if (CPlayerAH::mpPlayerAH->mPosition.mX < CEMissileAH::mPosition.mX){
		mPosition.mX -= 0.1;
	}
	//Y�����֒ǔ�
	if (CPlayerAH::mpPlayerAH->mPosition.mY > CEMissileAH::mPosition.mY){
		mPosition.mY += 0.1;
	}
	if (CPlayerAH::mpPlayerAH->mPosition.mY < CEMissileAH::mPosition.mY){
		mPosition.mY -= 0.1;
	}
	//Z�����֒ǔ�
	if (CPlayerAH::mpPlayerAH->mPosition.mZ > CEMissileAH::mPosition.mZ){
		mPosition.mZ += 0.1;
	}
	if (CPlayerAH::mpPlayerAH->mPosition.mZ < CEMissileAH::mPosition.mZ){
		mPosition.mZ -= 0.1;
	}
	if (CPlayerAH::mpPlayerAH->mRotation.mX > CEMissileAH::mRotation.mX){
		mRotation.mX += 0.1;
	}
	if (CPlayerAH::mpPlayerAH->mRotation.mX < CEMissileAH::mRotation.mX){
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
		if (CPlayerAH::mpPlayerAH->mPosition.mY > CEMissileAH::mPosition.mY){
			mPosition.mY += 0.1;
		}
		if (CPlayerAH::mpPlayerAH->mPosition.mY < CEMissileAH::mPosition.mY){
			mPosition.mY -= 0.1;
		}
		//X�����֒ǔ�
		if (CPlayerAH::mpPlayerAH->mPosition.mX > CEMissileAH::mPosition.mX){
			mPosition.mX += 0.1;
		}
		if (CPlayerAH::mpPlayerAH->mPosition.mX < CEMissileAH::mPosition.mX){
			mPosition.mX -= 0.1;
		}
		//Z�����֒ǔ�
		if (CPlayerAH::mpPlayerAH->mPosition.mZ > CEMissileAH::mPosition.mZ){
			mPosition.mZ += 0.1;
		}
		if (CPlayerAH::mpPlayerAH->mPosition.mZ < CEMissileAH::mPosition.mZ){
			mPosition.mZ -= 0.1;
		}
		if (CPlayerAH::mpPlayerAH->mRotation.mX > CEMissileAH::mRotation.mX){
			mRotation.mX += 0.1;
		}
		if (CPlayerAH::mpPlayerAH->mRotation.mX < CEMissileAH::mRotation.mX){
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

void CEMissileAH::Collision(CCollider *m, CCollider *y) {
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
/*//�~�T�C�����W
CVector vPos = CVector(1.0f, 0.0f, 0.0f) * mMatrix - CVector(0.0f, 0.0f, 0.0f) * mMatrix;

//�~�T�C�������x�N�g��
CVector vDir(10, 10, 10);
//vPos = vPos.getRotationTowards(vDir);//�~�T�C�����W�X�V

//�t���A���W
CVector vTargetFPos = Flare->mPosition - mPosition;

//�~�T�C��
float EFmissile = vPos.dot(vTargetFPos);

//�~�T�C���ǔ�����
if (EFmissile > 0.0f){
mRotation.mY += 1;
}
else if (EFmissile < 0.0f){
mRotation.mY -= 1;
}

//Y�����֒ǔ�
if (Flare->mPosition.mY > CEMissile::mPosition.mY){
mPosition.mY += 0.1;
}
if (Flare->mPosition.mY < CEMissile::mPosition.mY){
mPosition.mY -= 0.1;
}

//X�����֒ǔ�
if (Flare->mPosition.mX > CEMissile::mPosition.mX){
mPosition.mX += 0.1;
}
if (Flare->mPosition.mX < CEMissile::mPosition.mX){
mPosition.mX -= 0.1;
}

//Z�����֒ǔ�
if (Flare->mPosition.mZ > CEMissile::mPosition.mZ){
mPosition.mZ += 0.1;
}
if (Flare->mPosition.mZ < CEMissile::mPosition.mZ){
mPosition.mZ -= 0.1;
}
if (Flare->mRotation.mX > CEMissile::mRotation.mX){
mRotation.mX += 0.1;
}
if (Flare->mRotation.mX < CEMissile::mRotation.mX){
mRotation.mX -= 0.1;
}
if (ETime <= 100){
if (Flare->mEnabled = true){
//�t���A���W
CVector vTargetFPos = Flare->mPosition - mPosition;
//�t���A�ǔ�
float EFmissile = vPos.dot(vTargetFPos);
if (EFmissile > 0.0f){
mRotation.mY += 1;
}
else if (EFmissile < 0.0f){
mRotation.mY -= 1;
}

//�t���A�ǔ�����
//X�����֒ǔ�
if (Flare->mPosition.mX > CEMissile::mPosition.mX){
mPosition.mX += 0.1;
}
if (Flare->mPosition.mX < CEMissile::mPosition.mX){
mPosition.mX -= 0.1;
}

//Y�����֒ǔ�
if (Flare->mPosition.mY > CEMissile::mPosition.mY){
mPosition.mY += 0.1;
}
if (Flare->mPosition.mY < CEMissile::mPosition.mY){
mPosition.mY -= 0.1;
}

//Z�����֒ǔ�
if (Flare->mPosition.mZ > CEMissile::mPosition.mZ){
mPosition.mZ += 0.1;
}
if (Flare->mPosition.mZ < CEMissile::mPosition.mZ){
mPosition.mZ -= 0.1;
}
if (Flare->mRotation.mX > CEMissile::mRotation.mX){
mRotation.mX += 0.1;
}
if (Flare->mRotation.mX < CEMissile::mRotation.mX){
mRotation.mX -= 0.1;
}
}
}
else{
//�~�T�C���ǔ�����
if (Emissile > 0.0f){
mRotation.mY += 1;
}
else if (Emissile < 0.0f){
mRotation.mY -= 1;
}
//Y�����֒ǔ�
if (CPlayer::mpPlayer->mPosition.mY > CEMissile::mPosition.mY){
mPosition.mY += 0.1;
}
if (CPlayer::mpPlayer->mPosition.mY < CEMissile::mPosition.mY){
mPosition.mY -= 0.1;
}
//X�����֒ǔ�
if (CPlayer::mpPlayer->mPosition.mX > CEMissile::mPosition.mX){
mPosition.mX += 0.1;
}
if (CPlayer::mpPlayer->mPosition.mX < CEMissile::mPosition.mX){
mPosition.mX -= 0.1;
}
//Z�����֒ǔ�
if (CPlayer::mpPlayer->mPosition.mZ > CEMissile::mPosition.mZ){
mPosition.mZ += 0.1;
}
if (CPlayer::mpPlayer->mPosition.mZ < CEMissile::mPosition.mZ){
mPosition.mZ -= 0.1;
}
if (CPlayer::mpPlayer->mRotation.mX > CEMissile::mRotation.mX){
mRotation.mX += 0.1;
}
if (CPlayer::mpPlayer->mRotation.mX < CEMissile::mRotation.mX){
mRotation.mX -= 0.1;
}
}
*/
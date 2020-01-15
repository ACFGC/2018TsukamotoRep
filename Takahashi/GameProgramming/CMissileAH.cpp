#include"CMissileAH.h"
#include"CEnemyAH.h"
#include"CPlayerAH.h"
//�G�̊O���ϐ����Ă�
extern CEnemyAH*Enemy;

#define LIFE 600

CMissileAH::CMissileAH(CModel *model, float px, float py, float pz, float rx, float ry, float rz, float sx, float sy, float sz)
: mLife(LIFE)
{
	Init(model, px, py, pz, rx, ry, rz, sx, sy, sz);
	mCollider.mpParent = this;
	mCollider.mRadius = 1.0f;
}

void CMissileAH::Update() {
	CVector vPos = CVector(1.0f, 0.0f, 0.0f) * mMatrix - CVector(0.0f, 0.0f, 0.0f) * mMatrix;//�~�T�C�����W
	CVector vDir(0, 10, 0); //�~�T�C�������x�N�g��
	//vPos = vPos.getRotationTowards(vDir);//�~�T�C�����W�X�V

	CEnemyAH*tenemy = Enemy;//�G�̍��W����������
	CVector vTargetPos = tenemy->mPosition - mPosition;//�^�[�Q�b�g���W
	//CVector vtargetppos = CPlayer::mpPlayer->mPosition - mPosition;
	float missile = vPos.dot(vTargetPos);//�~�T�C��
	//�~�T�C���ǔ�����
	if (missile > 0.0f){
		mRotation.mY += 1;
	}
	else if (missile < 0.0f){
		mRotation.mY -= 1;
	}
	//Y�����֒ǔ�
	if (tenemy->mPosition.mY > CMissileAH::mPosition.mY){
		mPosition.mY += 0.1;
	}
	if (tenemy->mPosition.mY < CMissileAH::mPosition.mY){
		mPosition.mY -= 0.1;
	}
	//X�����֒ǔ�
	if (tenemy->mPosition.mX > CMissileAH::mPosition.mX){
		mPosition.mX += 0.1;
	}
	if (tenemy->mPosition.mX < CMissileAH::mPosition.mX){
		mPosition.mX -= 0.1;
	}
	//Z�����֒ǔ�
	if (tenemy->mPosition.mZ > CMissileAH::mPosition.mZ){
		mPosition.mZ += 0.1;
	}
	if (tenemy->mPosition.mZ < CMissileAH::mPosition.mZ){
		mPosition.mZ -= 0.1;
	}
	if (tenemy->mRotation.mX > CMissileAH::mRotation.mX){
		mRotation.mX += 0.1;
	}
	if (tenemy->mRotation.mX < CMissileAH::mRotation.mX){
		mRotation.mX -= 0.1;
	}
	//�~�T�C���ǔ���������
	if (Time > 0){
		Time--;
	}
	//���Ԃ���������Čv�Z
	if (Time == 0){
		if (missile < 0.0f){
			mRotation.mY += 1;
		}
		else if (missile > 0.0f){
			mRotation.mY -= 1;
		}
		if (tenemy->mPosition.mY > CMissileAH::mPosition.mY){
			mPosition.mY += 0.1;
		}
		if (tenemy->mPosition.mY < CMissileAH::mPosition.mY){
			mPosition.mY -= 0.1;
		}
		if (tenemy->mPosition.mX > CMissileAH::mPosition.mX){
			mPosition.mX += 0.1;
		}
		if (tenemy->mPosition.mX < CMissileAH::mPosition.mX){
			mPosition.mX -= 0.1;
		}
		if (tenemy->mRotation.mX > CMissileAH::mRotation.mX){
			mRotation.mX += 0.1;
		}
		if (tenemy->mRotation.mX < CMissileAH::mRotation.mX){
			mRotation.mX -= 0.1;
		}
	}
	if (mLife > 0) {
		mLife--;
		//�s��X�V
		mMatrix = mMatrix.Scale(mScale.mX, mScale.mY, mScale.mZ) * mMatrixRotation * 
			mMatrix.Translate(mPosition.mX, mPosition.mY, mPosition.mZ);
		mPosition = mPosition + CVector(0.0f, 0.0f, 1.0f) * mMatrixRotation;
	}
	else {
		mEnabled = false;
	}
}
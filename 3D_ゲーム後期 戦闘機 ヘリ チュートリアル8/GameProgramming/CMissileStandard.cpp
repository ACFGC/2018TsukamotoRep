#include"CMissileStandard.h"
#include"CEnemyStandard.h"
#include"CPlayerStandard.h"
#include"CFire.h"
#include"CSceneGameF22.h"
//�G�̊O���ϐ����Ă�
extern CEnemyStandard*EnemySD;
//�t�@�C�A�̊O���ϐ����Ă�
extern CFire *f;
#define LIFE 600

CMissileStandard::CMissileStandard(CModel *model, float px, float py, float pz, float rx, float ry, float rz, float sx, float sy, float sz)
: mLife(LIFE)
{
	Init(model, px, py, pz, rx, ry, rz, sx, sy, sz);
	mCollider.mpParent = this;
	mCollider.mRadius = 1.0f;
}

void CMissileStandard::Update() {
	CVector vPos = CVector(1.0f, 0.0f, 0.0f) * mMatrix - CVector(0.0f, 0.0f, 0.0f) * mMatrix;//�~�T�C�����W
	CVector vPosX = CVector(0.0f, 1.0f, 0.0f) * mMatrix - CVector(0.0f, 0.0f, 0.0f) * mMatrix;//�~�T�C��X���W
	CVector vDir(mPosition.mX, 10, mPosition.mZ); //�~�T�C�������x�N�g��
	//vPos = vPos.getRotationTowards(vDir);//�~�T�C�����W�X�V

	CEnemyStandard*tenemy = EnemySD;//�G�̍��W����������
	CVector vTargetPos = tenemy->mPosition - mPosition;//�^�[�Q�b�g���W
	//CVector vtargetppos = CPlayer::mpPlayer->mPosition - mPosition;
	float missile = vPos.dot(vTargetPos);//�~�T�C��
	//�~�T�C���ǔ�����
	if (missile > tenemy->mPosition.mX){
		//mRotation.mY += 1;
		mMatrixRotation = mMatrixRotation*CMatrix().RotateY(1);
	}
	else if (missile < tenemy->mPosition.mX){
		//mRotation.mY -= 1;
		mMatrixRotation = mMatrixRotation*CMatrix().RotateY(-1);
	}
	float missileX = vPosX.dot(vTargetPos);
	//�~�T�C���ǔ�����
	if (missileX > tenemy->mPosition.mY){
		//mRotation.mY += 1;
		mMatrixRotation = mMatrixRotation*CMatrix().RotateX(-1);
	}
	else if (missileX < tenemy->mPosition.mY){
		//mRotation.mY -= 1;
		mMatrixRotation = mMatrixRotation*CMatrix().RotateX(1);
	}
	//�~�T�C���ǔ���������
	if (Time > 0){
		Time--;
	}
	//���Ԃ���������Čv�Z
	/*if (Time == 0){
	if (missile < 0.0f){
	mRotation.mY += 1;
	}
	else if (missile > 0.0f){
	mRotation.mY -= 1;
	}
	if (tenemy->mPosition.mY > CMissile::mPosition.mY){
	mPosition.mY += 0.1;
	}
	if (tenemy->mPosition.mY < CMissile::mPosition.mY){
	mPosition.mY -= 0.1;
	}
	if (tenemy->mPosition.mX > CMissile::mPosition.mX){
	mPosition.mX += 0.1;
	}
	if (tenemy->mPosition.mX < CMissile::mPosition.mX){
	mPosition.mX -= 0.1;
	}
	if (tenemy->mRotation.mX > CMissile::mRotation.mX){
	mRotation.mX += 0.1;
	}
	if (tenemy->mRotation.mX < CMissile::mRotation.mX){
	mRotation.mX -= 0.1;
	}
	}*/
	if (mLife > 0) {
		mLife--;
		//CCharacter::Update();
		//mPosition = mPosition + CVector(0.0f, 0.0f, 1.0f) * mMatrixRotation;
		//�s��X�V
		mMatrix = mMatrix.Scale(mScale.mX, mScale.mY, mScale.mZ) * mMatrixRotation *
			mMatrix.Translate(mPosition.mX, mPosition.mY, mPosition.mZ);
		mPosition = mPosition + CVector(0.0f, 0.0f, 1.0f) * mMatrixRotation;
	}
	else {
		mEnabled = false;
	}
}
void CMissileStandard::Collision(CCollider *m, CCollider *y) {
	//��������������
	if (CCollider::Collision(m, y)){
		switch (y->mpParent->mTaskTag){
			//������������̃^�O��EENEMY�Ȃ�
		case EENEMY:
			f = new CFire();
			f->mPosition = y->mpParent->mPosition;
			f->SetTexture("fire.tga");
			TaskManager.Add(f);
			//����������
			m->mpParent->mEnabled = false;
			//�����������������
			//y->mpParent->mEnabled = false;
			break;
		}
	}
}
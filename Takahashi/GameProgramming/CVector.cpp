#include "CVector.h"
#include "CMatrix.h"
#define _USE_MATH_DEFINES
#include <math.h>
#pragma once

CVector::CVector()
: mX(0.0f), mY(0.0f), mZ(0.0f)
{}

CVector::CVector(float x, float y, float z)
: mX(x), mY(y), mZ(z)
{}

void CVector::Set(float x, float y, float z) {
	mX = x;
	mY = y;
	mZ = z;
}

CVector CVector::Multi(const CMatrix &m) {
	CVector v;

	v.mX = mX * m.mM[0][0] + mY * m.mM[1][0] + mZ * m.mM[2][0] + m.mM[3][0];
	v.mY = mX * m.mM[0][1] + mY * m.mM[1][1] + mZ * m.mM[2][1] + m.mM[3][1];
	v.mZ = mX * m.mM[0][2] + mY * m.mM[1][2] + mZ * m.mM[2][2] + m.mM[3][2];

	return v;
}


CVector CVector::operator*(const CMatrix &m) {
	return Multi(m);
}

CVector CVector::operator + (const CVector &v) {
	return CVector(mX + v.mX, mY + v.mY, mZ + v.mZ);
}

CVector CVector::operator - (const CVector &v) {
	return CVector(mX - v.mX, mY - v.mY, mZ - v.mZ);
}
CVector CVector::operator * (const CVector &v) {
	return CVector(mX * v.mX, mY * v.mY, mZ * v.mZ);
}
CVector CVector::operator*(const float f) {
	return CVector(mX * f, mY * f, mZ * f);
}

float CVector::Length() {
	return sqrtf(mX * mX + mY * mY + mZ * mZ);
}

float CVector::dot(const CVector &v) {
	return mX*v.mX + mY*v.mY + mZ*v.mZ;
}
/* �w�肳�ꂽ�x�N�g���̕����֌�����ׂ̉�]�p�x�𓾂�
return:�bX���̉�]�p�x�@Y���̉�]�p�x�@�O�x�b
*/
CVector CVector::getRotationTowards(const CVector &dir) {
	//�ړI�ƂȂ�x�N�g���́AXZ���ʏ�ł̒��������߂�
	float sx = sqrt(dir.mX*dir.mX + dir.mY*dir.mY);
	//�ړI�ƂȂ�x�N�g���ł�X���ł̉�]�p�x�AY���ł̉�]�p�x�����߂�
	CVector rot = CVector(atan2f(-dir.mY, sx)*180.0f / M_PI, atan2f(-dir.mZ, dir.mX)*180.0f / M_PI, 0.0f);
	//�����̃x�N�g���́AXZ���ʏ�ł̒��������߂�
	sx = sqrt(mX * mX + mZ * mZ);
	//�����̃x�N�g���ł�X���ł̉�]�p�x�AY���ł̉�]�p�x�����߂�
	CVector rot1(atan2f(-mY, sx)*180.0f / M_PI, atan2f(-mZ, mX)*180.0f / M_PI, 0.0f);
	//�}�C�i�X�̊p�x�̓v���X�̊p�x�֕ϊ�����i0�x�`360�x�̊Ԃɂ���j
	if (rot.mX < 0.0f) rot.mX += 360.0f;
	if (rot.mY < 0.0f) rot.mY += 360.0f;
	if (rot1.mX < 0.0f) rot1.mX += 360.0f;
	if (rot1.mY < 0.0f) rot1.mY += 360.0f;
	//�ړI�̉�]�l�Ǝ����̉�]�l�Ƃ̍������߂�
	rot1 = rot + rot1 * -1.0f;
	//�}�C�i�X�̊p�x�̓v���X�̊p�x�֕ϊ�����i0�x�`360�x�̊Ԃɂ���j
	if (rot1.mX < 0.0f) rot1.mX += 360.0f;
	if (rot1.mY < 0.0f) rot1.mY += 360.0f;
	return rot1;	//���߂��p�x��߂�
}
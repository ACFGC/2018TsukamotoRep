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
/* 指定されたベクトルの方向へ向ける為の回転角度を得る
return:｜X軸の回転角度　Y軸の回転角度　０度｜
*/
CVector CVector::getRotationTowards(const CVector &dir) {
	//目的となるベクトルの、XZ平面上での長さを求める
	float sx = sqrt(dir.mX*dir.mX + dir.mY*dir.mY);
	//目的となるベクトルでのX軸での回転角度、Y軸での回転角度を求める
	CVector rot = CVector(atan2f(-dir.mY, sx)*180.0f / M_PI, atan2f(-dir.mZ, dir.mX)*180.0f / M_PI, 0.0f);
	//自分のベクトルの、XZ平面上での長さを求める
	sx = sqrt(mX * mX + mZ * mZ);
	//自分のベクトルでのX軸での回転角度、Y軸での回転角度を求める
	CVector rot1(atan2f(-mY, sx)*180.0f / M_PI, atan2f(-mZ, mX)*180.0f / M_PI, 0.0f);
	//マイナスの角度はプラスの角度へ変換する（0度～360度の間にする）
	if (rot.mX < 0.0f) rot.mX += 360.0f;
	if (rot.mY < 0.0f) rot.mY += 360.0f;
	if (rot1.mX < 0.0f) rot1.mX += 360.0f;
	if (rot1.mY < 0.0f) rot1.mY += 360.0f;
	//目的の回転値と自分の回転値との差を求める
	rot1 = rot + rot1 * -1.0f;
	//マイナスの角度はプラスの角度へ変換する（0度～360度の間にする）
	if (rot1.mX < 0.0f) rot1.mX += 360.0f;
	if (rot1.mY < 0.0f) rot1.mY += 360.0f;
	return rot1;	//求めた角度を戻す
}
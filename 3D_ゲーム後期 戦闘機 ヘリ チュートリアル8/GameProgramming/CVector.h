#ifndef CVECTOR
#define CVECTOR

class CMatrix;

class CVector {
public:
	float mX, mY, mZ;
	CVector();
	CVector(float x, float y, float z);
	void Set(float x, float y, float z);
	CVector Multi(const CMatrix &m);
	CVector operator*(const CMatrix &m);
	CVector operator+(const CVector &v);
	CVector operator-(const CVector &v);
	CVector operator*(const CVector &v);
	CVector operator*(const float f);
	float Length();
	float dot(const CVector &v);
	/* �w�肳�ꂽ�x�N�g���̕����֌�����ׂ̉�]�p�x�𓾂�
	return:�bX���̉�]�p�x�@Y���̉�]�p�x�@�O�x�b
	*/
	CVector getRotationTowards(const CVector &dir);
};

#endif

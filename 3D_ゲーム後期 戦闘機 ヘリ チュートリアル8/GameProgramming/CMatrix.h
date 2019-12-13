#ifndef CMATRIX
#define CMATRIX
#define PAI 3.14159
class CMatrix {
public:
	float mM[4][4];
	CMatrix();
	CMatrix Identity() ;
	CMatrix RotateY(float degree);
	CMatrix RotateX(float degree);
	CMatrix RotateZ(float degree);
	CMatrix Scale(float x, float y, float z);
	CMatrix Translate(float x, float y, float z);
	CMatrix Multi(const CMatrix &m);
	CMatrix operator*(const CMatrix &m);
	CMatrix operator-(const CMatrix &m);
	//�C�ӎ���]�s��쐬
	//Axis(��]�p�x,X���x�N�g��,Y���x�N�g��,Z���x�N�g��)
	CMatrix Axis(float degree, float x, float y, float z);
	void print();
};

#endif

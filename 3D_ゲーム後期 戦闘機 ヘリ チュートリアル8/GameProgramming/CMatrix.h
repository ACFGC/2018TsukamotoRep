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
	//任意軸回転行列作成
	//Axis(回転角度,X軸ベクトル,Y軸ベクトル,Z軸ベクトル)
	CMatrix Axis(float degree, float x, float y, float z);
	void print();
};

#endif

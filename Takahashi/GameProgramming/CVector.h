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
	/* w’è‚³‚ê‚½ƒxƒNƒgƒ‹‚Ì•ûŒü‚ÖŒü‚¯‚éˆ×‚Ì‰ñ“]Šp“x‚ğ“¾‚é
	return:bX²‚Ì‰ñ“]Šp“x@Y²‚Ì‰ñ“]Šp“x@‚O“xb
	*/
	CVector getRotationTowards(const CVector &dir);
};

#endif

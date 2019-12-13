#ifndef CMISSILE
#define CMISSILE

#include "CCharacter.h"
#include "CBox.h"
#include "CCollider.h"

class CMissile : public CCharacter {
public:
	int mLife;
	CCollider mCollider;
	CModel mAAM;
	CMissile(CModel *model, float px, float py, float pz, float rx, float ry, float rz, float sx, float sy, float sz);
	void Update();
};

#endif

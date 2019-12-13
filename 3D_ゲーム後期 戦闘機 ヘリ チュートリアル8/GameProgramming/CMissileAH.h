#ifndef CMISSILEAH
#define CMISSILEAH

#include "CCharacter.h"
#include "CBox.h"
#include "CCollider.h"

class CMissileAH : public CCharacter {
public:
	//����
	int Time = 30 * 60;
	//���ݎ���
	int mLife;
	CCollider mCollider;
	CModel mAAM;
	CMissileAH(CModel *model, float px, float py, float pz, float rx, float ry, float rz, float sx, float sy, float sz);
	void Update();
};

#endif

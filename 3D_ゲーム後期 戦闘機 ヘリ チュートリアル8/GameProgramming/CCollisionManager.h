#ifndef CCOLLISIONMANAGER
#define CCOLLISIONMANAGER

#include "CTaskManager.h"
#include"CTask.h"
#include"CCollider.h"
class CCollisionManager : public CTaskManager {
public:
	void Update();
};

#endif

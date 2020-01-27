#include"CSphereCollider.h"
#include"CCharacter.h"
bool CSphereCollider::Collision(CSphereCollider*p1,CSphereCollider*p2){
	CVector pos1 = p1->mV[0]*p1->mpParent->mMatrix;
	CVector pos2 = p2->mV[0]
		*p2->mpParent->mMatrix;
	pos1 = pos2 - pos1;
	if (pos1.Length() <p1->mRadius + p2->mRadius){
		p1->mAdjust = pos1*((p1->mRadius + p2->mRadius -
			pos1.Length()) / (p1->mRadius + p2->mRadius));
		p2->mAdjust =p1->mAdjust*-1;
		return true;
	}
	else{
		p1->mAdjust = p2->mAdjust = CVector(0.0f, 0.0f, 0.0f);
	}
	return false;
}
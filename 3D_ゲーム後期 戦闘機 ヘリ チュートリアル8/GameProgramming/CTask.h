#ifndef CTASK
#define CTASK

class CTask {
public:
	CTask *mpNext;
	CTask *mpPrev;
	int mPriority;
	bool mEnabled;
	CTask()
		: mpNext(0)
		, mpPrev(0)
		, mPriority(0)
		, mEnabled(true) {}
	enum ETaskTag{
		//�v���C���[
		EPLAYER,
		//�G
		EENEMY,
		//�v���C���[�̍U��
		EPLAYERBULLET,//�@�֖C
		EPLAYERMISSILE,//�~�T�C��
		//�G�̍U��
		EENEMYBULLET,
		//�t���A
		EFLARE,
		//���[�_�[
		ERADAR,
	};
	ETaskTag mTaskTag;
	//��Ԏ��ʎq
	enum EState{
		//����
		EDESTORY,
	};
	EState mState;//���
	//�Փˏ���
	virtual bool Collision(CTask*m, CTask*y){ return false; };
	virtual ~CTask() {};
	virtual void Update() {};
	virtual void Render() {};
};


#endif

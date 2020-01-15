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
		//プレイヤー
		EPLAYER,
		//敵
		EENEMY,
		//プレイヤーの攻撃
		EPLAYERBULLET,
		//敵の攻撃
		EENEMYBULLET,
		//フレア
		EFLARE,
	};
	ETaskTag mTaskTag;
	//衝突処理
	virtual bool Collision(CTask*m, CTask*y){ return false; };
	virtual ~CTask() {};
	virtual void Update() {};
	virtual void Render() {};
};


#endif

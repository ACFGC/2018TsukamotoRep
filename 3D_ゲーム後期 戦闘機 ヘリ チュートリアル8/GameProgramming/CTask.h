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
		EPLAYERBULLET,//機関砲
		EPLAYERMISSILE,//ミサイル
		//敵の攻撃
		EENEMYBULLET,
		//フレア
		EFLARE,
		//レーダー
		ERADAR,
	};
	ETaskTag mTaskTag;
	//状態識別子
	enum EState{
		//撃墜
		EDESTORY,
	};
	EState mState;//状態
	//衝突処理
	virtual bool Collision(CTask*m, CTask*y){ return false; };
	virtual ~CTask() {};
	virtual void Update() {};
	virtual void Render() {};
};


#endif

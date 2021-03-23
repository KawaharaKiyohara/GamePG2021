#pragma once
class Player : public IGameObject
{
public:
	Player();
	~Player();
	void Update();
	void Render(RenderContext& renderContext);
	void Move();
	void Rotation();
	void Animation();
	//‚±‚±‚©‚çƒƒ“ƒo•Ï”
	enum EnAnimationClip {
		enAnimClip_Idle,
		enAnimClip_Walk,
		enAnimClip_Jump,
		enAnimClip_Num,
	};
	ModelRender modelRender;
	Vector3 position;
	Quaternion rot;
	AnimationClip animationClips[enAnimClip_Num];
	int playerState;
	PhysicsStaticObject po;
};


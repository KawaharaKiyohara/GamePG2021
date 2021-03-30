#pragma once
class Player : public IGameObject
{
public:
	Player();
	~Player();
	void Update();
	void Render(RenderContext& renderContext);
	void Rotation();
	//ここからメンバ変数
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
	//Hands On 3 CharacterControllerクラスのオブジェクトを。
	//Playerクラスに保持させる。

	//Hands On 5 移動速度を追加する。

};


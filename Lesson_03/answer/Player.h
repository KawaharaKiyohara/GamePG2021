#pragma once
class Player : public IGameObject
{
public:
	Player();
	~Player();
	void Update();
	void Render(RenderContext& renderContext);
	void Move();
	//‚±‚±‚©‚çƒƒ“ƒo•Ï”
	ModelRender modelRender;
	Vector3 position;
};


#pragma once
class Player : public IGameObject
{
public:
	Player();
	~Player();
	void Update();
	void Render(RenderContext& renderContext);
	//‚±‚±‚©‚çƒƒ“ƒo•Ï”
	ModelRender modelRender;
};


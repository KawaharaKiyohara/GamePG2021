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
	//ここからメンバ変数
	ModelRender modelRender;
	Vector3 position;
	//クォータニオン。
};


#pragma once
class Player : public IGameObject
{
public:
	Player();
	~Player();
	void Update();
	void Render(RenderContext& renderContext);
	//ここからメンバ変数
	ModelRender modelRender;
	//Hands On 1 座標データを追加する。
	Vector3 position;
};


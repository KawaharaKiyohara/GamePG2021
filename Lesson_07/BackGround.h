#pragma once
class BackGround : public IGameObject
{
public:
	BackGround();
	~BackGround();
	void Update();
	void Render(RenderContext& renderContext);
	ModelRender modelRender;
	//Hands On 1 静的物理オブジェクト(PhysicsStaticObject)。
	//を保持させる。
	PhysicsStaticObject physicsStaticObject;
};


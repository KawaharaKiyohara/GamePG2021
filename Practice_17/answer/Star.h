#pragma once

class Player;
//☆クラス。
class Star : public IGameObject
{
public:
	Star();
	~Star();
	//更新処理。
	void Update();
	//描画処理。
	void Render(RenderContext& rc);
	//移動処理。
	void Move();
	//回転処理。
	void Rotation();

	//メンバ変数。
	ModelRender modelRender;	//モデルレンダ―。
	Vector3 position;		//座標。
	int moveCount;		//上に移動か下に移動か。
	Vector3 firstPosition;		//最初の座標。
	Quaternion rotation;	//クォータニオン。
	Player* player;		//プレイヤー。
};


#include "stdafx.h"
#include "Star.h"
#include "Player.h"

Star::Star()
{
	//TODO モデルを差し替える。
	modelRender.Init("Assets/modelData/star.tkm");
	//モデルを読み込む。
	//プレイヤーのオブジェクトを引っ張ってくる。
	player = FindGO<Player>("Player");
}

Star::~Star()
{

}

void Star::Update()
{
	//回転を加算する。
	rot.AddRotationDegY(2.0f);
	//絵描きさんに回転を教える。
	modelRender.SetRotation(rot);

	//moveCountが0の時。
	if (moveCount == 0)
	{
		//上に移動する。
		position.y += 1.0f;
	}
	//moveCountが1の時。
	else if (moveCount == 1)
	{
		//下に移動する。
		position.y -= 1.0f;
	}

	//y座標が100.0fを超えたら。
	if (position.y >= 100.0f)
	{
		//moveCountを1にする(下に移動するようにする)。
		moveCount = 1;
	}
	//y座標が-100.0fより下になったら。
	else if (position.y <= -100.0f)
	{
		//moveCountを0にする(上に移動するようにする)。
		moveCount = 0;
	}
	//絵描きさんに座標を教える。
	modelRender.SetPosition(position);

	//絵描きさんの更新処理。
	modelRender.Update();

	//プレイヤーから☆に向かうベクトルを求める。
	Vector3 diff = position - player->position;
	//プレイヤーと☆の距離が70.0fより小さかったら。
	if (diff.Length() <= 70.0f)
	{
		//自身(☆)を削除する。
		DeleteGO(this);
	}
}

void Star::Render(RenderContext& renderContext)
{
	//☆を描画する。
	modelRender.Draw(renderContext);
}
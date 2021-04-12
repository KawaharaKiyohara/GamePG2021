#include "stdafx.h"
#include "Star.h"

Star::Star()
{
	//☆のモデルを読み込む。
	modelRender.Init("Assets/modelData/star.tkm");
}

Star::~Star()
{

}

void Star::Update()
{
	//移動処理。
	Move();

	//絵描きさんの更新処理。
	modelRender.Update();
}

void Star::Move()
{
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

	//y座標が初期座標y+100.0fを超えたら。
	if (position.y >= firstPosition.y + 100.0f)
	{
		//moveCountを1にする(下に移動するようにする)。
		moveCount = 1;
	}
	//y座標が初期座標-100.0fより下になったら。
	else if (position.y <= firstPosition.y - 100.0f)
	{
		//moveCountを0にする(上に移動するようにする)。
		moveCount = 0;
	}

	//絵描きさんに座標を教える。
	modelRender.SetPosition(position);
}

void Star::Render(RenderContext& rc)
{
	//☆を描画する。
	modelRender.Draw(rc);
}
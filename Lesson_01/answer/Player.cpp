#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	//モデルを初期化する。
	modelRender.Init("Assets/modelData/unityChan.tkm");
}

Player::~Player()
{

}

void Player::Update()
{
	//Hands On 2 プレイヤーを動かしてみよう。
	position.x = position.x + 1.0f;

	//実習課題 1 プレイヤーを奥に動かしてみよう。
	position.z = position.z + 1.0f;

	//Hands On 3 座標を絵描きさんに教える。
	modelRender.SetPosition(position);

	//モデルを更新する。
	modelRender.Update();
}

void Player::Render(RenderContext& renderContext)
{
	//モデルを表示する。
	modelRender.Draw(renderContext);
}

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
	//モデルを更新する。
	modelRender.Update();
}

void Player::Render(RenderContext& renderContext)
{
	//モデルを表示する。
	modelRender.Draw(renderContext);
}

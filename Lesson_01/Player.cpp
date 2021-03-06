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
	

	//実習課題 1 プレイヤーを奥に動かしてみよう。


	//Hands On 3 座標を絵描きさんに教える。


	//モデルを更新する。
	modelRender.Update();
}

void Player::Render(RenderContext& renderContext)
{
	//モデルを表示する。
	modelRender.Draw(renderContext);
}

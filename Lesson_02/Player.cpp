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
	//Hands On 1 キャラクターを左右に動かしてみよう。

	//Hands On 2 キャラクターを複製してみよう。
	
	//Hands On 3 キャラクターをジャンプさせてみよう。
	
	//実習課題 1 ゲームパッドの上ボタンが押されたら奥に。
	//下ボタンが押されたら手前にキャラクターが動くようにしよう。
	
	//Hands On 4 重力を加えてみよう。

	//座標を絵描きさんに教える。
	modelRender.SetPosition(position);

	//モデルを更新する。
	modelRender.Update();
}

void Player::Render(RenderContext& renderContext)
{
	//モデルを表示する。
	modelRender.Draw(renderContext);
}

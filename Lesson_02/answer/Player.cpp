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
	if (g_pad[0]->IsPress(enButtonRight))  //もしもゲームパッドの右ボタンが押されたら。
	{                                      //キーボードの6キー。
		position.x += 10.0f;
	}

	if (g_pad[0]->IsPress(enButtonLeft))  //もしもゲームパッドの左ボタンが押されたら。
	{                                     //キーボードの4キー。
		position.x -= 10.0f;
	}

	//Hands On 2 キャラクターを複製してみよう。
	if (g_pad[0]->IsPress(enButtonSelect)) //もしもゲームパッドのAボタンが押されたら。
	{                                      //キーボードのスペースキー。
		NewGO<Player>(0);
	}

	//Hands On 3 キャラクターをジャンプさせてみよう。
	if (g_pad[0]->IsPress(enButtonA))    //もしもゲームパッドのAボタンが押されたら。
	{								     //キーボードのJキー。
		position.y += 5.0f;
	}

	//実習課題 1 ゲームパッドの上ボタンが押されたら奥に。
	//下ボタンが押されたら手前にキャラクターが動くようにしよう。
	if (g_pad[0]->IsPress(enButtonUp))
	{
		position.z += 10.0f;
	}

	if (g_pad[0]->IsPress(enButtonDown))
	{
		position.z -= 10.0f;
	}

	//Hands On 4 重力を加えてみよう。
	position.y -= 0.5f;

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

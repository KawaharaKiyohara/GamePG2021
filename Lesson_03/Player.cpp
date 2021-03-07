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
	Quaternion rot;

	//Hands On 1 キャラクターを右に向かせてみよう。

	//Question 1 キャラクターを左に向かせてみよう。

	//Question 2 キャラクターを奥に向かせてみよう。

	//Question 3 キャラクターを手前に向かせてみよう。

	//Hands On 2 キャラクターを右に向かせよう。

	//Question 4 パッドの左ボタンが押されたら、キャラクターが左を向くようにしてみよう。

	//Question 5 パッドの上ボタンが押されたら、キャラクターが奥を向くようにしてみよう。

	//Question 6 パッドの下ボタンが押されたら、キャラクターが奥を向くようにしてみよう。
	
	//回転を絵描きさんに教える。

	//キャラクターの移動。
	Move();

	//モデルを更新する。
	modelRender.Update();
}

void Player::Move()
{
	if (g_pad[0]->IsPress(enButtonRight))  //もしもゲームパッドの右ボタンが押されたら。
	{                                      //キーボードの6キー。
		position.x += 10.0f;
	}

	if (g_pad[0]->IsPress(enButtonLeft))  //もしもゲームパッドの左ボタンが押されたら。
	{                                     //キーボードの4キー。
		position.x -= 10.0f;
	}

	if (g_pad[0]->IsPress(enButtonSelect)) //もしもゲームパッドのAボタンが押されたら。
	{                                      //キーボードのスペースキー。
		NewGO<Player>(0);
	}

	/*if (g_pad[0]->IsPress(enButtonA))    //もしもゲームパッドのAボタンが押されたら。
	{								     //キーボードのJキー。
		position.y += 5.0f;
	}*/

	if (g_pad[0]->IsPress(enButtonUp))
	{
		position.z += 10.0f;
	}

	if (g_pad[0]->IsPress(enButtonDown))
	{
		position.z -= 10.0f;
	}

	//position.y -= 0.5f;

	//座標を絵描きさんに教える。
	modelRender.SetPosition(position);
}

void Player::Render(RenderContext& renderContext)
{
	//モデルを表示する。
	modelRender.Draw(renderContext);
}

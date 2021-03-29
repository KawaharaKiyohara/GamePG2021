#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	//アニメーションクリップをロードする。
	animationClips[enAnimClip_Idle].Load("Assets/animData/idle.tka");
	animationClips[enAnimClip_Idle].SetLoopFlag(true);
	animationClips[enAnimClip_Walk].Load("Assets/animData/walk.tka");
	animationClips[enAnimClip_Walk].SetLoopFlag(true);
	animationClips[enAnimClip_Jump].Load("Assets/animData/jump.tka");
	animationClips[enAnimClip_Jump].SetLoopFlag(false);
	//モデルを初期化する。
	modelRender.Init("Assets/modelData/unityChan.tkm",animationClips,enAnimClip_Num,enModelUpAxisY);
}

Player::~Player()
{

}

void Player::Update()
{
	//Hands On 3 ステートを使ってみよう。
	//Hands On 1 歩きアニメーションを再生してみよう。
	if (playerState == 0) {
		//ゲームパッドの上ボタンが押されていたら。
		if (g_pad[0]->IsPress(enButtonUp))
		{
			//歩きアニメーションを再生する。
			modelRender.PlayAnimation(enAnimClip_Walk);
		}
		//ゲームパッドの下ボタンが押されたら。
		else if (g_pad[0]->IsPress(enButtonDown))
		{
			//歩きアニメーションを再生する。
			modelRender.PlayAnimation(enAnimClip_Walk);
		}
		//右ボタンが押されたら。
		else if (g_pad[0]->IsPress(enButtonRight))
		{
			//歩きアニメーションを再生する。
			modelRender.PlayAnimation(enAnimClip_Walk);
		}
		//左ボタンが押されたら。
		else if (g_pad[0]->IsPress(enButtonLeft))
		{
			//歩きアニメーションを再生する。
			modelRender.PlayAnimation(enAnimClip_Walk);
		}
		//何も入力されていなければ。
		else
		{
			//立ちアニメーションを再生する。
			modelRender.PlayAnimation(enAnimClip_Idle);
		}

		//Hands On 2 ジャンプアニメーションを再生してみよう。
		//Aボタンが押されたら。
		if (g_pad[0]->IsTrigger(enButtonA))
		{
			//ジャンプアニメーションを再生する。
			modelRender.PlayAnimation(enAnimClip_Jump);
			playerState = 1;
		}
	}
	else if (playerState == 1) 
	{
		if (position.y <= 0.0f) 
		{
			//ジャンプ終わり
			playerState = 0;
		}
	}



	//キャラクターの移動。
	Move();

	//キャラクターの回転。
	Rotation();

	//モデルを更新する。
	modelRender.Update();
}

void Player::Move()
{
	if (g_pad[0]->IsPress(enButtonRight))  //もしもゲームパッドの右ボタンが押されたら。
	{                                      //キーボードの6キー。
		position.x += 5.0f;
	}

	if (g_pad[0]->IsPress(enButtonLeft))  //もしもゲームパッドの左ボタンが押されたら。
	{                                     //キーボードの4キー。
		position.x -= 5.0f;
	}

	if (g_pad[0]->IsPress(enButtonA))    //もしもゲームパッドのAボタンが押されたら。
	{								     //キーボードのJキー。
		position.y += 5.0f;
	}

	if (g_pad[0]->IsPress(enButtonUp))
	{
		position.z += 5.0f;
	}

	if (g_pad[0]->IsPress(enButtonDown))
	{
		position.z -= 5.0f;
	}

	position.y -= 0.5f;
	if (position.y <= 0.0f)
	{
		position.y = 0.0f;
	}

	//座標を絵描きさんに教える。
	modelRender.SetPosition(position);
}

void Player::Rotation()
{
	if (g_pad[0]->IsPress(enButtonRight))
	{
		rot.SetRotationDegY(90.0f);
	}

	if (g_pad[0]->IsPress(enButtonLeft))
	{
		rot.SetRotationDegY(-90.0f);
	}

	if (g_pad[0]->IsPress(enButtonUp))
	{
		rot.SetRotationDegY(0.0f);
	}

	if (g_pad[0]->IsPress(enButtonDown))
	{
		rot.SetRotationDegY(180.0f);
	}

	//回転を絵描きさんに教える。
	modelRender.SetRotation(rot);
}

void Player::Render(RenderContext& renderContext)
{
	//モデルを表示する。
	modelRender.Draw(renderContext);
}

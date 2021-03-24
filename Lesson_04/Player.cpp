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
	//Hands On 1 歩きアニメーションを再生してみよう。
		//実習課題 1 左右のボタンでも歩きアニメーションを再生できるようにしなさい。
		//Hands On 2 ジャンプアニメーションを再生してみよう。
	



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

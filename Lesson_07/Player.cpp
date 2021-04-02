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
	modelRender.Update();

	//Hands On 4 CharacterControllerクラスのオブジェクトを初期化する。
	characterController.Init(25.0f, 75.0f, position);

	SetName("Player");
}

Player::~Player()
{

}

void Player::Update()
{
	
	//キャラクターの移動。
	Move();

	//キャラクターの回転。
	Rotation();

	//キャラクターのアニメーション。
	Animation();

	//モデルを更新する。
	modelRender.Update();
}

void Player::Move()
{
	moveSpeed.x = 0.0f;
	//yはここでは、初期化しない。
	moveSpeed.z = 0.0f;

	if (playerState == 0) {
		if (g_pad[0]->IsPress(enButtonRight))
		{
			moveSpeed.x = 4.0f;
		}
		if (g_pad[0]->IsPress(enButtonLeft))
		{
			moveSpeed.x = -4.0f;
		}
		if (g_pad[0]->IsPress(enButtonUp))
		{
			moveSpeed.z = 4.0f;
		}
		if (g_pad[0]->IsPress(enButtonDown))
		{
			moveSpeed.z = -4.0f;
		}
		//地面に着いていたら。
		if (characterController.IsOnGround() == true)
		{
			//y方向の速度を0にする。
			moveSpeed.y = 0.0f;
			//Aボタンが押されたら。
			if (g_pad[0]->IsTrigger(enButtonA))
			{
				//y方向の移動速度を上げる。
				moveSpeed.y = 18.0f;
			}
		}
	}
	//重力は常に発生させる。
	moveSpeed.y -= 0.4f;

	position = characterController.Execute(moveSpeed, 1.0f);

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

void Player::Animation()
{
	if (playerState == 0) {
		//Aボタンが押されたら。
		if (g_pad[0]->IsTrigger(enButtonA))
		{
			//ジャンプアニメーションを再生する。
			modelRender.PlayAnimation(enAnimClip_Jump);
			playerState = 1;
		}
		//ゲームパッドの上ボタンが押されていたら。
		else if (g_pad[0]->IsPress(enButtonUp))
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
	}
	//ジャンプ中だったら。
	else if (playerState == 1)
	{
		//地面に着地したら。
		if (characterController.IsOnGround() == true)
		{
			//ステートを0にする(ジャンプ中ではない)。
			playerState = 0;
		}
	}
}

void Player::Render(RenderContext& renderContext)
{
	//モデルを表示する。
	modelRender.Draw(renderContext);
}

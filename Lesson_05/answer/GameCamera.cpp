#include "stdafx.h"
#include "GameCamera.h"
#include "Player.h"

GameCamera::GameCamera()
{
	g_camera3D->SetNear(250.0f);
	g_camera3D->SetFar(900.0f);
}

GameCamera::~GameCamera()
{

}

void GameCamera::Update()
{
	//Hands On 1 注視点を設定する。
	Vector3 target;
	//注視点をプレイヤーの座標に設定する。
	target.x = player->position.x;
	//y座標を少し上げる。
	target.y = player->position.y + 100.0f;
	target.z = player->position.z;
	//カメラの注視点を変更する。
	g_camera3D->SetTarget(target);

	//Hands On 2 視点を設定する。
	Vector3 cameraPos;
	cameraPos = target;
	//zを注視点から-300の位置にする。
	cameraPos.z -= 300.0f;
	//カメラの視点を変更する。
	g_camera3D->SetPosition(cameraPos);

	//Hands On 3 近平面を設定する。
	g_camera3D->SetFar(5000.0f);

	//Hands On 4 遠平面を設定する。
	g_camera3D->SetNear(1.0f);

	//Hands On 5 画角を変更する。
	timer -= 0.04f;
	float angle = g_camera3D->GetViewAngle();
	//三角関数を使用していますが、気にしないでください。
	angle += sinf(timer) / 70.0;
	g_camera3D->SetViewAngle(angle);
}



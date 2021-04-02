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
	Vector3 target;
	//注視点をプレイヤーの座標に設定する。
	target.x = player->position.x;
	//y座標を少し上げる。
	target.y = player->position.y + 100.0f;
	target.z = player->position.z;
	//カメラの注視点を変更する。
	g_camera3D->SetTarget(target);

	Vector3 cameraPos;
	cameraPos = target;
	//zを注視点から-300の位置にする。
	cameraPos.z -= 300.0f;
	//カメラの視点を変更する。
	g_camera3D->SetPosition(cameraPos);

	g_camera3D->SetFar(5000.0f);

	g_camera3D->SetNear(1.0f);
}



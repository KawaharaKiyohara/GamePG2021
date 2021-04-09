#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "GameCamera.h"
#include "BackGround.h"

Game::Game()
{
	//プレイヤーのオブジェクトを作る。
	player = NewGO<Player>(0, "player");

	//ゲームカメラのオブジェクトを作る。
	gameCamera = NewGO<GameCamera>(0, "gamecamera");

	backGround = NewGO<BackGround>(0);
}

Game::~Game()
{
	
}

//更新処理。
void Game::Update()
{
	
}
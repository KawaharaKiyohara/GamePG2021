#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "GameCamera.h"
#include "BackGround.h"
#include "Star.h"

Game::Game()
{
	//プレイヤーのオブジェクトを作る。
	player = NewGO<Player>(0, "player");

	//ゲームカメラのオブジェクトを作る。
	gameCamera = NewGO<GameCamera>(0, "gamecamera");

	//背景のオブジェクトを作る。
	backGround = NewGO<BackGround>(0);

	//Starクラスのオブジェクトを作る。
	Star* star1 = NewGO<Star>(0,"star");
	star1->position = { 100.0f,150.0f,-200.0f };
	star1->firstPosition = star1->position;

	Star* star2 = NewGO<Star>(0, "star");
	star2->position = { 1000.0f,150.0f,-200.0f };
	star2->firstPosition = star2->position;

	Star* star3 = NewGO<Star>(0, "star");
	star3->position = { 100.0f,250.0f,400.0f };
	star3->firstPosition = star3->position;

	Star* star4 = NewGO<Star>(0, "star");
	star4->position = { 2300.0f,50.0f,-200.0f };
	star4->firstPosition = star4->position;

	Star* star5 = NewGO<Star>(0, "star");
	star5->position = { 2700.0f,450.0f,400.0f };
	star5->firstPosition = star5->position;

}

Game::~Game()
{
	
}

//更新処理。
void Game::Update()
{
	
}
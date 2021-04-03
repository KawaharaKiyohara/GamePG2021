#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "BackGround.h"
#include "GameCamera.h"
//Hands On 1 Starクラスの機能を使いたいので、ヘッダーファイルをインクルードする。
#include "Star.h"

Game::Game()
{
	NewGO<BackGround>(0);
	auto player = NewGO<Player>(0);
	auto gameCamera = NewGO<GameCamera>(0);
	gameCamera->player = player;

	//Hands On 2 Starクラスのオブジェクトを作成。
	Star* star = NewGO<Star>(0);
}

Game::~Game()
{

}

void Game::Update()
{

}
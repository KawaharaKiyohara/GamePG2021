#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "BackGround.h"
#include "GameCamera.h"
#include "Star.h"

//Hands On 3 SoundEngineとWaveFileBankの機能を使いたいので。
//ヘッダーファイルをインクルードする。


Game::Game()
{
	NewGO<BackGround>(0);
	auto player = NewGO<Player>(0);
	auto gameCamera = NewGO<GameCamera>(0);
	gameCamera->player = player;

	Star* star = NewGO<Star>(0);

	//Hands On 4 WaveFileBankを使って、waveファイル(.wav)を読み込む。
	

	//Hands On 5 BGMを再生してみよう。

}

Game::~Game()
{

}

void Game::Update()
{

}
#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "BackGround.h"
#include "GameCamera.h"
#include "Star.h"

//Hands On 3 SoundEngineとWaveFileBankの機能を使いたいので。
//ヘッダーファイルをインクルードする。
#include "sound/SoundEngine.h"
#include "sound/WaveFileBank.h"

Game::Game()
{
	NewGO<BackGround>(0);
	auto player = NewGO<Player>(0);
	auto gameCamera = NewGO<GameCamera>(0);
	gameCamera->player = player;

	Star* star = NewGO<Star>(0);

	//Hands On 4 WaveFileBankを使って、waveファイル(.wav)を読み込む。
	//0は読み込んだwavファイルのされる番号。
	SoundEngine::GetInstance().GetWaveFileBank().Resist(0, "Assets/sound/shining_star.wav");

	//Hands On 5 BGMを再生してみよう。
	//SoundSouceのオブジェクトを作成する。
	bgm = NewGO<SoundSource>(0);
	//WaveFileBankから登録されたwaveファイルのデータを持ってくる。
	bgm->Init(0);
	//trueにすると、音がループする。
	bgm->Play(true);
}

Game::~Game()
{

}

void Game::Update()
{

}
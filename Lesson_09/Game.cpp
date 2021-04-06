#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "BackGround.h"
#include "GameCamera.h"
#include "Star.h"


#include "sound/SoundEngine.h"
#include "sound/WaveFileBank.h"

Game::Game()
{
	NewGO<BackGround>(0);
	auto player = NewGO<Player>(0);
	auto gameCamera = NewGO<GameCamera>(0);
	gameCamera->player = player;

	Star* star = NewGO<Star>(0);
	
	SoundEngine::GetInstance().GetWaveFileBank().Resist(0, "Assets/sound/shining_star.wav");

	bgm = NewGO<SoundSource>(0);
	//WaveFileBankから登録されたwaveファイルのデータを持ってくる。
	bgm->Init(0);
	//trueにすると、音がループする。
	bgm->Play(true);

	//Hands On 3 画像を読み込む。
	
	
	//Hands On 9 表示する文字を設定しよう。
	
}

Game::~Game()
{
	

}

void Game::Update()
{
	//Hands On 6 画像を横に動かしてみよう。
	

	//Hands On 7 画像を縦に動かしてみよう。
	

	//実習課題1 画像を左上に表示してみよう。
	

	//絵描きさんに座標を教える。


	//Hands On 4 画像の更新処理。
	
}

//Hands On 5 Render関数を追加する。

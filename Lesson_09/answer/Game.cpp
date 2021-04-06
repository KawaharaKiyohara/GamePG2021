#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "BackGround.h"
#include "GameCamera.h"
#include "Star.h"


#include "sound/SoundEngine.h"

Game::Game()
{
	NewGO<BackGround>(0);
	auto player = NewGO<Player>(0);
	auto gameCamera = NewGO<GameCamera>(0);
	gameCamera->player = player;

	Star* star = NewGO<Star>(0);
	
	g_soundEngine->ResistWaveFileBank(0, "Assets/sound/shining_star.wav");

	bgm = NewGO<SoundSource>(0);
	//WaveFileBankから登録されたwaveファイルのデータを持ってくる。
	bgm->Init(0);
	//trueにすると、音がループする。
	bgm->Play(true);

	//Hands On 3 画像を読み込む。
	spriteRender.Init("Assets/sprite/unitychan.dds", 512.0f, 512.0f);
	
	//Hands On 9 表示する文字を設定しよう。
	//文字を設定する。
	fontRender.SetText(L"Hellow World!");
	//表示する座標を設定する。
	fontRender.SetPosition({-600.0f,100.0f,0.0f});
	//表示する色を設定する。
	fontRender.SetColor(g_vec4White);
}

Game::~Game()
{
	

}

void Game::Update()
{
	//Hands On 6 画像を横に動かしてみよう。
	//Xボタンが押されたら。
	if (g_pad[0]->IsPress(enButtonX))
	{
		//画像を右に移動させる。
		position.x += 1.0f;
	}
	//Yボタンが押されたら。
	if (g_pad[0]->IsPress(enButtonY))
	{
		//画像を左に移動させる。
		position.x -= 1.0f;
	}

	//Hands On 7 画像を縦に動かしてみよう。
	//Aボタンが押されたら。
	if (g_pad[0]->IsPress(enButtonA))
	{
		//画像を上に移動させる。
		position.y += 1.0f;
	}
	//Bボタンが押されたら。
	if (g_pad[0]->IsPress(enButtonB))
	{
		//画像を下に移動させる。
		position.y -= 1.0f;
	}

	//実習課題1 画像を左上に表示してみよう。
	position.x = -640.0f;
	position.y = 360.0f;

	//絵描きさんに座標を教える。
	spriteRender.SetPosition(position);

	//Hands On 4 画像の更新処理。
	spriteRender.Update();
}

//Hands On 5 Render関数を追加する。
void Game::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
	fontRender.Draw(rc);
}
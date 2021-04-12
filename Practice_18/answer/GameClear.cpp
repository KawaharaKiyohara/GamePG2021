#include "stdafx.h"
#include "GameClear.h"
#include "Title.h"

GameClear::GameClear()
{
	//ゲームクリアの画像を読み込む。
	spriteRender.Init("Assets/sprite/gameclear.dds", 1280.0f, 720.0f);
}

GameClear::~GameClear()
{

}

//更新処理。
void GameClear::Update()
{
	//Aボタンが押されたら。
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		//タイトルのオブジェクトをつくる。
		NewGO<Title>(0, "title");
		//自身を削除する。
		DeleteGO(this);
	}
}

//描画処理。
void GameClear::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}
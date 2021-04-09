#include "stdafx.h"
#include "Title.h"
#include "Game.h"

Title::Title()
{
	spriteRender.Init("Assets/sprite/title.dds",1280.0f,720.0f);

}

Title::~Title()
{
	
}

void Title::Update()
{
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		NewGO<Game>(0, "game");
		DeleteGO(this);
	}
}

void Title::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}
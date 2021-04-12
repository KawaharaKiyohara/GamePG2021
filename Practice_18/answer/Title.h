#pragma once
#include "sound/SoundSource.h"

//タイトル。
class Title : public IGameObject
{
public:
	Title();
	~Title();
	void Update();
	void Render(RenderContext& rc);
	
	SpriteRender spriteRender;
	SoundSource* titleBGM;			//タイトルのBGM。
};


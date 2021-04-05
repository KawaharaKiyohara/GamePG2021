#pragma once
#include "sound/SoundSource.h"

class Player;
class Game : public IGameObject
{
public:
	Game();
	~Game();
	void Update();
	//Hands On 1 Render関数を追加する。
	void Render(RenderContext& rc);
	
	//ここからメンバ変数。
	Player* player;
	SoundSource* bgm;
	//Hands On 2 SpriteRenderと座標と大きさを追加する。
	SpriteRender spriteRender;
	Vector3 position;
	Vector3 scale = { 5.0f,5.0f,5.0f };
};


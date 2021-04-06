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

	//ここからメンバ変数。
	Player* player;
	SoundSource* bgm;
	//Hands On 2 SpriteRenderと座標を追加する。

	//Hands On 8 FontRenderを追加する。
	
};


#pragma once
#include "sound/SoundSource.h"

class Player;
class Game : public IGameObject
{
public:
	Game();
	~Game();
	void Update();
	//Hands On 1 Render�֐���ǉ�����B
	void Render(RenderContext& rc);
	
	//�������烁���o�ϐ��B
	Player* player;
	SoundSource* bgm;
	//Hands On 2 SpriteRender�ƍ��W�Ƒ傫����ǉ�����B
	SpriteRender spriteRender;
	Vector3 position;
	Vector3 scale = { 5.0f,5.0f,5.0f };
};


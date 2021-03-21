#pragma once
class Player;
class GameCamera : public IGameObject
{
public:
	GameCamera();
	~GameCamera();
	void Update();

	//プレイヤー。
	Player* player;
	float timer = 0;
};


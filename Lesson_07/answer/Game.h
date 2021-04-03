#pragma once
class Player;
class Game : public IGameObject
{
public:
	Game();
	~Game();
	void Update();

	Player* player;
};


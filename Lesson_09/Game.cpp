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
	//WaveFileBank����o�^���ꂽwave�t�@�C���̃f�[�^�������Ă���B
	bgm->Init(0);
	//true�ɂ���ƁA�������[�v����B
	bgm->Play(true);

	//Hands On 3 �摜��ǂݍ��ށB
	spriteRender.Init("Assets/sprite/title.dds", 64.0f, 64.0f);
	//�傫����ݒ肷��B
	spriteRender.SetScale(scale);
	spriteRender.SetPosition(position);
}

Game::~Game()
{
	

}

void Game::Update()
{
	//Hands On 5 �摜�����ɓ������Ă݂悤�B
	//X�{�^���������ꂽ��B
	if (g_pad[0]->IsPress(enButtonX))
	{
		//�摜�����Ɉړ�������B
		position.x += 1.0f;
	}
	//Y�{�^���������ꂽ��B
	if (g_pad[0]->IsPress(enButtonY))
	{
		//�摜���E�Ɉړ�������B
		position.x -= 1.0f;
	}

	//Hands On 6 �摜���c�ɓ������Ă݂悤�B
	//A�{�^���������ꂽ��B
	if (g_pad[0]->IsPress(enButtonA))
	{
		//�摜����Ɉړ�������B
		position.y += 1.0f;
	}
	//B�{�^���������ꂽ��B
	if (g_pad[0]->IsPress(enButtonB))
	{
		//�摜�����Ɉړ�������B
		position.y -= 1.0f;
	}
	//�G�`������ɍ��W��������B
	spriteRender.SetPosition(position);

	//Hands On 4 �摜�̍X�V�����B
	spriteRender.Update();
}

//Hands On 5 Render�֐���ǉ�����B
void Game::Render(RenderContext& rc)
{

	spriteRender.Draw(rc);

	//TODO FontRender������āA������g���悤�ɂ���B
	Font font;
	font.Begin(rc);
	//�����͍�����A�\�������������A���W�A�F�A��]�A�傫���A�s�{�b�g�B
	font.Draw(L"Hellow World!", { -300, 300 }, g_vec4White, 0.0f, 1.0f, { 0.0f, 0.0f });
	font.End(rc);
}
#include "stdafx.h"
#include "Star.h"

Star::Star()
{
	//���̃��f����ǂݍ��ށB
	modelRender.Init("Assets/modelData/star.tkm");
}

Star::~Star()
{

}

void Star::Update()
{
	//�ړ������B
	Move();

	//�G�`������̍X�V�����B
	modelRender.Update();
}

void Star::Move()
{
	//moveCount��0�̎��B
	if (moveCount == 0)
	{
		//��Ɉړ�����B
		position.y += 1.0f;
	}
	//moveCount��1�̎��B
	else if (moveCount == 1)
	{
		//���Ɉړ�����B
		position.y -= 1.0f;
	}

	//y���W���������Wy+100.0f�𒴂�����B
	if (position.y >= firstPosition.y + 100.0f)
	{
		//moveCount��1�ɂ���(���Ɉړ�����悤�ɂ���)�B
		moveCount = 1;
	}
	//y���W���������W-100.0f��艺�ɂȂ�����B
	else if (position.y <= firstPosition.y - 100.0f)
	{
		//moveCount��0�ɂ���(��Ɉړ�����悤�ɂ���)�B
		moveCount = 0;
	}

	//�G�`������ɍ��W��������B
	modelRender.SetPosition(position);
}

void Star::Render(RenderContext& rc)
{
	//����`�悷��B
	modelRender.Draw(rc);
}
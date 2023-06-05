#include "GameCore.h"
#include <conio.h>

GameCore::GameCore(int w, int h)
	: GameFramework(w, h), isDrawTest(false), snake(),snake_length(4),
	move(3)
{

}

GameCore::~GameCore()
{

}

void GameCore::Init()
{
	for (int i = 0; i < 4; i++)
	{
		snake[i].snake_x = width / 2 - i;
		snake[i].snake_y = height / 2;
	}
	
}

void GameCore::Update(float dt)
{
	/*_sleep(100);*/
	
	for (int i = snake_length-1 ; i > 0; i--)
	{
		snake[i].snake_x = snake[i - 1].snake_x;
		snake[i].snake_y = snake[i - 1].snake_y;
	}
	if (GetKeyDown(KeyCode::A))
	{
		move = LEFT;
	}
	else if (GetKeyDown(KeyCode::D))
	{
		move = RIGHT;
	}
	else if (GetKeyDown(KeyCode::W))
	{
		move = UP;
	}
	else if (GetKeyDown(KeyCode::S))
	{
		move = DOWN;
	}

	switch (move)
	{
	case UP:
		snake[0].snake_y--;
		break;
	case DOWN:
		snake[0].snake_y++;
		break;
	case LEFT:
		snake[0].snake_x--;
		break;
	case RIGHT:
		snake[0].snake_x++;
		break;
	default:
		break;
	}

}

void GameCore::Draw()
{

	for (int i = 0; i <= width; i++)
	{
		ScreenPrint(i, 0, "бс");
		ScreenPrint(i, height, "бс");
	}
	for (int i = 0; i <= height; i++)
	{
		ScreenPrint(0, i, "бс");
		ScreenPrint(width+1, i, "бс");
	}
	for (int i = 1; i < width; i++)
	{
		for (int j = 1; j < height; j++)
		{
			ScreenPrint(i, j, "  ");
		}
	}
	ScreenPrint(snake[0].snake_x, snake[0].snake_y, "в┬");
	for (int i = 1; i < snake_length; i++)
	{
		ScreenPrint(snake[i].snake_x, snake[i].snake_y, "б▌");
	}
}

void GameCore::Release()
{
}

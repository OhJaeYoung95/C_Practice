#include <iostream>
#include "Snake.h"

Snake::Snake() : GameFramework(0,0), xPos(10), yPos(10), dir(DIR::Left)
, type(TileType::Snake), isGetKey(false), update(true)
{
}

Snake::Snake(int w, int h, int xpos, int ypos, DIR dir, TileType type) 
	: GameFramework(w, h), xPos(xpos), yPos(ypos), dir(dir), type(type), isGetKey(false), update(true)
{

}

Snake::~Snake()
{

}

void Snake::Init()
{
}

void Snake::Update(float dt)
{
    SnakeMove();
}
void Snake::Draw()
{
    SetColor(9);
    for (int i = 0; i < 115; i++)   // 115
    {
        ScreenPrint(i, 0, "бс");
        ScreenPrint(i, 13, "бс");    // 13
    }
    for (int i = 0; i < 14; i++)    // 14
    {
        ScreenPrint(0, i, "бс");
        ScreenPrint(114, i, "бс");   // 114
    }
    SetColor(4);

    ScreenPrint(xPos, yPos, "б┌");

}

void Snake::Release()
{
}

void Snake::SnakeMove()
{
    if (GetKeyDown(KeyCode::A))
        xPos--;
    else if (GetKeyDown(KeyCode::D))
        xPos++;


}
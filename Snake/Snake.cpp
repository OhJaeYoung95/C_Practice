#include <iostream>
#include <chrono>
#include <thread>

#include "Snake.h"

Snake::Snake() : dirSelect(1), xPos(40), yPos(20), dir(Dir::Right), type(TileType::Snake),bodyLen(2)
{
    for (int i = 0; i < bodyLen; i++)
    {
        body = new Body[i];
    }
}

Snake::Snake(int _dirSelect, int _xpos, int _ypos, Dir _dir, TileType _type, int _bodyLen)
    : dirSelect(_dirSelect), xPos(_xpos), yPos(_ypos), dir(_dir), type(_type), bodyLen(_bodyLen)
{
    for (int i = 0; i < bodyLen; i++)
    {
        body = new Body[i];
    }
}


Snake::~Snake()
{
    delete[] body;
}

int Snake::GetXPos()
{
    return xPos;
}

int Snake::GetYPos()
{
    return yPos;
}


void Snake::SnakeMove()
{
    switch(dir)
    {
    case Dir::Up:
        yPos--;
            break;
    case Dir::Right:
        xPos++;
            break;
    case Dir::Down:
        yPos++;
            break;
    case Dir::Left:
        xPos--;
            break;
    }
}



void Snake::SetSnakeDir(int dir)
{
    dirSelect = dir;
}

int Snake::GetSnakeDir()
{
    return dirSelect;
}

void Snake::SnakeRoatateR()
{
    dirSelect++;
}

void Snake::SnakeRoatateL()
{
    dirSelect--;
}

void Snake::SetSnakeDirControl(Dir _dir)
{
    dir = _dir;
}


void Snake::FollowHead()
{
    for (int i = bodyLen-1; i >0 ; i--)
    {
        body[i].SetXPos(body[i - 1].GetXPos());
        body[i].SetYPos(body[i - 1].GetYPos());
    }
    body[0].SetXPos(xPos);
    body[0].SetYPos(yPos);
}

int Snake::GetBodyLen()
{
    return bodyLen;
}


int Snake::GetBodyXPos(int index)
{
    return body[index].GetXPos();
}

int Snake::GetBodyYPos(int index)
{
    return body[index].GetYPos();
}
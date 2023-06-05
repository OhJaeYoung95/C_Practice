#pragma once
//#include "Example.h"
#include "GameFramework.h"
#include "TileType.h"
#include "Body.h"

enum class Dir
{
	Up = 0,
	Right,
	Down ,
	Left
};

class Snake
{
private:
	int dirSelect;
	int xPos;
	int yPos;
	Dir dir;
	TileType type;
	Body* body;
	int bodyLen;


public:
	Snake();
	Snake(int _dirSelect, int _xpos, int _ypos, Dir _dir, TileType _type, int _bodyLen);
	~Snake();

	int GetXPos();
	int GetYPos();
	void SnakeMove();
	void SetSnakeDir(int dir);
	int GetSnakeDir();
	void SnakeRoatateR();
	void SnakeRoatateL();
	void SetSnakeDirControl(Dir _dir);


	int GetBodyLen();
	void FollowHead();
	int GetBodyXPos(int index);
	int GetBodyYPos(int index);
};
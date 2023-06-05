#pragma once
#include "TileType.h"

class Body
{

private:
	int xPos;
	int yPos;
	TileType type;
public:
	Body();
	~Body();

	void SetXPos(int _xPos);
	void SetYPos(int _yPos);
	int GetXPos();
	int GetYPos();
};
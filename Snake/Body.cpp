#include "Body.h"


Body::Body() : type(TileType::Wall)
{
}

Body::~Body()
{
}

void Body::SetXPos(int _xPos)
{
	xPos = _xPos;
}

void Body::SetYPos(int _yPos)
{
	yPos = _yPos;
}

int Body::GetXPos()
{
	return xPos;
}

int Body::GetYPos()
{
	return yPos;
}

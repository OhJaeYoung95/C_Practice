#include <iostream>
#include "Point.h"
#include "Printer.h"

using namespace std;

//void PointInit(int xPos, int yPos);
//void MovePos(int xPos, int yPos);
//void ShowPosition();
//void AddPoint(Point pos);

void Point::PointInit(int xPos, int yPos)
{
	xPos = xPos;
	yPos = yPos;
}
void Point::MovePos(int xPos, int yPos)
{
	xPos += xPos;
	yPos += yPos;
}
void Point::ShowPosition()
{
	cout << "X ÁÂÇ¥ : [" << xPos << "] Y ÁÂÇ¥ : [" << yPos << "]" << endl;
}
void Point::AddPoint(Point pos)
{
	xPos += pos.xPos;
	yPos += pos.yPos;
}
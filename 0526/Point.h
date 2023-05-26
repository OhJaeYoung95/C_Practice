#pragma once

class Point
{
private:
	int xPos;
	int yPos;

public:
	void PointInit(int xPos, int yPos);
	void MovePos(int xPos, int yPos);
	void ShowPosition();
	void AddPoint(Point pos);
};
#pragma once
class Apple
{
private:
	int xPos;
	int yPos;
	int count;
public:
	Apple();
	int GetAppleCount();
	int GetXPos();
	int GetYPos();
	void SetXPos(int _xPos);
	void SetYPos(int _yPos);
};


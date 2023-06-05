#include "Apple.h"
#include <time.h>
#include <random>

Apple::Apple() : count(3)
{
    xPos = rand() % 50;
    yPos = rand() % 50;
}

int Apple::GetAppleCount()
{
    return count;
}

int Apple::GetXPos()
{
    return xPos;
}

int Apple::GetYPos()
{
    return yPos;
}

void Apple::SetXPos(int _xPos)
{
    yPos = _xPos;
}

void Apple::SetYPos(int _yPos)
{
    xPos = _yPos;
}

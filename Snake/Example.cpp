#include "Example.h"
#include <conio.h>

Example::Example(int w, int h)
    : GameFramework(w, h), isDrawTest(false)
{

}
Example::~Example()
{

}

void Example::Init()
{

}

void Example::Update(float dt)
{
    isDrawTest = GetKey(KeyCode::W);
}

void Example::Draw()
{
    SetColor(4);
    if (isDrawTest)
    {
    }
}

void Example::Release()
{
}

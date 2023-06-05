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
   
    isDrawTest = GetKey(KeyCode::A);
}

void Example::Draw()
{
    if (isDrawTest)
    {
        ScreenPrint(0, 0, "TEST1");
        ScreenPrint(10, 10, "TEST2");
    }
}

void Example::Release()
{
}

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
        SetColor(9);
        for (int i = 0; i < 115; i++)
        {
            ScreenPrint(i, 0, "��");
            ScreenPrint(i, 13, "��");
        }
        for (int i = 0; i < 14; i++)
        {
            ScreenPrint(0, i, "��");
            ScreenPrint(114, i, "��");
        }

    }
}

void Example::Release()
{
}

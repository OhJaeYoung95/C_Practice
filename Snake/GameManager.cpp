#include <iostream>
#include <chrono>
#include <thread>
#include "Snake.h"
#include <time.h>
#include <random>

#include "GameManager.h"


GameManager::GameManager(int w, int h) : GameFramework(w, h), snake(), appleCount(3)
{
    for (int i = 0; i < appleCount; i++)
    {
        apple = new Apple[i];
    }
}

GameManager::~GameManager()
{
    delete[] apple;
}

void GameManager::Init()
{
}

void GameManager::Update(float dt)
{
    // 시간 스케일 팩터를 조정하여 시간을 가속화
    double timeScaleFactor = 5.0; // 10배 빠른 속도로 시간 흐름

    // 원하는 시간 간격
    std::chrono::milliseconds interval(80);

    // 시간 가속화를 위해 간격 조정
    std::chrono::milliseconds acceleratedInterval(static_cast<long>(interval.count() / timeScaleFactor));
    std::this_thread::sleep_for(acceleratedInterval);
    DirectSelect();
    snake.SnakeMove();
}

void GameManager::Draw()
{

    SetColor(9);
    for (int i = 6; i <= width + 6; i++)   // 115
    {
        ScreenPrint(i, 3, "■");
        ScreenPrint(i, height/2 +3, "■");    // 13
    }
    for (int i = 3; i < height/2 + 3; i++)    // 14
    {
        ScreenPrint(6, i, "■");
        ScreenPrint(width + 6, i, "■");   // 114
    }

    SetColor(14);
    for (int i = 0; i < snake.GetBodyLen(); i++)
    {
        ScreenPrint(snake.GetBodyXPos(i), snake.GetBodyYPos(i), "o");
    }
    SetColor(4);
    ScreenPrint(snake.GetXPos(), snake.GetYPos(), "O");
    snake.FollowHead();

    SetColor(4);
    AppleSetting();
    for (int i = 0; i < appleCount; i++)
    {
       ScreenPrint(apple[i].GetXPos(), apple[i].GetYPos(), "●");
    }


}

void GameManager::Release()
{
}

void GameManager::DirectSelect()
{
    if (GetKeyDown(KeyCode::A))
        snake.SnakeRoatateL();
    else if (GetKeyDown(KeyCode::D))
        snake.SnakeRoatateR();

    if (snake.GetSnakeDir() == -1)
        snake.SetSnakeDir(3);

    if (snake.GetSnakeDir() == 4)
        snake.SetSnakeDir(0);

    snake.SetSnakeDirControl((Dir)snake.GetSnakeDir());

}

void GameManager::AppleSetting()
{
    srand((unsigned int)time(NULL));

    for (int i = 0; i < appleCount; i++)
    {
        apple[i].SetXPos(rand() % 50);
        apple[i].SetYPos(rand() % 50);
    }
}

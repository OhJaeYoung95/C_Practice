#pragma once
#include "GameFramework.h"
#include "Snake.h"
#include "Apple.h"

class GameManager : public GameFramework
{
private:
    Snake snake;
    Apple* apple;
    int appleCount;


public:
    GameManager(int w, int h);
    ~GameManager();

    void Init() override;
    void Update(float dt) override;
    void Draw() override;
    void Release() override;

    void DirectSelect();
    void AppleSetting();
};
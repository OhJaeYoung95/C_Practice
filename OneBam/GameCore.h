#pragma once
#pragma once
#include "GameFramework.h"
#include "snake.h"

#define MAP_WIDTH 85
#define MAP_HEIGHT 20

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

class GameCore : public GameFramework, public Snake
{
private:
    bool isDrawTest;
    Snake snake[MAP_WIDTH - 2 * MAP_HEIGHT - 2];
    int snake_length;
    int move;
public:
    GameCore(int w, int h);
    virtual ~GameCore();

    void Init() override;
    void Update(float dt) override;
    void Draw() override;
    void Release() override;

};
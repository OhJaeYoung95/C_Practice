#include "Example.h"
#include "Snake.h"


int main(int argc, char* argv[])
{
    Snake snake(85, 20, 10, 5, DIR::Left, TileType::Snake);
    snake.ScreenInit();
    snake.Init();
    snake.Do();
    snake.Release();
    snake.ScreenRelease();
    return 0;
}

//Example game(85, 20);
//game.ScreenInit();
//game.Init();
//game.Do();
//game.Release();
//game.ScreenRelease();
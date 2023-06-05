#include "GameCore.h"

int main(int argc, char* argv[])
{
    GameCore game(MAP_WIDTH, MAP_HEIGHT);
    game.ScreenInit();
    game.Init();
    game.Do();
    game.Release();
    game.ScreenRelease();

    
    return 0;
}

#include "Example.h"
#include "GameManager.h"
#include "Snake.h"


int main()
{
	GameManager game(80, 80);
	game.ScreenInit();
	game.Init();
	game.Do();
	game.Release();
	game.ScreenRelease();    
	return 0;
}

//Example game(85, 20);
//game.ScreenInit();
//game.Init();
//game.Do();
//game.Release();
//game.ScreenRelease();
#pragma once
//#include "Example.h"
#include "GameFramework.h"
#include "TileType.h"

enum class DIR
{
	Up = 1,
	Right,
	Down,
	Left
};

class Snake : public GameFramework
{
private:
	bool update;
	bool isGetKey;
	int xPos;
	int yPos;
	DIR dir;
	TileType type;
public:
	Snake();
	Snake(int w, int h, int xpos, int ypos, DIR dir, TileType type);
	~Snake();

	void Init() override;
	void Update(float dt) override;
	void Draw() override;
	void Release() override;

	void SnakeMove();


};


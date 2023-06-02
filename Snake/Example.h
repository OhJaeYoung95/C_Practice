#pragma once
#define WALL_SIZE 1024

#include "GameFramework.h"
#include "TileType.h"



class Example : public GameFramework
{
private:
    bool isDrawTest;
    //int wallCount;
    //Wall* wall[WALL_SIZE];

public:
    Example(int w, int h);
    virtual ~Example();

    void Init() override;
    void Update(float dt) override;
    void Draw() override;
    void Release() override;

};
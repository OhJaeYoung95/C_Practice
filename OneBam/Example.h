#pragma once
#include "GameFramework.h"

class Example : public GameFramework
{
private:
    bool isDrawTest;

public:
    Example(int w, int h);
    virtual ~Example();

    void Init() override;
    void Update(float dt) override;
    void Draw() override;
    void Release() override;

};
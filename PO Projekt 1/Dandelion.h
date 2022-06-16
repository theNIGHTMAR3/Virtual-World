#pragma once
#include <Windows.h>

#include "Plant.h"
class Dandelion :
    public Plant
{

public:
    Dandelion() = default;
    Dandelion(World * world, const Coordinates pos);

    void Action() override;


    void Reproduce(Coordinates childPos) override;


    ~Dandelion();
};


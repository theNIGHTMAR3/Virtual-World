#pragma once
#include "Plant.h"
class Grass :
    public Plant
{
public:
    Grass() = default;
    Grass(World * world, const Coordinates pos);

    void Reproduce(Coordinates childPos) override;


    ~Grass();
};


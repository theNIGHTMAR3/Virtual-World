#pragma once
#include "Animal.h"
class Sheep :
    public Animal
{
public:

    Sheep() = default;
    Sheep(World * world, const Coordinates pos);

    void Reproduce(Coordinates childPos) override;
 

    ~Sheep();
};


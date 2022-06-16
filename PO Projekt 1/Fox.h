#pragma once
#include "Animal.h"
class Fox :
    public Animal
{
public:

    Fox() = default;
    Fox(World * world, const Coordinates pos);

    bool CheckDirection(Direction newDir);

    void Action() override;

    void Reproduce(Coordinates childPos) override;

    ~Fox();
};


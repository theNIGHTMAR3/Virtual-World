#pragma once
#include "Animal.h"
class Turtle :
    public Animal
{
public:

    Turtle() = default;
    Turtle(World * world, const Coordinates pos);

    void Action() override;

    bool DefendersReaction(Organism* attacker) override;

    void Reproduce(Coordinates childPos) override;

    ~Turtle();
};


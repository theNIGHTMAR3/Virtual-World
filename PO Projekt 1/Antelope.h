#pragma once
#include "Animal.h"
class Antelope :
    public Animal
{

public:

    Antelope() = default;
    Antelope(World * world, const Coordinates pos);

    //bool CheckDirection(Direction newDir);

    void Action() override;

    bool DefendersReaction(Organism* attacker) override;

    void Reproduce(Coordinates childPos) override;



    ~Antelope();
};


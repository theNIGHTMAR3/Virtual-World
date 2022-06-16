#pragma once
#include "Plant.h"
class WolfBerries :
    public Plant
{

public:
    WolfBerries() = default;
    WolfBerries(World * world, const Coordinates pos);

    bool DefendersReaction(Organism* attacker);

    void Reproduce(Coordinates childPos) override;


    ~WolfBerries();
};


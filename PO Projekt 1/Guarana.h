#pragma once
#include "Plant.h"
class Guarana :
    public Plant
{

public:
    Guarana() = default;
    Guarana(World * world, const Coordinates pos);

    bool DefendersReaction(Organism* attacker) override;

    void Reproduce(Coordinates childPos) override;


    ~Guarana();
};


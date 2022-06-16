#pragma once
#include "Plant.h"
#include "Animal.h"

class PineBorscht :
    public Plant
{
public:
    PineBorscht() = default;
    PineBorscht(World * world, const Coordinates pos);

    bool DefendersReaction(Organism * attacker) override;

    void Action() override;

    //sprawdza czy pole nale¿y do planszy
    bool CheckDirectionToKill (Direction newDir);

    void Reproduce(Coordinates childPos) override;


    ~PineBorscht();

};


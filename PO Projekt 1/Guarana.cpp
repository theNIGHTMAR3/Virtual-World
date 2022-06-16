#include "Guarana.h"

Guarana::Guarana(World* world, const Coordinates pos)
{
    this->world = world;
    this->position = pos;
    this->age = 0;
    this->strength = 0;
    this->initiative = 0;
    this->name = "Guarana";
    this->sign = 'G';

    this->world->AddOrganism(this, pos);
}

bool Guarana::DefendersReaction(Organism* attacker)
{
    attacker->ChangeStrength(3);
    return false;
}

void Guarana::Reproduce(Coordinates childPos)
{
    new Guarana(this->world, childPos);
}

Guarana::~Guarana()
{

}

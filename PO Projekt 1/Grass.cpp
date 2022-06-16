#include "Grass.h"

Grass::Grass(World* world, const Coordinates pos)
{
    this->world = world;
    this->position = pos;
    this->age = 0;
    this->strength = 0;
    this->initiative = 0;
    this->name = "Grass";
    this->sign = '#';

    this->world->AddOrganism(this, pos);
}

void Grass::Reproduce(Coordinates childPos)
{
    new Grass(this->world, childPos);
}

Grass::~Grass()
{

}
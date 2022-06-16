#include "WolfBerries.h"

WolfBerries::WolfBerries(World* world, const Coordinates pos)
{
    this->world = world;
    this->position = pos;
    this->age = 0;
    this->strength = 99;
    this->initiative = 0;
    this->name = "WolfBerries";
    this->sign = 'B';

    this->world->AddOrganism(this, pos);
}

bool WolfBerries::DefendersReaction(Organism* attacker)
{
    string tempLog = "";
    tempLog += attacker->GetName();
    tempLog += " attacks ";
    tempLog += this->GetName();
    tempLog += " and got killed by berries";
    world->AddLog(tempLog);

    //zabija atakuj¹cego
    this->world->UpdateIter();
    delete attacker;
    this->Render();

    return true;
}

void WolfBerries::Reproduce(Coordinates childPos)
{
    new WolfBerries(this->world, childPos);
}


WolfBerries::~WolfBerries()
{

}
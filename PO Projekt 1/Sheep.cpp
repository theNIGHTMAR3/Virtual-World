#include "Sheep.h"


Sheep::Sheep(World* world, const Coordinates pos)
{
	this->world = world;
	this->position = pos;
	this->age = 0;
	this->strength = 4;
	this->initiative = 4;
	this->name = "Sheep";
	this->sign = 'S';

	this->world->AddOrganism(this, pos);
}

void Sheep::Reproduce(Coordinates childPos)
{
	new Sheep(this->world, childPos);
}

Sheep::~Sheep()
{
}

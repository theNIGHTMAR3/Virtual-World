#include "Wolf.h"

Wolf::Wolf(World* world, const Coordinates pos)
{
	this->world = world;
	this->position = pos;
	this->age = 0;
	this->strength = 9;
	this->initiative = 5;
	this->name = "Wolf";
	this->sign = 'W';

	this->world->AddOrganism(this, pos);
}

void Wolf::Reproduce(Coordinates childPos)
{
	new Wolf(this->world, childPos);
}

Wolf::~Wolf()
{
	delete this;
}

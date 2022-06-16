#include "Fox.h"

Fox::Fox(World* world, const Coordinates pos)
{
    this->world = world;
    this->position = pos;
    this->age = 0;
    this->strength = 3;
    this->initiative = 7;
    this->name = "Fox";
    this->sign = 'F';

    this->world->AddOrganism(this, pos);
}

bool Fox::CheckDirection(Direction newDir)
{
	int tempX = this->position.x;
	int tempY=this->position.y;

	switch (newDir)
	{
	case UP:
		tempY--;
		break;

	case DOWN:
		tempY++;
		break;

	case LEFT:
		tempX--;
		break;

	case RIGHT:
		tempX++;
		break;
	}
	Coordinates newPos = { tempX,tempY };

	//sprawdza czy nowe pole jest puste lub jest s³absze zwierzê
	if (this->world->ReturnOrganism(newPos) == NULL || this->world->ReturnOrganism(newPos)->GetStrength() <= this->strength)
		return true;
	else return false;
	
}

void Fox::Action()
{
	this->prevPos = position;
	//ruch
	bool safe = false;
	Direction nextDir;
	//mo¿liwy ruch
	if (this->CheckDirection(UP) || this->CheckDirection(DOWN) || this->CheckDirection(LEFT) || this->CheckDirection(RIGHT))
	{
		while (safe != true)
		{
			nextDir = this->ChooseDir();
			safe = this->CheckDirection(nextDir);
		}
	}

	this->Move(nextDir);

	//render
	this->Render();
	this->world->RenderWorld();
	Sleep(200);
	system("cls");

	Organism* temp = this->CheckForCollision();
	//sprawdzanie kolizji
	if (temp != NULL)
	{
		//sprawdza czy jest funkcja obronna
		if (!temp->DefendersReaction(this))
		{
			this->Collision(this->CheckForCollision());
		}
	}

	this->AddAge();
}

void Fox::Reproduce(Coordinates childPos)
{
	new Fox(this->world, childPos);
}

Fox::~Fox()
{
}
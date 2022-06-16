#include "Turtle.h"

Turtle::Turtle(World* world, const Coordinates pos)
{
	this->world = world;
	this->position = pos;
	this->age = 0;
	this->strength = 2;
	this->initiative = 1;
	this->name = "Turtle";
	this->sign = 'T';

	this->world->AddOrganism(this, pos);
}


void Turtle::Action()
{
	int guess = rand() % 4;
	//75% szans na pozostanie w miejscu
	if (guess == 0)
	{
		Direction nextDir= this->ChooseDir();
		this->prevPos = position;
		//ruch
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
	}

	this->AddAge();
}

bool Turtle::DefendersReaction(Organism* attacker)
{
	if (attacker->GetName() == "Turtle")
		return false;
	{
		if (attacker->GetStrength() < 5)
		{
			string tempLog = "";
			tempLog += attacker->GetName();
			tempLog += " attacks ";
			tempLog += this->GetName();
			tempLog += " but got blocked ";
			world->AddLog(tempLog);

			attacker->GoBack();
			this->Render();
			this->world->RenderWorld();
			return true;
		}
		else
			return false;
	}

}

void Turtle::Reproduce(Coordinates childPos)
{
	new Turtle(this->world, childPos);
}

Turtle::~Turtle()
{
}
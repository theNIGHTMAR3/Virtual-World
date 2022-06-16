#include "Antelope.h"

Antelope::Antelope(World* world, const Coordinates pos)
{
	this->world = world;
	this->position = pos;
	this->age = 0;
	this->strength = 4;
	this->initiative = 4;
	this->name = "Antelope";
	this->sign = 'A';

	this->world->AddOrganism(this, pos);
}

bool Antelope::DefendersReaction(Organism* attacker)
{
	if (attacker->GetName() == "Antelope")
		return false;
	else
	{
	int guess = rand() % 2;
		//50% szans na ucieczkê
		if (guess == 0)
		{
			string tempLog = "";
			tempLog += attacker->GetName();
			tempLog += " attacks ";
			tempLog += this->GetName();
			tempLog += " but ";
			tempLog += this->GetName();
			tempLog += " runs away ";
			world->AddLog(tempLog);

			//sprawdzenie kierunku gdzie mo¿e uciec
			bool safe = false;
			Direction runAway;
			while (safe != true)
			{
				runAway = this->ChooseDir();
				safe = this->CheckDirection(runAway);
			}
		
			this->Move(runAway);

			//render
			this->Render();
			attacker->Render();
			this->world->RenderWorld();
			Sleep(200);
			system("cls");

			return true;
		}
		else return false;
	}
	
}

void Antelope::Action()
{
	//podwójny ruch
	for (int i = 0; i < 2 && this->sign>0; i++)
	{
		Direction nextDir = this->ChooseDir();
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

void Antelope::Reproduce(Coordinates childPos)
{
	new Antelope(this->world, childPos);
}

Antelope::~Antelope()
{
	
}
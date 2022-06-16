#include "Dandelion.h"

Dandelion::Dandelion(World* world, const Coordinates pos)
{
    this->world = world;
    this->position = pos;
    this->age = 0;
    this->strength = 0;
    this->initiative = 0;
    this->name = "Dandelion";
    this->sign = 'D';

    this->world->AddOrganism(this, pos);
}

void Dandelion::Action()
{
	bool move = false;
	//3 krotne rozmna¿anie
	for (int i = 0; i < 3; i++)
	{
	//sprawdza czy jest wolne pole
		//rozmna¿anie jeœli wiek != 0
		if (this->age != 0 && (this->CheckDirection(UP) || this->CheckDirection(DOWN) || this->CheckDirection(LEFT) || this->CheckDirection(RIGHT)))
		{
			int guess = rand() % 10;

			//10% szans na rozmno¿enie
			if (guess == 0)
			{
				Direction splitDir;
				bool safe = false;

				while (safe != true)
				{
					splitDir = this->ChooseDir();
					safe = this->CheckDirection(splitDir);
				}

				string tempLog = "";
				tempLog += this->GetName();
				tempLog += " has just splitted ";
				world->AddLog(tempLog);

				Coordinates splitPos = this->ReturnNextPos(splitDir);
				//rozmno¿enie
				this->Reproduce(splitPos);
				move = true;
			}

		}
	}

	//render jeœli ruch zosta³ wykonany
	if (move)
	{
		this->Render();
		this->world->RenderWorld();
		Sleep(200);
		system("cls");

	}

	//dodanie wieku na koniec ruchu
	this->AddAge();
}

void Dandelion::Reproduce(Coordinates childPos)
{
    new Dandelion(this->world, childPos);
}

Dandelion::~Dandelion()
{

}
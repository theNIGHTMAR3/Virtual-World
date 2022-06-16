#include "Plant.h"

void Plant::Action()
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
		}

		//render
		this->Render();
		this->world->RenderWorld();
		Sleep(200);
		system("cls");
	}



	//dodanie wieku na koniec ruchu
	this->AddAge();
}

void Plant::Collision(Organism* collider)
{
	return;
}

void Plant::GoBack()
{
	return;
}

Plant::~Plant()
{

}
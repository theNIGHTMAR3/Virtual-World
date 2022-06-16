#include "PineBorscht.h"

PineBorscht::PineBorscht(World* world, const Coordinates pos)
{
    this->world = world;
    this->position = pos;
    this->age = 0;
    this->strength = 10;
    this->initiative = 0;
    this->name = "PineBorscht";
    this->sign = '&';

    this->world->AddOrganism(this, pos);
}

bool PineBorscht::DefendersReaction(Organism* attacker)
{

    string tempLog = "";
    tempLog += attacker->GetName();
    tempLog += " attacks ";
    tempLog += this->GetName();
    tempLog += " but got killed";
    world->AddLog(tempLog);

    //zabija atakuj¹cego
    this->world->UpdateIter();
    delete attacker;
	this->Render();

    return true;
}

void PineBorscht::Action()
{
	Coordinates posToKill;
	//czy jest ktoœ w pobli¿u
	if (this->CheckDirectionToKill(UP) || this->CheckDirectionToKill(DOWN) || this->CheckDirectionToKill(LEFT) || this->CheckDirectionToKill(RIGHT))
	{
		//zabijanie s¹siednich pól
		if (this->CheckDirectionToKill(UP))
		{
			posToKill = this->ReturnNextPos(UP);

			string tempLog = "";
			tempLog += this->world->ReturnOrganism(posToKill)->GetName();
			tempLog += " moved to close to ";
			tempLog += this->GetName();
			tempLog += " and died ";
			world->AddLog(tempLog);


			delete this->world->ReturnOrganism(posToKill);
			this->Ground(posToKill);
			
		}
		if (this->CheckDirectionToKill(DOWN))
		{
			posToKill = this->ReturnNextPos(DOWN);

			string tempLog = "";
			tempLog += this->world->ReturnOrganism(posToKill)->GetName();
			tempLog += " moved to close to ";
			tempLog += this->GetName();
			tempLog += " and died ";
			world->AddLog(tempLog);


			delete this->world->ReturnOrganism(posToKill);
			this->Ground(posToKill);
		}
		if (this->CheckDirectionToKill(LEFT))
		{
			posToKill = this->ReturnNextPos(LEFT);

			string tempLog = "";
			tempLog += this->world->ReturnOrganism(posToKill)->GetName();
			tempLog += " moved to close to ";
			tempLog += this->GetName();
			tempLog += " and died ";
			world->AddLog(tempLog);


			delete this->world->ReturnOrganism(posToKill);
			this->Ground(posToKill);
		}
		if (this->CheckDirectionToKill(RIGHT))
		{
			posToKill = this->ReturnNextPos(RIGHT);

			string tempLog = "";
			tempLog += this->world->ReturnOrganism(posToKill)->GetName();
			tempLog += " moved to close to ";
			tempLog += this->GetName();
			tempLog += " and died ";
			world->AddLog(tempLog);


			delete this->world->ReturnOrganism(posToKill);	
			this->Ground(posToKill);
		}

		//render
		this->Render();
		this->world->RenderWorld();
		Sleep(200);
		system("cls");
	
	}	

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

bool PineBorscht::CheckDirectionToKill(Direction newDir)
{
	Coordinates newPos = this->ReturnNextPos(newDir);

	int tempX = newPos.x;
	int tempY = newPos.y;


	int tempW = this->world->GetWidth();
	int tempH = this->world->GetHeight();

	Organism* temp = this->world->ReturnOrganism(newPos);
	//sprawdza czy pole nale¿y do planszy i czy znajduje siê na nim organism
	if (tempX>=0 && tempX <tempW && tempY >= 0 && tempY < tempH && temp!=NULL && temp->GetName()!=this->name && dynamic_cast<Animal*>(temp))
		return true;

	else return false;
}

void PineBorscht::Reproduce(Coordinates childPos)
{
	new PineBorscht(this->world, childPos);
}

PineBorscht::~PineBorscht()
{

}
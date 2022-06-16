#include "Animal.h"


Organism* Animal::CheckForCollision()
{
	list<Organism*> orgs = this->world->GetListOfOrganisms();

	for (Organism* organism : orgs )
	{
		//równe wspó³rzêdne i nie ten sam obiekt
		if (organism->GetPosition().x == this->position.x && organism->GetPosition().y == this->position.y && organism!=this)
		{
			return organism;
			break;
		}
	}
	return NULL;
}

void Animal::Collision(Organism* defender)
{
	//rozmno¿enie
	if (this->GetName() == defender->GetName())
	{
		string tempLog = "2 ";
		tempLog += this->GetName();
		tempLog += " type animals have just met ";
		world->AddLog(tempLog);

		this->GoBack();
		defender->Render();

		//sprawdza czy jest wolne pole
		if (this->CheckDirection(UP) || this->CheckDirection(DOWN) || this->CheckDirection(LEFT) || this->CheckDirection(RIGHT))
		{
			Direction childDir;
			bool safe = false;
			while (safe != true)
			{
				childDir = this->ChooseDir();
				safe = this->CheckDirection(childDir);
			}
			tempLog += " and new ";
			tempLog += this->GetName();
			tempLog += " was born <3 ";
			world->AddLog(tempLog);

			Coordinates childPos = this->ReturnNextPos(childDir);

			this->Reproduce(childPos);
		}
	}
	//atakuj¹cy wygra³
	else if (this->GetStrength() >= defender->GetStrength())
	{
		string tempLog = "";
		tempLog += this->GetName();
		tempLog +=" attacks ";
		tempLog += defender->GetName();
		tempLog += " and won ";
		world->AddLog(tempLog);

		delete defender;
		//this->Render();
	}
	//atakuj¹cy przegra³
	else 
	{
		string tempLog = "";
		tempLog += this->GetName();
		tempLog += " attacks ";
		tempLog += defender->GetName();
		tempLog += " and lost ";
		world->AddLog(tempLog);
		
		this->world->UpdateIter();
		delete this;
		defender->Render();
	}
}

void Animal::GoBack()
{
	this->position = this->prevPos;
	this->Render();
}


void Animal::Move(Direction move)
{
	//zmieniane
	this->prevPos = position;

	switch (move)
	{
	case UP:
		if (this->position.y == 0)
			break;
		else
			this->position.y--;
		break;

	case DOWN:
		if (this->position.y == this->world->GetHeight()-1) 
			break;
		else
			this->position.y++;
		break;

	case LEFT:
		if (this->position.x == 0)
			break;
		else
			this->position.x--;
		break;

	case RIGHT:
		if (this->position.x == this->world->GetWidth() - 1)
			break;
		else
			this->position.x++;
		break;
	}

	Ground(this->prevPos);
}

void Animal::Action()
{
	this->prevPos = position;
	//ruch
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

	//dodanie wieku na koniec ruchu
	this->AddAge();
}

Animal::~Animal()
{
	
}

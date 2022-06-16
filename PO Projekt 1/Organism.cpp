#include "Organism.h"
#include "Human.h"

int Organism::GetStrength() { return this->strength; }
int Organism::GetInitiative() { return this->initiative; }
int Organism::GetAge() { return this->age; }
Coordinates Organism::GetPosition() { return this->position; }
char Organism::GetSign() { return this->sign; }
World* Organism::GetWorld() { return this->world; }
string Organism::GetName() { return this->name; }

const void Organism::Render()
{
	int tempX = this->position.x;
	int tempY = this->position.y;
	//zapisanie znaku na danych wspó³rzênych
	this->world->UpdateMap(tempX, tempY, this->sign);

	//this->world->RenderWorld();
}

void Organism::AddAge()
{
	this->age++;
}

bool Organism::DefendersReaction(Organism* attacker)
{
	return false;
}


Coordinates Organism::ReturnNextPos(Direction dir)
{
	int tempX = this->position.x;
	int tempY = this->position.y;

	switch (dir)
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

	return newPos;
}

Direction Organism::ChooseDir()
{
	srand(time(NULL));

	int guess;

	Direction newDir;

	int w = world->GetWidth();
	int h = world->GetHeight();

	int x = position.x;
	int y = position.y;

	//lewy strona
	if (x == 0)
	{
		//lewy górny róg
		if (y == 0)
		{
			guess = rand() % 2;
			newDir = (guess == 0) ? DOWN : RIGHT;
		}
		//lewy dolny róg
		else if (y = h - 1)
		{
			guess = rand() % 2;
			newDir = (guess == 0) ? UP : RIGHT;
		}
		//lewa œciana
		else
		{
			guess = rand() % 3;
			switch (guess)
			{
			case 0: newDir = UP; break;
			case 1: newDir = RIGHT; break;
			case 2: newDir = DOWN; break;
			}
		}
	}
	//prawa strona
	else if (x == w - 1)
	{
		//prawy górny róg
		if (y == 0)
		{
			guess = rand() % 2;
			newDir = (guess == 0) ? DOWN : LEFT;
		}
		//prawy dolny róg
		else if (y = h - 1)
		{
			guess = rand() % 2;
			newDir = (guess == 0) ? UP : LEFT;
		}
		//prawa œciana
		else
		{
			guess = rand() % 3;
			switch (guess)
			{
			case 0: newDir = UP; break;
			case 1: newDir = LEFT; break;
			case 2: newDir = DOWN; break;
			}
		}
	}
	//góra
	else if (y == 0)
	{
		guess = rand() % 3;
		switch (guess)
		{
		case 0: newDir = LEFT; break;
		case 1: newDir = RIGHT; break;
		case 2: newDir = DOWN; break;

		}
	}
	//dó³
	else if (y == h - 1)
	{
		guess = rand() % 3;
		switch (guess)
		{
		case 0: newDir = LEFT; break;
		case 1: newDir = RIGHT; break;
		case 2: newDir = UP; break;

		}
	}
	//œrodek
	else
	{
		newDir = (Direction)(rand() % 4);
	}

	return newDir;
}

bool Organism::CheckDirection(Direction newDir)
{
	Coordinates newPos = this->ReturnNextPos(newDir);

	//sprawdza czy nowe pole jest puste
	if (this->world->ReturnOrganism(newPos) == NULL)
		return true;
	else return false;

}

void Organism::Ground(Coordinates prev)
{
	this->world->UpdateMap(prev.x, prev.y, '.');
}

void Organism::ChangeStrength(int number)
{
	this->strength += number;

	string tempLog = "";
	tempLog += this->GetName();
	tempLog += " changed its strength by ";
	tempLog += to_string(number);
	tempLog += " and it is now ";
	tempLog += to_string(this->strength);
	world->AddLog(tempLog);
}

Organism ::~Organism()
{
	if (dynamic_cast<Human*>(this))
		this->world->HumanDead();

	//usuwa organizm z listy
	this->world->RemoveOrganism(this);
}
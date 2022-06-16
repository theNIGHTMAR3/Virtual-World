#include "World.h"
//zwierzêta
#include "Wolf.h"
#include "Sheep.h"
#include "Human.h"
#include "Fox.h"
#include "Turtle.h"
#include "Antelope.h"
//roœliny
#include "Grass.h"
#include "Guarana.h"
#include "WolfBerries.h"
#include "PineBorscht.h"
#include "Dandelion.h"

using namespace std;

//konstruktor defaultowy
World::World()
{
	humanAlive = true;
	this->width = 20;
	this->height = 20;

	//generowanie mapy
	map = new char* [width];
	for (int i = 0; i < this->width; i++)
	{
		map[i] = new char[height];
	}

	//wype³nienie mapy .
	for (int i = 0; i < this->width; i++)
	{
		for (int j = 0; j < this->height; j++)
			map[i][j] = '.';
	}
}

//konstruktor customowy
World::World(const int width, const int height)
{
	humanAlive = true;
	this->width = width;
	this->height = height;

	//generowanie mapy
	map = new char* [width];
	for (int i = 0; i < this->width; i++)
	{
		map[i] = new char[height];
	}

	//wype³nienie mapy .
	for (int i = 0; i < this->width; i++)
	{
		for (int j = 0; j < this->height; j++)
			map[i][j] = '.';
	}

	//startowe orgnizmy//

	new Wolf(this, this->RandPos());
	new Wolf(this, this->RandPos());

	new Sheep(this, this->RandPos());
	new Sheep(this, this->RandPos());

	new Fox(this, this->RandPos());
	new Fox(this, this->RandPos());

	new Human(this, this->RandPos());

	new Turtle(this, this->RandPos());
	new Turtle(this, this->RandPos());

	new Antelope(this, this->RandPos());
	new Antelope(this, this->RandPos());

	new Grass(this, this->RandPos());
	new Grass(this, this->RandPos());

	new Guarana(this, this->RandPos());
	new Guarana(this, this->RandPos());

	new WolfBerries(this, this->RandPos());
	new WolfBerries(this, this->RandPos());

	new PineBorscht(this, this->RandPos());
	new PineBorscht(this, this->RandPos());

	new Dandelion(this, this->RandPos());
	new Dandelion(this, this->RandPos());

}

//gettery
int World::GetWidth() { return this->width; }
int World::GetHeight() { return this->height; }
string World::GetLog() { return this->log; }
bool World::IsHumanAlive() { return humanAlive; }

list<Organism*> World::GetListOfOrganisms() { return this->creatures; }
list<Organism*>::iterator World::GetIter() { return this->listIter; }

//updatuje iterator po usuniêciu organizmu
void World::UpdateIter()
{
	if (*listIter != creatures.back())
		++listIter;
	else 
		listIter = creatures.begin();
}

//zwraca organizm z danego pola lub NULL
Organism* World::ReturnOrganism(Coordinates newPos)
{
	list<Organism*>::iterator iter;
	for (iter = creatures.begin(); iter != creatures.end(); ++iter)
	{
		if ((*iter)->GetPosition().x == newPos.x && (*iter)->GetPosition().y == newPos.y)
			return *iter;
	}	
	return NULL;
}

//wypisuje log i go czyœci
void World::PrintLog()
{
	cout << this->log;
	this->log = "";
}

//dodaje do logu œwiata
void World::AddLog(string log)
{
	this->log += log;
	this->log += '\n';
}

//nowa tura wszytskich organizmów
void World::NextTurn()
{
	//lista wszytskich organizmów i ich akcji
	for (listIter = creatures.begin(); listIter != creatures.end(); ++listIter)
	{
		(*listIter)->Action();
		//koñczy kiedy gra jest skoñczona
		if (this->IsGameOver() == true)
			break;
	}
}

void World::AddOrganism(Organism* org,Coordinates pos)
{
	org->Render();
	//brak organizmów
	if (creatures.empty())
	{
		creatures.push_back(org);
		return;
	}
	else
	{
		list<Organism*>::iterator iter;

		for (iter = creatures.begin(); iter != creatures.end(); ++iter)
		{
			//sprawdzanie po iniciatywie
			if (org->GetInitiative() > (*iter)->GetInitiative())
			{
				creatures.insert(iter,org);
				return;
			}
			//sprawdzanie po wieku
			else if (org->GetInitiative() == (*iter)->GetInitiative() && org->GetAge() < (*iter)->GetAge())
			{
				creatures.insert(iter, org);
				return;
			}
			//ta sama si³a i wiek, ale nie koniec listy
			else if (org->GetAge() == (*iter)->GetAge() && org->GetInitiative() == (*iter)->GetInitiative() && iter != creatures.end())
			{
				++iter;
				creatures.insert(iter, org);
				return;
			}
			//koniec listy
			else if (*iter == creatures.back())
			{
				creatures.push_back(org);
				return;
			}

		}
	}
}

Coordinates World::RandPos()
{

	bool done = false;
	int newX;
	int newY;
	Coordinates startPos;
	while (done != true)
	{
		newX = rand() % this->width;
		newY = rand() % this->height;
		startPos = { newX,newY };
		if (this->ReturnOrganism(startPos) == NULL)
			done = true;
	}

	return startPos;
}

void World::RemoveOrganism(Organism* toRemove)
{
	for (list<Organism*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
	{
		if (*iter == toRemove)
		{
			creatures.erase(iter);
			return;
		}
	}
}

void World::UpdateMap(int x, int y, char sign)
{
	this->map[y][x] = sign;
}

void World::RenderWorld()
{	
	cout << "=================================" << endl;
	cout << "|   Michal Kuprianowicz 184631  |" << endl;
	cout << "| arrows - movement, q - elixir |" << endl;
	cout << "=================================" << endl;

	for (int i = 0; i < this->width; i++)
	{
		for (int j = 0; j < this->height; j++)
			cout << map[i][j]<<" ";
		cout << endl;
	}
	cout << endl << endl;
}

//koniec gry
void World::GameOver(){ this->gameOver = true; }
bool World::IsGameOver(){ return gameOver; }


void World::HumanDead()
{
	if (this->humanAlive == true)
		humanAlive = false;
	GameOver();
}

World::~World()
{
	for (int i = 0; i < this->width; i++)
		delete[] map[i];

	delete[] map;
}
#pragma once
#include <iostream>
#include <list>

#include "Organism.h"


using namespace std;

class Organism;


class World
{
	int width;
	int height;
	char** map;
	string log;
	list <Organism*> creatures;
	bool humanAlive;
	bool gameOver = false;
	list<Organism*>::iterator listIter;
public:

	//kostruktor defaultowy
	World();
	//konstuktor mapy
	World(const int width, const int height);

	//gettery
	int GetWidth();
	int GetHeight();
	string GetLog();
	list<Organism*>::iterator GetIter();
	list<Organism*> GetListOfOrganisms();
	bool IsHumanAlive();

	//updatuje iterator po usuni�ciu organizmu
	void UpdateIter();

	//wypisuje log i go czy�ci
	void PrintLog();
	//dodaje do logu �wiata
	void AddLog(string log);

	//nowa tura wszytskich organizm�w
	void NextTurn();

	//wypisanie �wiata
	void RenderWorld();

	//update mapy
	void UpdateMap(int x, int y,char sign);

	//dodanie organixmu do �wiata
	void AddOrganism(Organism* organism, Coordinates position);
	//usuni�cie ogranizmu ze �wiata
	void RemoveOrganism(Organism* organism);

	//zwraca organizm z danego pola lub NULL
	Organism* ReturnOrganism(Coordinates newPos);

	//losuje startow� pozycj�
	Coordinates RandPos();

	//koniec gry
	void HumanDead();
	void GameOver();
	bool IsGameOver();

	//destruktor
	~World();

};


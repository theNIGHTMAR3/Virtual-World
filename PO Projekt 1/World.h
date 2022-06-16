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

	//updatuje iterator po usuniêciu organizmu
	void UpdateIter();

	//wypisuje log i go czyœci
	void PrintLog();
	//dodaje do logu œwiata
	void AddLog(string log);

	//nowa tura wszytskich organizmów
	void NextTurn();

	//wypisanie œwiata
	void RenderWorld();

	//update mapy
	void UpdateMap(int x, int y,char sign);

	//dodanie organixmu do œwiata
	void AddOrganism(Organism* organism, Coordinates position);
	//usuniêcie ogranizmu ze œwiata
	void RemoveOrganism(Organism* organism);

	//zwraca organizm z danego pola lub NULL
	Organism* ReturnOrganism(Coordinates newPos);

	//losuje startow¹ pozycjê
	Coordinates RandPos();

	//koniec gry
	void HumanDead();
	void GameOver();
	bool IsGameOver();

	//destruktor
	~World();

};


#pragma once
#include <iostream>
#include <list>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
#include <string>

#include "structures.h"
#include "World.h"

using namespace std;

class World;

class Organism
{
protected:
	int age;
	int strength;
	int initiative;
	Coordinates position;
	World* world;

	char sign;
	string name;

public:

	Organism() = default;
	
	//metody wirtualne
	virtual void Action()=0;
	virtual void Collision(Organism* collider)=0;
	virtual void GoBack() = 0;
	virtual void Reproduce(Coordinates childPos)=0;

	//rekacja obro�cy
	virtual bool DefendersReaction(Organism* attacker);

	//sprawdza czy pole jest wolne
	bool CheckDirection(Direction newDir);

	//renderuje organism
	const void Render();

	//uzupe�nienie pola pustego
	void Ground(Coordinates prev);


	//zwraca koordynaty nast�pnego ruchu
	Coordinates ReturnNextPos(Direction dir);

	//losowanie kierunku
	Direction ChooseDir();

	//gettery
	int GetStrength();
	int GetInitiative();
	int GetAge();
	Coordinates GetPosition();
	char GetSign();
	World* GetWorld();
	string GetName();

	//zmiana si�y organismu o dan� warto��
	void ChangeStrength(int number);

	//dodaje wiek
	void AddAge();

	~Organism();
};


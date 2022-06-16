#pragma once
#include <iostream>
#include <list>
#include <ctime>
#include <cstdlib>
#include <Windows.h>

#include "Organism.h"
#include "structures.h"
#include "World.h"

using namespace std;

class World;

class Animal :
    public Organism
{
protected:
	Coordinates prevPos;
public:

	Animal()=default;

	//ruch
	void Move(Direction move);

	//powrót na poprzednie pole
	void GoBack();

	//akcja
	void Action() override;

	//obs³uguje kolizje obiektu
	void Collision(Organism* collider) override;

	
	//sprawdza kolizje obiektu
	Organism* CheckForCollision();

	~Animal();
};
#pragma once

#include <iostream>
#include <list>
#include <ctime>
#include <cstdlib>
#include <Windows.h>

#include "Organism.h"
#include "structures.h"
#include "World.h"
#include "Organism.h"
class Plant :
    public Organism
{

public:
	Plant() = default;

	//akcja
	void Action() override;

	//obs³uguje kolizje obiektu
	void Collision(Organism * collider) override;

	void GoBack() override;

	//sprawdza kolizje obiektu
	//Organism* CheckForCollision();

	~Plant();
};


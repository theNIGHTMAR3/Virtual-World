#pragma once
#include "Animal.h"
class Wolf :
    public Animal
{

public:

    Wolf()=default;
    Wolf(World* world, const Coordinates pos);

    void Reproduce(Coordinates childPos) override;
    
	~Wolf();
};


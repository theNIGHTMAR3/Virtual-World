#pragma once
#include <conio.h>
#include <Windows.h>
#include <string>

#include "Animal.h"

//sterowanie
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ESC 27
#define q 113


class Human :
    public Animal
{
    bool activeAbility;
    int abilityDuration;
    int tempStrength;
    int cooldown;
public:

    Human() = default;
    Human(World * world, const Coordinates pos);

    void ActivateAbitily();
    void ManageAbitily();

    void Action() override;

    void Reproduce(Coordinates childPos) override;

   
    ~Human();
};


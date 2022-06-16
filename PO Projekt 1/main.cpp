#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <string>
#include <list>


#include "structures.h"
#include "World.h"
#include "Organism.h"
#include "Animal.h"
#include "Wolf.h"
#include "Sheep.h"

//sterowanie
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ESC 27
#define q 113


using namespace std;

int main()
{
    srand(time(NULL));

    int w, h;

    cout << "Give width and height of the world" << endl;
    cin >> w >> h;

    while (w <= 0 || h <= 0)
    {
        system("cls");
        cout << "Incorrect data" << endl;
        cout << "Give width and height of the world" << endl;
        cin >> w>> h;
    }


    World world(w, h);

    int c = 0;


    //main game loop
    while (!world.IsGameOver())
    {


        world.NextTurn();


        if (world.IsGameOver()) 
        {
            system("cls");
            world.RenderWorld();
            world.PrintLog();
        }
    }


    return 0;
}

#include "Human.h"

Human::Human(World* world, const Coordinates pos)
{
	this->world = world;
	this->position = pos;
	this->age = 0;
	this->strength = 5;
	this->initiative = 4;
	this->name = "Player";
	this->sign = 'P';

    this->activeAbility = false;
    this->abilityDuration = 0;
    this->cooldown = 0;

	this->world->AddOrganism(this, pos);
}

void Human::Action()
{
    this->prevPos = position;
	//ruch gracza
    int c = 0;
    system("cls");
    this->world->RenderWorld();
   	this->world->PrintLog();

    bool moveIsDone = false;

    cout << "Your turn" << endl;
    while (!moveIsDone)
    {
    switch (c = _getch())
        {
        case KEY_UP:
            this->Move(UP);
            moveIsDone = true;
            break;
        case KEY_DOWN:
            this->Move(DOWN);
            moveIsDone = true;
            break;
        case KEY_LEFT:
            this->Move(LEFT);
            moveIsDone = true;
            break;
        case KEY_RIGHT:
            this->Move(RIGHT);
            moveIsDone = true;
            break;
        case q:
            this->world->AddLog("used elixir");
            this->ActivateAbitily();
            moveIsDone = true;
            break;
        case ESC:
            this->world->AddLog("\nGame Over \n");
            this->world->GameOver();
            moveIsDone = true;
            break;
        default:
            continue;
        }
    }
    

    if (!this->world->IsGameOver())
    {
        system("cls");
	    //render
	    this->Render();
        this->world->RenderWorld();
        Sleep(200);
        system("cls");
    }


    Organism* temp = this->CheckForCollision();
    //sprawdzanie kolizji
    if (temp != NULL)
    {
        //sprawdza czy jest funkcja obronna
        if (!temp->DefendersReaction(this))
        {
            this->Collision(this->CheckForCollision());
        }
    }

    //dzia³anie elixiru
    this->ManageAbitily();
    
    this->AddAge();
}

void Human::ActivateAbitily()
{
    //u¿ycie elixiru
    if (this->activeAbility == false && this->abilityDuration == 0 && this->cooldown==0)
    {
        //si³a by³a mniejsza niz 10
        if (this->strength < 10)
        {
            this->tempStrength = this->strength;
            int x = 10 - this->strength;
            this->ChangeStrength(x);
            this->activeAbility = true;
        }
        //si³a >=10
        else
        {
            string tempLog = "";
            tempLog += "elixir didn't work because strength was higher or equal 10  ";
            world->AddLog(tempLog);
        }
    }
    //elixir jest w trakcie dzia³ania
    else if (this->activeAbility == true && this->abilityDuration != 0)
    {
        string tempLog = "";
        tempLog += "elixir is still working, ";
        tempLog += to_string(6-this->abilityDuration);
        tempLog += " turn to end";
        world->AddLog(tempLog);
    }
    //elixir jest na cooldownie
    else if (this->activeAbility == false && this->cooldown != 0)
    {
        string tempLog = "";
        tempLog += "elixir is on cooldown, ";
        tempLog += to_string(6 - this->cooldown);
        tempLog += " turn to end";
        world->AddLog(tempLog);
    }
}

void Human::ManageAbitily()
{
    if (this->activeAbility == true)
    {
        this->abilityDuration++;
        if (this->abilityDuration == 6)
        {
            this->abilityDuration = 0;
            this->activeAbility = false;
            this->cooldown++;
        }
        //zmniejszenie si³y
        if(this->strength>this->tempStrength && this->abilityDuration>1)
            this->ChangeStrength(-1);
    }
    else
    {
        if (this->cooldown != 0)
        {
            this->cooldown++;
            //zmniejszenie si³y
            if (this->strength > this->tempStrength)
                this->ChangeStrength(-1);
        }
        if (this->cooldown == 6)
            this->cooldown = 0;
    }
}

void Human::Reproduce(Coordinates childPos)
{
    //none
}

Human::~Human()
{
    
}
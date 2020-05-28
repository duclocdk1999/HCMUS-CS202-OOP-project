#ifndef _PEOPLE_H_ 
#define _PEOPLE_H_

#include "Header.h"
#include "Screen.h"
#include "Animal.h"
#include "Vehicle.h"

class People
{
private:
	int x, y;
	bool isDead;                            //if the player is dead
	bool isCompleted;

public:
	People();
	People(int x, int y);

	void LoadGame(istream &is, Screen &sc);
	void SaveGame(ostream &os);
	void Reset(Screen &screen);

	void Up(int k, Screen &screen);
	void Down(int k, Screen &screen);
	void Left(int k, Screen &screen);
	void Right(int k, Screen &screen);

	bool isImpact(Animal *animal);          //check if impact with an animal
	bool isImpact(VEHICLE *vehicle);

	bool isCompletedLevel();

	friend ostream& operator << (ostream& fout, const People &player);      //display the position of people
};
//-------------------------------------------------------------------------
ostream& operator << (ostream &fout, const People &player);

#endif
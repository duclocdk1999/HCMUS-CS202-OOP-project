#ifndef _GAME_H_ 
#define _GAME_H_ 

#include "Screen.h"
#include "Animal.h"
#include "People.h"
#include "VEHICLE.h"
#include <conio.h>
class Game
{
private:
	Screen screen;
	People *player;

	Bird birds[10];						//row 
	Dinosaur dinosaurs[10];				//row 
	Car cars[10];
	Truck trucks[10];

	int level;
	int difficulty;

	bool isRunning;
	bool isPaused;

public:
	Game();

	void StartGame(int diff);
	void ExitGame();
	void ResetPosition();
	void ResetGame();

	bool UpdatePosPlayer(char key, bool sysCal);
	void UpdatePosAnimalVehicle();

	void Paused();
	void Resume();

	bool IsRunning();
	bool IsPaused();

	int numberAttackers();
	int timeSleep();

	friend void ThreadScreen(Game *C);
	friend void ThreadUpdate(Game *C);

	void SaveGame(ostream &os);
	void LoadGame(istream &is);
};

#endif
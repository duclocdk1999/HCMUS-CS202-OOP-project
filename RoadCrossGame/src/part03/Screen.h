#pragma once
#ifndef SCREEN_H_
#define SCREEN_H_

#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <cstring>
#include <thread>
#include <cstdio>
using namespace std;

class Screen {
private:
	string sc[21];
	bool IsDisplay;
public:
	void Display(thread*&);
	void PrintScreen();
	void StopDisplay();
	void LoseScreen();
	void PassLevelScreen();
	void MoveBird(int OldX, int NewX);
	void MoveDinosaur(int OldX, int NewX);
	void MoveCar(int OldX, int NewX);
	void MoveTruck(int OldX, int NewX);
	void Movepeople(int OldY, int OldX, int NewY, int NewX);
	void clearS(int x, int y);
	void SaveGame(ostream &os);
	Screen();
};
void gotoxy(int x, int y);
#endif // !SCREEN_H_

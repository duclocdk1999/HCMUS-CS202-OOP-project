#pragma once
#ifndef  ANIMAL_H_
#define ANIMAL_H_
#include "Screen.h"
#include <cmath>
class  Animal
{
protected:
	int x;
public:
	Animal();
	Animal(int);
	virtual void move(Screen &sc, int direction) = 0;
	virtual void tell() = 0;
	virtual bool IsImpact(int y, int x) = 0;
	virtual bool IsImpact(int y, int x, int typeY);
	virtual void Delete(Screen &sc) = 0;
	void SaveGame(ostream &os);
	virtual void LoadGame(istream &is, Screen &sc) = 0;
};

class Bird : public Animal {
public:
	Bird() { x = 0; }
	Bird(int x) : Animal(x) {}
	void move(Screen &sc, int direction);
	void tell();
	bool IsImpact(int y, int x);
	void Delete(Screen &sc);
	//void SaveGame(ostream &os);
	void LoadGame(istream &is, Screen &sc);
};

class Dinosaur : public Animal {
public:
	Dinosaur() { x = 0; }
	Dinosaur(int x) : Animal(x) {}
	void move(Screen &sc, int direction);
	void tell();
	bool IsImpact(int y, int x);
	void Delete(Screen &sc);
	void LoadGame(istream &is, Screen &sc);
	//void SaveGame(ostream &os);
};
#endif // ! ANIMAL_H_

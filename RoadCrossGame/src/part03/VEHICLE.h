#ifndef VEHICLE_h_

using namespace std;

#include<iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <cstring>
#include <thread>
#include <cstdio>
#include  "Screen.h"

/////////////////////////////////////LUAN////////////////////////////////////////////////////
class VEHICLE
{
public:
	VEHICLE();
	VEHICLE(int x);
	virtual bool IsImpact(int x, int y, int consty);

	//void Save(ostreamm &);
	virtual void Move(Screen &sc, int direction) = 0;
	virtual void SoundFx() = 0;
	virtual bool IsImpact(int y, int x) = 0;
	virtual void Delete(Screen &sc) = 0;
	void SaveGame(ostream &os);
	virtual void LoadGame(istream &is, Screen &sc) = 0;
protected:
	int x;

};

class Truck : public VEHICLE
{
public:
	Truck();
	Truck(int x) : VEHICLE(x) {};
	bool IsImpact(int x, int y);
	void SoundFx();
	void Move(Screen &screen, int direc);
	void Delete(Screen &sc);
	//void Save (ostream &);
	void LoadGame(istream &is, Screen &sc);

};
class Car : public VEHICLE
{
public:
	Car();
	Car(int x) : VEHICLE(x) {};

	bool IsImpact(int x, int y);
	void SoundFx();
	void Move(Screen &screen, int direc);
	void Delete(Screen &sc);
	//void Save (ostream &);
	void LoadGame(istream &is, Screen &sc);

};
#endif // !VEHICLE_h_
#pragma once

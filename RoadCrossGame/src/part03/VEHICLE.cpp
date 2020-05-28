#include "VEHICLE.h"

void Car::LoadGame(istream &is, Screen &sc) {
	is.read((char *)&x, 4);
	sc.MoveCar(-1, x);
}
void Truck::LoadGame(istream &is, Screen &sc) {
	is.read((char *)&x, 4);
	sc.MoveTruck(-1, x);
}
void VEHICLE::SaveGame(ostream &os) {
	os.write((char *)&x, 4);
}

VEHICLE::VEHICLE()
{
	x = -1;
}

VEHICLE::VEHICLE(int x)
{
	this->x = x;
}

Car::Car()
{
	this->x = -1;
	//this->y = 5;
}



Truck::Truck()
{
	this->x = -1;
	//this->y = 1;

}




bool VEHICLE::IsImpact(int y, int x, int consty)
{
	if (abs(x - this->x) < 3 && abs(y - consty) < 2) return true;
	else return false;
}

bool Truck::IsImpact(int x, int y)
{
	bool check = VEHICLE::IsImpact(x, y, 1);
	if (check)
		this->SoundFx();
	return check;
}

bool Car::IsImpact(int x, int y)
{
	bool check = VEHICLE::IsImpact(x, y, 5);
	if (check)
		this->SoundFx();
	return check;
}



void Car::Move(Screen &screen, int direc)
{
	screen.MoveCar(x, x + direc);
	x = x + direc;
	x = (x + 60) % 60;
}

void Truck::Move(Screen &screen, int direc)
{
	screen.MoveTruck(x, x + direc);
	x = x + direc;
	x = (x + 60) % 60;
}

void Car::Delete(Screen &screen)
{
	screen.MoveCar(x, -1);
	x = -1;
}

void Truck::Delete(Screen &screen)
{
	screen.MoveTruck(x, -1);
	x = -1;
}

void Truck::SoundFx() {
	mciSendString("play sound/Truck.wav", NULL, 0, NULL);
}
void Car::SoundFx() {
	mciSendString("play sound/Car.wav", NULL, 0, NULL);
}
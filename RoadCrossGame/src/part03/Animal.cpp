#include "Animal.h"

void Bird::LoadGame(istream &is, Screen &sc) {
	is.read((char *)&x, 4);
	sc.MoveBird(-1, x);
}
void Dinosaur::LoadGame(istream &is, Screen &sc) {
	is.read((char *)&x, 4);
	sc.MoveDinosaur(-1, x);
}
void Animal::SaveGame(ostream &os) {
	os.write((char *)&x, 4);
}
Animal::Animal()
{
	x = -1;
}
Animal::Animal(int x) {
	this->x = x;
}
bool Animal::IsImpact(int y, int x, int typeY) {
	if (abs(x - this->x) < 3 && abs(y - typeY) < 2) {
		return true;
	}
	return false;
}
void Bird::move(Screen &sc, int direction) {
	sc.MoveBird(x, x + direction);
	x += direction;
	x = (x + 60) % 60;
}
void Bird::tell() {
	//sound will add later
	mciSendString("play sound/Bird.wav", NULL, 0, NULL);
}
bool Bird::IsImpact(int y, int x) {
	bool check = Animal::IsImpact(y, x, 12);
	if (check)
		this->tell();
	return check;
}
void Bird::Delete(Screen &sc) {
	sc.MoveBird(x, -1);
	x = -1;
}
void Dinosaur::move(Screen &sc, int direction) {
	sc.MoveDinosaur(x, x + direction);
	x += direction;
	x = (x + 60) % 60;
}
void Dinosaur::tell() {
	//sound will add later
	mciSendString("play sound/Dino.wav", NULL, 0, NULL);
}
bool Dinosaur::IsImpact(int y, int x) {
	bool check = Animal::IsImpact(y, x, 9);
	if (check)
		this->tell();
	return check;
}
void Dinosaur::Delete(Screen &sc) {
	sc.MoveDinosaur(x, -1);
	x = -1;
}
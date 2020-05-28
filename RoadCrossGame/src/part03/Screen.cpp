#include "Screen.h"
const string birdshape[2] = { "\\./"
,".Y." };
const string dinosaurshape[2] = { "./("
,"/T\\" };
const string carshape[2] = { "/T\\"
,"ooo" };
const string truckshape[2] = { "TTT"
,"ooo" };
const string peopleshape[2] = { ".o."
,".Y." };
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void gotoxy(int x, int y) //goes to x,y console
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void Screen::SaveGame(ostream &os) {
	char x;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 60; j++) {
			x = sc[i][j];
			os.write((char*)&x, 1);
		}
	}
}
void Screen::PrintScreen() {
	int co = 0; bool trafficLight = 0, check = 0;
	while (IsDisplay) {
		gotoxy(0, 2);
		for (int i = 0; i < 20; i++)
		{
			cout << sc[i];
			if (i == 4 || i == 5 || i == 0 || i == 1) {
				SetConsoleTextAttribute(hConsole, 10);
				cout << "##";
				SetConsoleTextAttribute(hConsole, 15);
			}
			if (i == 8 || i == 9 || i == 12 || i == 13) {
				if (i == 8 || i == 9)
					check = 0;
				else check = 1;
				if (trafficLight^check) {
					SetConsoleTextAttribute(hConsole, 10);
					cout << "##";
					SetConsoleTextAttribute(hConsole, 15);
				}
				else {
					SetConsoleTextAttribute(hConsole, 12);
					cout << "##";
					SetConsoleTextAttribute(hConsole, 15);
				}
			}
			cout << "\n";
		}
		Sleep(50);
		co++;
		if (co % 15 == 0)
			trafficLight = !trafficLight;
	}
}
void Screen::Display(thread* &t) {
	if (IsDisplay == false) {
		IsDisplay = true;
		t = new thread(&Screen::PrintScreen, this);
	}
}
Screen::Screen() {
	char c;
	for (int i = 0; i < 20; i++) {
		sc[i] = "";
		if ((i + 1) % 4 == 0)
			c = '_';
		else c = '.';
		for (int j = 0; j < 60; j++)
			sc[i] += c;
	}
	IsDisplay = false;
}
void Screen::StopDisplay() {
	IsDisplay = false;
}
void Screen::clearS(int x, int y) {
	for (int i = x; i < x + 3; i++)
		for (int j = y; j < y + 2; j++) {
			if ((j + 1) % 4 == 0)
				sc[j][i] = '_';
			else sc[j][i] = '.';
		}
}
void Screen::MoveBird(int OldX, int NewX) {
	if (OldX > -1 && OldX + 3 <= 60)
		clearS(OldX, 12);
	if (NewX > -1 && NewX + 3 <= 60) {
		for (int j = 12; j < 14; j++)
			for (int i = NewX; i < NewX + 3; i++) {
				sc[j][i] = birdshape[j - 12][i - NewX];
			}
	}
}
void Screen::MoveDinosaur(int OldX, int NewX) {
	if (OldX > -1 && OldX + 3 <= 60)
		clearS(OldX, 9);
	if (NewX > -1 && NewX + 3 <= 60) {
		for (int j = 9; j < 11; j++)
			for (int i = NewX; i < NewX + 3; i++) {
				sc[j][i] = dinosaurshape[j - 9][i - NewX];
			}
	}
}
void Screen::MoveCar(int OldX, int NewX) {
	if (OldX > -1 && OldX + 3 <= 60)
		clearS(OldX, 5);
	if (NewX > -1 && NewX + 3 <= 60) {
		for (int j = 5; j < 7; j++)
			for (int i = NewX; i < NewX + 3; i++) {
				sc[j][i] = carshape[j - 5][i - NewX];
			}
	}
}
void Screen::MoveTruck(int OldX, int NewX) {
	if (OldX > -1 && OldX + 3 <= 60)
		clearS(OldX, 1);
	if (NewX > -1 && NewX + 3 <= 60) {
		for (int j = 1; j < 3; j++)
			for (int i = NewX; i < NewX + 3; i++) {
				sc[j][i] = truckshape[j - 1][i - NewX];
			}
	}
}
void Screen::Movepeople(int OldY, int OldX, int NewY, int NewX) {
	if (OldX > -1 && OldX + 3 <= 60 && OldY > -1 && OldY + 2 <= 20)
		clearS(OldX, OldY);
	if (NewX > -1 && NewX + 3 <= 60 && NewY > -1 && NewY + 2 <= 20) {
		for (int j = NewY; j<NewY + 2; j++)
			for (int i = NewX; i < NewX + 3; i++) {
				sc[j][i] = peopleshape[j - NewY][i - NewX];
			}
	}
}
void Screen::LoseScreen() {
	system("cls");
	SetConsoleTextAttribute(hConsole, 12);
	gotoxy(20, 10);
	cout << "You are Lose (T.T)";
	gotoxy(18, 11);
	cout << "Press any key to continue";
	SetConsoleTextAttribute(hConsole, 15);
}
void Screen::PassLevelScreen() {
	system("cls");
	for (int i = 0; i < 10; i++)
		cout << "\n";
	for (int i = 0; i < 20; i++)
		cout << " ";
	SetConsoleTextAttribute(hConsole, 10);
	cout << "Congratulations!\n";
	for (int i = 0; i < 15; i++)
		cout << " ";
	cout << "But next level is harder (^.^)";
	SetConsoleTextAttribute(hConsole, 15);
}
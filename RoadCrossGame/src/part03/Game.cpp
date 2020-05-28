#include "Game.h"

void ThreadScreen(Game *C)
{
	while (C->IsRunning())
	{
		if (!C->IsPaused())
		{
			C->screen.PrintScreen();
		}
	}
}
//-----------------------------------------
void ThreadUpdate(Game *C)
{
	while (C->IsRunning())
	{
		if (!C->IsPaused())
		{
			C->UpdatePosAnimalVehicle();
		}
	}
}
//-----------------------------------------
void Game::LoadGame(istream &is) {
	this->isRunning = false;
	is.read((char *)&level, 4);
	is.read((char *)&difficulty, 4);

	screen = Screen();
	player->LoadGame(is, screen);
	int n = this->numberAttackers();
	for (int i = 0; i < n; i++) {
		birds[i].LoadGame(is, screen);
		dinosaurs[i].LoadGame(is, screen);
		cars[i].LoadGame(is, screen);
		trucks[i].LoadGame(is, screen);
	}

	// start
	this->isRunning = true;
	thread* second = new thread(ThreadUpdate, this);
}
void Game::SaveGame(ostream &os) {
	os.write((char *)&level, 4);
	os.write((char *)&difficulty, 4);

	//save children
	player->SaveGame(os);
	int n = this->numberAttackers();
	for (int i = 0; i < n; i++) {
		birds[i].SaveGame(os);
		dinosaurs[i].SaveGame(os);
		cars[i].SaveGame(os);
		trucks[i].SaveGame(os);
	}
	//screen.SaveGame(os);
}
Game::Game()
{
	this->player = new People();
	this->level = 0;
	this->isRunning = false;
	this->isPaused = true;
}
//-----------------------------------------
void Game::StartGame(int diff)
{
	this->isRunning = true;
	this->isPaused = false;

	this->difficulty = diff;

	this->ResetPosition();

	//thread first(ThreadScreen, this);
	//thread second(ThreadUpdate, this);

	thread* second = new thread(ThreadUpdate, this);
	thread* DisplayThread = NULL;
	screen.Display(DisplayThread);
	//first.join();
	//second.join();
}
//-----------------------------------------
void Game::ResetPosition()
{
	gotoxy(28, 0);
	cout << "Level " << this->level + 1;
	for (int i = 0; i < this->numberAttackers(); i++)
	{
		int new_collumn;
		birds[i].Delete(screen);
		new_collumn = LENGTH / numberAttackers() * i + rand() % (LENGTH / numberAttackers() - 5);
		birds[i] = Bird(new_collumn);

		dinosaurs[i].Delete(screen);
		new_collumn = LENGTH / numberAttackers() * i + rand() % (LENGTH / numberAttackers() - 5);
		dinosaurs[i] = Dinosaur(new_collumn);

		cars[i].Delete(screen);
		new_collumn = LENGTH / numberAttackers() * i + rand() % (LENGTH / numberAttackers() - 5);
		cars[i] = Car(new_collumn);

		trucks[i].Delete(screen);
		new_collumn = LENGTH / numberAttackers() * i + rand() % (LENGTH / numberAttackers() - 5);
		trucks[i] = Truck(new_collumn);
	}
	player->Reset(screen);
}
//-----------------------------------------
void Game::ResetGame()
{
	screen.StopDisplay();
	screen = Screen();
	this->isRunning = false;
	this->level = 0;
	this->isPaused = true;
}
//-----------------------------------------
void Game::ExitGame()
{
	screen.StopDisplay();
	this->isRunning = false;
}
//-----------------------------------------
bool Game::UpdatePosPlayer(char key, bool sysCal)
{
	switch (key)
	{
	case 'w': player->Up(1, this->screen);    break;
	case 'a': player->Left(1, this->screen);  break;
	case 's': player->Down(1, this->screen);  break;
	case 'd': player->Right(1, this->screen); break;
	}

	if (this->player->isCompletedLevel())
	{
		this->player->Reset(screen);

		//delete birds out of screen		
		/*for (int i = 0; i < this->numberAttackers(); i++)
		{
		birds[i].Delete(screen);
		dinosaurs[i].Delete(screen);

		//vehicle delete
		cars[i].Delete(screen);
		trucks[i].Delete(screen);
		}*/
		// complete screen
		this->Paused();
		Sleep(50);
		screen.PassLevelScreen();
		Sleep(1500);


		//reset animal + vehicle

		this->level++;
		if (this->level == 10) {
			for (int i = 0; i < this->numberAttackers(); i++)
			{
				birds[i].Delete(screen);
				dinosaurs[i].Delete(screen);

				//vehicle delete
				cars[i].Delete(screen);
				trucks[i].Delete(screen);
			}
			this->level = 0;
		}
		this->ResetPosition();

		this->Resume();
	}
	else
	{
		//if player isImpact... -> 

		for (int i = 0; i < this->numberAttackers(); i++)
			if (player->isImpact(&birds[i]) || player->isImpact(&dinosaurs[i]) ||
				player->isImpact(&cars[i]) || player->isImpact(&trucks[i]))
			{
				this->ExitGame();

				// lose screen
				//Sleep(50);
				screen.LoseScreen();
				Sleep(1500);
				if (sysCal == true)
					int x = _getch();

				return true;
			}
	}
	return true;
}
//-----------------------------------------
void Game::UpdatePosAnimalVehicle()
{

	for (int i = 0; i < this->numberAttackers(); i++)
	{
		birds[i].move(screen, 1);
		dinosaurs[i].move(screen, -1);
		cars[i].Move(screen, 1);
		trucks[i].Move(screen, -1);
		this->UpdatePosPlayer('m', false);
	}
	Sleep(timeSleep());
}
//-----------------------------------------
int Game::numberAttackers()
{
	return this->level / 2 + 1;
}
//-----------------------------------------
int Game::timeSleep()
{
	return 1000 - ((this->level + 1) / 2) * 110 - (difficulty * 160);
}
//-----------------------------------------
bool Game::IsRunning()
{
	return this->isRunning;
}
//-----------------------------------------
bool Game::IsPaused()
{
	return this->isPaused;
}
//-----------------------------------------
void Game::Paused()
{
	screen.StopDisplay();
	this->isPaused = true;
}
//-----------------------------------------
void Game::Resume()
{
	system("cls");
	gotoxy(28, 0);
	cout << "Level " << this->level + 1;
	thread* DisplayThread = NULL;
	screen.Display(DisplayThread);
	this->isPaused = false;
}
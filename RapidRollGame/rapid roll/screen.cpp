#include "screen.h"

void gotoxy(int hang, int cot) // di chuyen con tro man hinh toi (hang, cot) tren console
{
	COORD coord;
	coord.X = cot;
	coord.Y = hang;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//---------------------------------------------
void display(char a[100][100])
{
	for (int i = 0; i < SO_HANG; i++)
	{
		for (int j = 0; j < SO_COT; j++)
			printf("%c", a[i][j]);			
		printf("\n");
	}
}
//---------------------------------------------
void ghiMenu()
{
	gotoxy(SO_HANG / 2, SO_COT + 2);
	printf("rapid Roll Game");
	gotoxy(SO_HANG / 2 + 1, SO_COT + 2);
	printf("score: ");
}
//---------------------------------
void goodbye(int score)
{
	gotoxy(0, 0);
	for (int i = 0; i < SO_HANG; i++)
	{
		if (i == 0)
			printf("%c", 201);
		else
			if (i == SO_HANG - 1)
				printf("%c", 200);
			else
				printf("%c", 186);

		if (i == 0 || i == SO_HANG - 1)
			for (int j = 1; j < SO_COT - 1; j++)
				printf("%c", 205);
		else
			for (int j = 1; j < SO_COT - 1; j++)
				printf(" ");
		
		if (i == 0)
			printf("%c\n", 187);
		else
			if (i == SO_HANG - 1)
				printf("%c\n", 188);
			else
				printf("%c\n", 186);
	}

	if (score >= 500)
	{
		gotoxy(SO_HANG / 2, 2);
		printf("Congratulation !");
		gotoxy(SO_HANG / 2 + 1, 2);
		printf("You won");
	}
	else
	{
		gotoxy(SO_HANG / 2, 2);
		printf("You Lose");
		gotoxy(SO_HANG / 2 + 1, 2);
		printf("try again ?");
	}
}
//--------------------------------------------
void inQuaBong(int hang, int cot)
{
	gotoxy(hang, cot);
	printf("%c", 219);
	printf("%c", 219);
}
//--------------------------------------------
void inThanhNgang(int hang, int cot, int do_dai_thanh, bool cam_bay)
{
	gotoxy(hang, cot);
	
	if (cam_bay == false)
		for (int i = 0; i < do_dai_thanh; i++)
			printf("%c", 205);
	else
		printf("%c", 207);
}
//--------------------------------------------
void inKhungTroChoi()
{
	printf("%c", 201);	//top left
	printf("%c", 205);	// =
	printf("%c", 187);	//top right
	printf("\n");
	printf("%c", 186);	// ||
	printf(" ");
	printf("%c", 186);
	printf("\n");
	printf("%c", 200);	// bottom left
	printf("%c", 205);
	printf("%c", 188);	// bottom right
}
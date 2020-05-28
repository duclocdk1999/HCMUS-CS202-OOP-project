#include "logic.h"

//----------------------------------------------------------------
void initGame(QuaBong &ball, ThanhNgang thanh[], char a[100][100])
{
	for (int i = 0; i < SO_HANG; i++)
		for (int j = 0; j < SO_COT; j++)
			a[i][j] = ' ';

	for (int j = 0; j < SO_COT; j++)
	{
		a[0][j] = char(205);
		a[SO_HANG - 1][j] = char(205);
	}

	for (int i = 0; i < SO_HANG; i++)
	{
		a[i][0] = char(186);
		a[i][SO_COT - 1] = char(186);
	}

	a[0][0] = char(201);
	a[SO_HANG - 1][0] = char(200);
	a[0][SO_COT - 1] = char(187);
	a[SO_HANG - 1][SO_COT - 1] = char(188);

	ball.hang = 1;
	ball.cot = 10;

	for (int i = 0; i < SO_THANH_NGANG; i++)
	{
		thanh[i].hang = i * 2 - 1;
		
		do {
			thanh[i].cot = rand() % (SO_COT - DO_DAI_THANH - 1) + 1;
		} while (thanh[i].cot <= ball.cot && thanh[i].cot + DO_DAI_THANH >= ball.cot);

		thanh[i].cam_bay = false;
	}
}
//-----------------------------------------------------------------
void capNhatViTriTuBanPhim(QuaBong &ball, ThanhNgang thanh[], char a[100][100])
{
	char kitu = nhapTuBanPhim();
	if (kitu == KEY_LEFT)
	{
		if (ball.cot > 1)
		{
			a[ball.hang][ball.cot] = ' ';
			ball.cot--;
			a[ball.hang][ball.cot] = 'O';
		}
	}
	else
		if (kitu == KEY_RIGHT)
		{
			if (ball.cot < SO_COT - 2)
			{
				a[ball.hang][ball.cot] = ' ';
				ball.cot++;
				a[ball.hang][ball.cot] = 'O';	
			}
		}
		else
			if (kitu == KEY_ESC)
			{
				ball.exit_game = true;
			}

	if (ball.hang < 1 || ball.hang > SO_HANG - 1)
	{
		ball.exit_game = true;
	}
	else
	{
		for (int i = 0; i < SO_THANH_NGANG; i++)
			if (ball.hang == thanh[i].hang)
			{
				if (ball.cot < thanh[i].cot + DO_DAI_THANH && ball.cot >= thanh[i].cot)
				{
					if (thanh[i].cam_bay == true)
					{
						ball.exit_game = true;
					}
					else
					{
						a[ball.hang][ball.cot] = '=';
						ball.hang--;
						a[ball.hang][ball.cot] = 'O';
					}
					break;
				}
			}
	}
}
//--------------------------------------------------------------------
void capNhatViTri(QuaBong &ball, ThanhNgang thanh[], char a[100][100], int score)
{
	if (ball.hang < SO_HANG - 1 && ball.hang > 0)
	{
		if (score < 400)
			Sleep(500 - score);
		else
			Sleep(100);

		if (a[ball.hang + 1][ball.cot] == ' ')
		{
			a[ball.hang][ball.cot] = ' ';
			ball.hang++;
			a[ball.hang][ball.cot] = 'O';
		}
		else 
			if (ball.hang == SO_HANG - 2)
			{
				ball.exit_game = true;
			}

		for (int i = 0; i < SO_THANH_NGANG; i++)
		{
			if (thanh[i].hang > 0)
			{
				if (thanh[i].hang < SO_HANG - 1)
					for (int j = 0; j < DO_DAI_THANH; j++)
						a[thanh[i].hang][thanh[i].cot + j] = ' ';
				else
				{
					thanh[i].cot = rand() % (SO_COT - DO_DAI_THANH - 1) + 1;
					thanh[i].cam_bay = rand() % 2;
				}

				thanh[i].hang--;
			}
			else
				thanh[i].hang = SO_HANG - 1;

			if (thanh[i].hang > 0 && thanh[i].hang < SO_HANG - 1)
			{
				char kitu_thanh = char(205);		//thanh ko gai
				if (thanh[i].cam_bay == true)	
					kitu_thanh = char(207);			//thanh co gai

				for (int j = 0; j < DO_DAI_THANH; j++)
					a[thanh[i].hang][thanh[i].cot + j] = kitu_thanh;
			}
		}
	}
	else
	{
		ball.exit_game = true;
	}
}
//-----------------------------------------------------------------------
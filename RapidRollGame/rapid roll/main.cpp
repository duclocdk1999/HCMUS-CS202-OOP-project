#include "logic.h"
#include "screen.h"
#include "settings.h"

char a[100][100];
int score;

QuaBong ball;
ThanhNgang thanh[SO_THANH_NGANG];

//---------------------------------
void capNhatBanPhim()
{
	while (ball.exit_game == false)
	{
		capNhatViTriTuBanPhim(ball, thanh, a);
	}
}
//---------------------------------
void capNhatHeThong()
{
	while (ball.exit_game == false)
	{
		capNhatViTri(ball, thanh, a, score);
		score++;
	}
}
//---------------------------------
void capNhatManHinh()
{
	while (ball.exit_game == false)
	{
		gotoxy(0, 0);				
		display(a);

		gotoxy(SO_HANG / 2 + 1, SO_COT + 9);
		printf("%d", score);
	}
}
//---------------------------------
int main()
{
	//de khoi tao bo dem ngau nhien
	time_t t;
	srand((unsigned)time(&t));

	//khoi tao game
	initGame(ball, thanh, a);
	ghiMenu();

	//chay 3 luong
	std::thread first(capNhatBanPhim);
	std::thread second(capNhatHeThong);
	std::thread third(capNhatManHinh);

	first.join();
	second.join();
	third.join();

	//chao tam biet nguoi choi
	Sleep(1000);
	goodbye(score);

	Sleep(1000);
	_getch();

	return 0;
}
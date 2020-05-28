#include "keyboard.h"

char nhapTuBanPhim()	//nhap tu man hinh
{
	char kitu;
	if (_kbhit())
	{
		kitu = _getch();
		return kitu;
	}
	return '\0';
}
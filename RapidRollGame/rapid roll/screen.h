#ifndef _SCREEN_H_
#define _SCREEN_H_ 

#include "settings.h"

//-------------------------------------------------------------------
void gotoxy(int x, int y);
void display(char a[100][100]);
void ghiMenu();
void goodbye(int score);
//void inQuaBong(int hang, int cot);
//void inThanhNgang(int hang, int cot, int do_dai_thanh, bool cam_bay);
//void inKhungTroChoi();

#endif
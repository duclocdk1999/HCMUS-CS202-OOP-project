#ifndef _LOGIC_H_ 
#define _LOGIC_H_ 

#include "keyboard.h"
#include "settings.h"

struct QuaBong
{
	int hang, cot;
	bool exit_game = false;
};

struct ThanhNgang
{
	int hang, cot;
	bool cam_bay;
};

//khoi tao toa do cho qua bong, cac thanh ngang va mang a
void initGame(QuaBong &ball, ThanhNgang Ngang[], char a[100][100]);

//cap nhat toa do tu ban phim
void capNhatViTriTuBanPhim(QuaBong &ball, ThanhNgang thanh[], char a[100][100]);

//cap nhat toa do tu dong
void capNhatViTri(QuaBong &ball, ThanhNgang thanh[], char a[100][100], int score);

#endif
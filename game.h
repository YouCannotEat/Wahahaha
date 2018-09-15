#define _CRT_SECURE_NO_WARNINGS 1
#ifndef __GAME_H__
#define __GAME_H__
#define Row 3 //ÐÐ
#define Col 3 //ÁÐ
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>
void menu();
void game();
void PlayerGo(char show[Row][Col], int row, int col);
void Display(char arr[Row][Col], int row, int col);
void Init(char arr[Row][Col], int row, int col, char f);
char IsWin(char show[Row][Col], int row, int col);
void ComputerGo(char show[Row][Col], int row, int col);
#endif // __GAME_H__

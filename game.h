#define _CRT_SECURE_NO_WARNINGS 1
#ifndef __GAME_H__
#define __GAME_H__
#define Row 4 //ÐÐ
#define Col 4 //ÁÐ
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>

void menu();
int game();
void PlayerGo(int arr[Row][Col], int row, int col);
void Display(int arr[Row][Col], int row, int col);
void Init(int arr[Row][Col], int row, int col, char f);
char IsWin(int arr[Row][Col], int row, int col);
void ComputerGo(int arr[Row][Col], int row, int col);
#endif // __GAME_H__



#include"game.h"
void menu()//菜单
{
	system("color F9");
	printf("\n\n\n\t\t欢迎来到三子棋");
	Sleep(2000);
	system("cls");
	printf("\n\n\t****************************\n");
	printf("\t****   1.开始游戏      *****\n");
	printf("\t****   0.退出          *****\n");
}
int Sum_Meb(char arr[Row][Col], int row, int col, char f)
{
	int count = 0;
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			if (arr[i][j] == f)
				count++;
	return count;
}

//返回玩家是否赢了
int Ret_Play(char arr[Row][Col], int row, int col, int f)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2] && arr[i][0] == f)
		{
			return 1;
		}
		else if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[2][i] == f)
		{
			return 1;
		}
	}
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[1][1] == f)return 1;
	if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[1][1] == f)return 1;
	return 0;
}
void Init(char arr[Row][Col], int rows, int cols, char f)//数组初始化
{
	memset(arr, f, rows*cols);
}
void Display(char arr[Row][Col], int row, int col)//显示
{
	int i = 0;
	int j = 0;
	printf("\t\t\t");
	for (i = 0; i < row; i++)
	{
		printf(" ___");
	}
	for (i = 0; i < row; i++)
	{
		printf("\n\t\t\t|");
		for (j = 0; j < col; j++)
		{
			printf("_%c_|", arr[i][j]);
		}
	}
}
//玩家在合适位置落子
void PlayerGo(char show[Row][Col], int row, int col)
{
	int r = 0;
	int c = 0;
	while (1)
	{
		printf("\n\n\t\t请玩家走(如 1 1)：>");
		scanf("%d %d", &r, &c);
		if (show[r - 1][c - 1] == ' ')
		{
			show[r - 1][c - 1] = 'X';
			Display(show, row, col);
			break;
		}
		else printf("输入错误\n");
	}
}
//判断输赢
char IsWin(char show[Row][Col], int row, int col)
{
	if (Sum_Meb(show, row, col, ' ') == 0)
		return 'D';
	else if (Ret_Play(show, row, col, 'X') == 1)
		return 'Y';
	else if (Ret_Play(show, row, col, 'O') == 1)
		return 'N';
	return 0;
}
//电脑在合适位置随机生成随机值，
void ComputerGo(char show[Row][Col], int row, int col)
{
	int r = 0;
	int c = 0;
	printf("\n\n\t\t请电脑走：>\n");
	while (1)
	{
		r = rand() % row + 1;
		c = rand() % col + 1;
		if (show[r][c] == ' ')
		{
			show[r][c] = 'O';
			Display(show, row, col);
			break;
		}
	}
}

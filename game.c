#include"game.h"
void menu()//�˵�
{
	system("color F9");
	printf("\n\n\n\n\t\t��ӭ����2048");
	Sleep(2000);
	system("cls");
	printf("\n\n\t****************************\n");
	printf("\t****   1.��ʼ��Ϸ      *****\n");
	printf("\t****   0.�˳�          *****\n");
}
void Init(int arr[Row][Col], int rows, int cols, char f)//�����ʼ��
{
	memset(arr, f, rows*cols*16);
}
void Display(int arr[Row][Col], int row, int col)//��ʾ
{
	int i = 0;
	int j = 0;
	printf("\t\t\t");
	for (i = 0; i < row; i++)
	{
		printf(" ______");
	}
	for (i = 0; i < row; i++)
	{
		printf("\n\t\t\t|");
		for (j = 0; j < col; j++)
		{
			if (arr[i][j] == 0)
				printf("_    _|");
			else
				printf("_%4d_|", arr[i][j]);
		}
	}
}
void NumMoveup(int arr[Row][Col], int row, int col,int ud)
{
	int i = 0;
	int j = 0;
	for (i = row-1; i >0; i--)
	{
		for (j = 0; j < col; j++)
		{
			if (arr[i - ud][j] == 0)
			{
				arr[i - ud][j] = arr[i][j];
				arr[i][j] = 0;
			}
			else if (arr[i - ud][j] == arr[i][j])
			{
				arr[i - ud][j] = 2 * arr[i][j];
				arr[i][j] = 0;
			}
		}
	}
}
void NumMovedown(int arr[Row][Col], int row, int col, int ud)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row-1; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (arr[i +ud][j] == 0)
			{
				arr[i +ud][j] = arr[i][j];
				arr[i][j] = 0;
			}
			else if (arr[i + ud][j] == arr[i][j])
			{
				arr[i + ud][j] = 2 * arr[i][j];
				arr[i][j] = 0;
			}
		}
	}
}
void NumMoveleft(int arr[Row][Col], int row, int col, int lr)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = col-1; j >0; j--)
		{
			if (arr[i][j-lr] == 0)
			{
				arr[i][j-lr] = arr[i][j];
				arr[i][j] = 0;
			}
			else if (arr[i][j-lr] == arr[i][j])
			{
				arr[i][j-lr] = 2 * arr[i][j];
				arr[i][j] = 0;
			}
		}
	}
}
void NumMoveright(int arr[Row][Col], int row, int col, int lr)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col-1; j++)
		{
			if (arr[i][j + lr] == 0)
			{
				arr[i][j + lr] = arr[i][j];
				arr[i][j] = 0;
			}
			else if (arr[i][j + lr] == arr[i][j])
			{
				arr[i][j + lr] = 2 * arr[i][j];
				arr[i][j] = 0;
			}
		}
	}
}
void  PlayerGo(int arr[Row][Col], int row, int col)
{
	int  n = 0;
	char a=0;
	while (1)
	{
		if(getchar()=='\n')
			printf("\n\n\t\t������������������Դ˶�Ӧ��WSAD����>");
		scanf("%c", &a);
		if (a == 'A' || a == 'a')n = 3;
		else if (a == 'S' || a == 's')n = 2;
		else if (a == 'd' || a == 'D')n = 4;
		else if (a == 'w' || a == 'W')n = 1;
		switch (n)
		{
		case 1: NumMoveup(arr,row,col,1); break;
		case 2:NumMovedown(arr,row,col,1); break;
		case 3:NumMoveleft(arr, row, col, 1); break;
		case 4:NumMoveright(arr, row, col, 1); break;
		default:printf("�����������������\n"); n = 0; break;
		}
		if(n!=0)break;
	}
}
char IsWin(int arr[Row][Col], int row, int col)
{
	int i = 0; int j = 0;
	int count=0;
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
		{
			if (arr[i][j] == 2048)
				return 'Y';
			else if (arr[i][j] == 0)
				count++;
		}
	if (count == 0) return 'N';
	return '0';
}
void ComputerGo(int arr[Row][Col], int row, int col)
{
	int r = 0;
	int c = 0;
	//printf("\n\n\t\t������ߣ�>\n");
	while (1)
	{
		r = rand() % row;
		c = rand() % col;
		if (arr[r][c] == 0)
		{
			arr[r][c] = 2; 
			Display(arr, row, col);
			break;
		}
	}
}
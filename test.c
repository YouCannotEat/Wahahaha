#include"game.h"
void game() //游戏
{
	char show[Row][Col];
	Init(show, Row, Col, ' ');
	Display(show, Row, Col);
	while (1)
	{
		char fin = 0;
		PlayerGo(show, Row, Col);
		fin = IsWin(show, Row, Col);
		if (fin != 0)break;
		ComputerGo(show, Row, Col);
		fin = IsWin(show, Row, Col);
		if (fin != 0)break;
	}
	if (IsWin(show, Row, Col) == 'Y')
	{
		system("cls");
		system("color F2");
		Display(show, Row, Col);
		printf("\n\n\n\t\t恭喜您，您赢了哦*★,°*:.☆(￣▽￣)/$:*.°★* 。\n");
	}
	else if (IsWin(show, Row, Col) == 'N')
		printf("\n\n\n\t\t很遗憾您输了。\n");
	else printf("\n\n\n\t\t平局！\n");
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do {
		menu();
		printf("请输入您的选择：>");
		scanf("%d", &input);
		if (input == 1)
		{
			game(); break;
		}
		else if (input == 0) printf("\t退出游戏\n");
	} while (input != 0);
	Sleep(3000);
	system("pause");
	return 0;
}
#include"game.h"
void game() //��Ϸ
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
		printf("\n\n\n\t\t��ϲ������Ӯ��Ŷ*��,��*:.��(������)/$:*.���* ��\n");
	}
	else if (IsWin(show, Row, Col) == 'N')
		printf("\n\n\n\t\t���ź������ˡ�\n");
	else printf("\n\n\n\t\tƽ�֣�\n");
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do {
		menu();
		printf("����������ѡ��>");
		scanf("%d", &input);
		if (input == 1)
		{
			game(); break;
		}
		else if (input == 0) printf("\t�˳���Ϸ\n");
	} while (input != 0);
	Sleep(3000);
	system("pause");
	return 0;
}
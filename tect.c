#include"game.h"
int game() //��Ϸ
{
	int show[Row][Col];
	Init(show, Row, Col,0);
	char fin = '0';
	while (1)
	{
		if(fin='0')
			ComputerGo(show, Row, Col);
		fin = IsWin(show, Row, Col);
		if (fin != '0')break;
		PlayerGo(show, Row, Col);
		fin = IsWin(show, Row, Col);
		if (fin != '0')break;
	}
	if (IsWin(show, Row, Col) != 'N')
	{
		system("cls");
		system("color F2");
		Display(show, Row, Col);
		printf("\n\n\n\t\t��ϲ������Ӯ��Ŷ*��,��*:.��(������)/$:*.���* ��\n");
	}
	else 
	printf("\n\n\n\t\t���ź������ˡ�\n");
	system("pause");
	exit(0);
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
			game(); 
		}
		else 
			if (input == 0) printf("\t�˳���Ϸ\n");
	} while (input != 0);
	return 0;
}
#include"game.h"
int game() //ÓÎÏ·
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
		printf("\n\n\n\t\t¹§Ï²Äú£¬ÄúÓ®ÁËÅ¶*¡ï,¡ã*:.¡î(£ş¨Œ£ş)/$:*.¡ã¡ï* ¡£\n");
	}
	else 
	printf("\n\n\n\t\tºÜÒÅº¶ÄúÊäÁË¡£\n");
	system("pause");
	exit(0);
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do {
		menu();
		printf("ÇëÊäÈëÄúµÄÑ¡Ôñ£º>");
		scanf("%d", &input);
		if (input == 1)
		{
			game(); 
		}
		else 
			if (input == 0) printf("\tÍË³öÓÎÏ·\n");
	} while (input != 0);
	return 0;
}
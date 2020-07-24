// blablabla.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>




using namespace std;

int main()
{
	int money, choice, suma=0, pozyczka=0;
	char ch;
	srand(time(NULL));
	money = rand() % 1000 + 100;
	printf("Stan konta:%i\n\n", money);

	

	do 
	{
		printf("Wybierz produkty:\n\n");
		printf("1. Spodnie - 120zl\n");
		printf("2. Kurtka - 250zl\n");
		printf("3. Bluza - 150zl\n");
		printf("4. Koszula - 100zl\n");
		printf("5. T-Shirt - 40zl\n");
		printf("6. Pożyczka 10%%\n");
		printf("0. Zakoncz\n");
		scanf_s("%i", &choice);
		ch = getchar();

		switch (choice)
		{
		case 1:
			if (money - 120 >= 0)
			{
				money -= 120;
				suma += 120;
			}
			else
			{
				printf("Nie masz wystarczajaco pieniedzy.\n");
			}
		break;

		case 2:
			if (money - 250 >= 0)
			{
				money -= 250;
				suma += 250;
			}
			else
			{
				printf("Nie masz wystarczajaco pieniedzy.\n");
			}
		break;

		case 3:
			if (money - 150 >= 0)
			{
				money -= 150;
				suma += 150;
			}
			else
			{
				printf("Nie masz wystarczajaco pieniedzy.\n");
			}
		break;

		case 4:
			if (money - 100 >= 0)
			{
				money -= 100;
				suma += 100;
			}
			else
			{
				printf("Nie masz wystarczajaco pieniedzy.\n");
			}
		break;

		case 5:
			if (money - 50 >= 0)
			{
				money -= 50;
				suma += 50;
			}
			else
			{
				printf("Nie masz wystarczajaco pieniedzy.\n");
			}
		break;

		case 6:
			printf("Ile pieniędzy chcesz pozyczyc? ");
			int tmp;
			scanf_s("%i", &tmp);
			ch = getchar();

			pozyczka += tmp * 1.10;
			money += tmp;
			printf("Pozyczasz %d zl, bedziesz musial zwrocic %d zl\n", tmp, (int)(tmp * 1.10));
		break;

		case 0:
			printf("Do widzenia!\n");
		break;

		default:
			printf("Bledny wybor\n");
		break;
		}

		printf("\nStan konta:%i\n", money);
		printf("Suma:%i\n", suma);
		while (getchar() != '\n');
		system("cls");
	} while (choice != 0);

	printf("Koszt wszystkich zakupow: %i\n", suma);
	printf("Stan konta: %i\n", money);
	printf("Koszt pozyczki: %i\n", pozyczka);


	return 0;
}


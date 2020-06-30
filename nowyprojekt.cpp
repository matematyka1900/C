// nowyprojekt.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>

int main()
{
	int card, cpucard, score = 0, cpuscore = 0, choice=1;
	char ch;

	do 
	{
		printf("Wybierz karte\n");
		printf("1. Dziewiatka\n");
		printf("2. Dziesiatka\n");
		printf("3. Walet\n");
		printf("4. Dama\n");
		printf("5. Krol\n");
		printf("6. As\n\n");
		scanf_s("%i", &card);
		ch = getchar();
		if (card < 1 || card>6)
		{
			printf("Bledny wybor");
			while (getchar() != '\n');
			system("cls");

		}
	} while (card < 1 || card > 6);

	srand(time(NULL));

	do 
	{
		if (choice == 1)
		{
			cpucard = rand() % 6 + 1;

			switch (card)
			{
			case 1:
				printf("Gracz:\n");
				printf("9 0pkt\n");
				printf("Wynik:%d", score);
				break;
			case 2:
				printf("Gracz:\n");
				printf("10 10pkt\n");
				score += 10;
				printf("Wynik:%d", score);
				break;
			case 3:
				printf("Gracz:\n");
				printf("J 2pkt\n");
				score += 2;
				printf("Wynik:%d", score);
				break;
			case 4:
				printf("Gracz:\n");
				printf("Q 3pkt\n");
				score += 3;
				printf("Wynik:%d", score);
				break;
			case 5:
				printf("Gracz:\n");
				printf("K 4pkt\n");
				score += 4;
				printf("Wynik:%d", score);
				break;
			case 6:
				printf("Gracz:\n");
				printf("AS 11pkt\n");
				score += 11;
				printf("Wynik:%d", score);
				break;
			default:
				break;
			}

			printf("\n");

			switch (cpucard)
			{
			case 1:
				printf("Komputer:\n");
				printf("9 0pkt\n");
				printf("Wynik:%d", cpuscore);
				break;
			case 2:
				printf("Komputer:\n");
				printf("10 10pkt\n");
				cpuscore += 10;
				printf("Wynik:%d", cpuscore);
				break;
			case 3:
				printf("Komputer:\n");
				printf("J 2pkt\n");
				cpuscore += 2;
				printf("Wynik:%d", cpuscore);
				break;
			case 4:
				printf("Komputer:\n");
				printf("Q 3pkt\n");
				cpuscore += 3;
				printf("Wynik:%d", cpuscore);
				break;
			case 5:
				printf("Komputer:\n");
				printf("K 4pkt\n");
				cpuscore += 4;
				printf("Wynik:%d", cpuscore);
				break;
			case 6:
				printf("Komputer:\n");
				printf("AS 11pkt\n");
				cpuscore += 11;
				printf("Wynik:%d", cpuscore);
				break;
			default:
				break;
			}



		}else 
		{
			printf("Bledny wybor");
		}

		while (getchar() != '\n');
		system("cls");

		if (score >= 21 || cpuscore >= 21)
		{
			break;
		}

		printf("Wybierz opcje:\n");
		printf("1. Jeszcze\n");
		printf("2. Stop\n");
		scanf_s("%i", &choice);
		ch = getchar();
		
		
		card = rand() % 6 + 1;

	} while (choice != 2);


	printf("gracz: %i, komputer: %i\n", score, cpuscore);

	if (score == 21)
	{
		printf("Wygrywa gracz");
	}
	else if (cpuscore == 21)
	{
		printf("Wygrywa komputer");
	}
	else if (score < cpuscore && cpuscore>21)
	{
		printf("Wygrywa gracz\n");


	}
	else if (cpuscore < score && score>21)
	{
		printf("Wygrywa komputer\n");
	}
	else if (cpuscore > score)
	{
		printf("Wygrywa komputer\n");
	}
	else
	{
		printf("Wygrywa gracz\n");
	}
	ch = getchar();
	return 0;
}



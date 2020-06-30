#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

using namespace std;

// 2.1
void pobierz(unsigned int n, float* tablica);
float iloczyn(unsigned int n, float* tablica);
float parzystych(unsigned int n, float* tablica);
float nieparzystych(unsigned int n, float* tablica);
float dodatnich(unsigned int n, float* tablica);
float ujemnych(unsigned int n, float* tablica);
float wiekszychOdK(unsigned int n, float* tablica);

// 2.2
void generuj(unsigned int n, float** tablica);
void wyswietl(unsigned int n, float** tablica);
void zamien(unsigned int n, float** tablica);



int main()
{
	int wybor = 0;
	unsigned int m, n;
	float* tab;
	float** tab2;
	char ch;

	do
	{
		printf("Wybierz zadanie:\n1.\n2.\n0. Koniec\n");
		scanf_s("%i", &wybor);

		switch (wybor)
		{
		case 1:
			printf("Podaj rozmiar tablicy: ");
			scanf_s("%u", &n);

			tab = (float*)malloc(sizeof(float) * n);

			pobierz(n, tab);
			printf("Iloczyn wszystkich liczb: %f\n", iloczyn(n, tab));
			printf("Iloczyn liczb parzystych: %f\n", parzystych(n, tab));
			printf("Iloczyn liczb nieparzystych: %f\n", nieparzystych(n, tab));
			printf("Iloczyn liczb dodatnich: %f\n", dodatnich(n, tab));
			printf("Iloczyn liczb ujemnych: %f\n", ujemnych(n, tab));
			printf("Iloczyn liczb wiekszych od K: %f\n", wiekszychOdK(n, tab));

			while (ch = getchar() != '\n');

			free(tab);

			break;
		case 2:
			printf("Zostanie utworzona tablica o rozmiarze N x N. Podaj N: ");
			scanf_s("%u", &n);
			while (ch = getchar() != '\n');


			tab2 = (float**)malloc(sizeof(float*) * n);
			for (int i = 0; i < n; i++)
			{
				tab2[i] = (float*)malloc(sizeof(float) * n);
			}

			generuj(n, tab2);
			wyswietl(n, tab2);
			zamien(n, tab2);
			printf("\n");
			wyswietl(n, tab2);
			while (ch = getchar() != '\n');

			for (int i = 0; i < n; i++)
			{
				free(tab2[i]);
			}
			free(tab2);
			


			break;
		default:
			break;
		}
		if (tab2 == NULL)
		{
			printf("Pamiec została zwolniona prawiłowo");
		}
		system("cls");
	} while (wybor != 0);
}


// 2.1
void pobierz(unsigned int n, float* tablica)
{
	char ch;

	printf("Podaj %u liczb: \n", n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%f", &tablica[i]);
	}
	while (ch = getchar() != '\n');
}

float iloczyn(unsigned int n, float* tablica)
{
	float suma = 1;
	for (int i = 0; i < n; i++)
	{
		suma *= tablica[i];
	}
	return suma;

}

float parzystych(unsigned int n, float* tablica)
{
	float suma = 1;
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
			suma *= tablica[i];
	}

	return suma;
}

float nieparzystych(unsigned int n, float* tablica)
{
	float suma = 1;
	for (int i = 0; i < n; i++)
	{
		if (i % 2 != 0)
			suma *= tablica[i];
	}

	return suma;
}

float dodatnich(unsigned int n, float* tablica)
{
	float suma = 1;
	for (int i = 0; i < n; i++)
	{
		if (tablica[i] > 0)
			suma *= tablica[i];
	}

	return suma;
}

float ujemnych(unsigned int n, float* tablica)
{
	float suma = 1;
	for (int i = 0; i < n; i++)
	{
		if (tablica[i] < 0)
			suma *= tablica[i];
	}

	return suma;
}

float wiekszychOdK(unsigned int n, float* tablica)
{
	char ch;
	float suma = 1, k = 0;
	cout << "Wprowadz kkkk " << endl;
	scanf_s("%f", &k);
	while (ch = getchar() != '\n');

	for (int i = 0; i < n; i++)
	{
		if (tablica[i] > k)
			suma *= tablica[i];
	}

	return suma;
}

// 2.2
void generuj(unsigned int n, float** tablica)
{
	float p, q;
	char ch;

	srand(time(NULL));
	printf("Wprowadz zakres generowanych liczb: \nOd:");
	scanf_s("%f", &p);
	printf("Do:");
	scanf_s("%f", &q);
	while (ch = getchar() != '\n');

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			tablica[i][j] = p + ((float)rand() / RAND_MAX) * (q - p);
		}
	}
}

void wyswietl(unsigned int n, float** tablica)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%f ", tablica[i][j]);
		}
		printf("\n");
	}
}

void zamien(unsigned int n, float** tablica)
{
	char ch;

	for (int i = 0; i < n; i++)
	{
		float tmp = tablica[i][i];
		tablica[i][i] = tablica[i][n - 1 - i];
		tablica[i][n - 1 - i] = tmp;
	}
}

#include <iostream>
#include <stdlib.h>
#include <time.h>

// 1.1
void pobierz(unsigned int n, float* tablica);
float suma(unsigned int n, float* tablica);
float dodatnich(unsigned int n, float* tablica);
float ujemnych(unsigned int n, float* tablica);
float wiekszychOdK(unsigned int n, float* tablica);
float parzystych(unsigned int n, float* tablica);
float nieparzystych(unsigned int n, float* tablica);

// 1.2
void generuj(unsigned int m, unsigned int n, float** tablica);
void wyswietl(unsigned int m, unsigned int n, float** tablica);
void zamien(unsigned int m, unsigned int n, float** tablica);



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
			printf("Suma wszystkich liczb: %f\n", suma(n, tab));
			printf("Suma liczb dodatnich: %f\n", dodatnich(n, tab));
			printf("Suma liczb ujemnych: %f\n", ujemnych(n, tab));
			printf("Suma liczb wiekszych od K: %f\n", wiekszychOdK(n, tab));
			printf("Suma liczb o indeksach parzystych: %f\n", parzystych(n, tab));
			printf("Suma liczb o indeksach nieparzystych: %f\n", nieparzystych(n, tab));
			while (ch = getchar() != '\n');

			free(tab);

			break;
		case 2:
			printf("Podaj liczbe wierszy: ");
			scanf_s("%u", &m);
			printf("Podaj liczbe kolumn: ");
			scanf_s("%u", &n);

			tab2 = (float**)malloc(sizeof(float*) * m);
			for (int i = 0; i < m; i++)
			{
				tab2[i] = (float*)malloc(sizeof(float) * n);
			}

			generuj(m, n, tab2);
			wyswietl(m, n, tab2);
			zamien(m, n, tab2);
			wyswietl(m, n, tab2);
			while (ch = getchar() != '\n');

			for (int i = 0; i < m; i++)
			{
				free(tab2[i]);
			}
			free(tab2);

			break;
		default:
			break;
		}

		system("cls");
	} while (wybor != 0);
}


// 1.1
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

float suma(unsigned int n, float* tablica)
{
	float suma=0;
	for (int i = 0; i < n; i++)
	{
		suma += tablica[i];
	}
	return suma;

}

float dodatnich(unsigned int n, float* tablica)
{
	float suma = 0;
	for (int i = 0; i < n; i++)
	{
		if (tablica[i]>0)
			suma += tablica[i];
	}

	return suma;
}

float ujemnych(unsigned int n, float* tablica)
{
	float suma = 0;
	for (int i = 0; i < n; i++)
	{
		if (tablica[i] < 0)
			suma += tablica[i];
	}

	return suma;
}

float wiekszychOdK(unsigned int n, float* tablica)
{
	char ch;
	float suma = 0, k = 0;
	printf("Wprowadz k:");
	scanf_s("%f", &k);
	while (ch = getchar() != '\n');

	for (int i = 0; i < n; i++)
	{
		if (tablica[i] > k)
			suma += tablica[i];
	}

	return suma;
}

float parzystych(unsigned int n, float* tablica)
{
	float suma = 0;
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
			suma += tablica[i];
	}

	return suma;
}

float nieparzystych(unsigned int n, float* tablica)
{
	float suma = 0;
	for (int i = 0; i < n; i++)
	{
		if (i % 2 != 0)
			suma += tablica[i];
	}

	return suma;
}

// 1.2
void generuj(unsigned int m, unsigned int n, float** tablica)
{
	float p, q;

	srand(time(NULL));
	printf("Wprowadz zakres generowanych liczb: \nOd:");
	scanf_s("%f", &p);
	printf("Do:");
	scanf_s("%f", &q);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			tablica[i][j] = p + ((float)rand() / RAND_MAX) * (q - p);
		}
	}
}

void wyswietl(unsigned int m, unsigned int n, float** tablica)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%f ", tablica[i][j]);
		}
		printf("\n");
	}
}

void zamien(unsigned int m, unsigned int n, float** tablica)
{
	char ch;
	unsigned int k1, k2;

	printf("Podaj pierwszy wiersz: ");
	scanf_s("%u", &k1);
	printf("Podaj drugi wiersz: ");
	scanf_s("%u", &k2);
	while (ch = getchar() != '\n');

	if (k1 < m && k2 < m)
	{
		for (int i = 0; i < n; i++)
		{
			float tmp = tablica[k1][i];
			tablica[k1][i] = tablica[k2][i];
			tablica[k2][i] = tmp;
		}
	}
}
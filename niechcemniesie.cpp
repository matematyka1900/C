#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//using namespace std;


#define dlugosc 25

struct samochod
{
	char marka[dlugosc];
	char model[dlugosc];
	char kolor[dlugosc];
};

void stworz_parking(struct samochod*** kawa, unsigned int n)
{
	*kawa = (struct samochod**)malloc(sizeof(struct samochod*) * n);

	for (int i = 0; i < n; i++)
	{
		(*kawa)[i] = NULL;
	}
}

void zwolnij_parking(struct samochod*** kawa, unsigned int n)
{
	for (int i = 0; i < n; i++)
	{
		if ((*kawa)[i] != NULL)
			free((*kawa)[i]);
	}

	free(*kawa);
}

void wyswietl(struct samochod** kawa, unsigned int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d. ", i);

		if (kawa[i] == NULL)
		{
			printf("Wolne\n");
		}
		else
		{
			printf("%s %s %s\n", kawa[i]->kolor, kawa[i]->marka, kawa[i]->model);
		}
	}
}

void zaparkuj(struct samochod** kawa, unsigned int n)
{
	int numer;
	printf("Podaj nr miejsca: ");
	scanf_s("%d", &numer);

	if (numer + 1 > n || n < 0)
	{
		printf("Miejsce nie istnieje\n");
		return;
	}

	if (kawa[numer] == NULL)
	{
		kawa[numer] = (struct samochod*)malloc(sizeof(struct samochod));

		char marka[dlugosc] = "";
		char model[dlugosc] = "";
		char kolor[dlugosc] = "";

		printf("Podaj marke: ");
		scanf_s(" %s", kawa[numer]->marka, dlugosc);

		printf("Podaj model: ");
		scanf_s(" %s", kawa[numer]->model, dlugosc);

		printf("Podaj kolor: ");
		scanf_s(" %s", kawa[numer]->kolor, dlugosc);
	}
	else
	{
		printf("Miejsce zajete!\n");
	}
}

void wyjedz(struct samochod** kawa, unsigned int n)
{
	int numer;
	printf("Podaj nr miejsca: ");
	scanf_s("%d", &numer);

	if (numer + 1 > n || n < 0)
	{
		printf("Miejsce nie istnieje\n");
		return;
	}

	if (kawa[numer] == NULL)
	{
		printf("Miejsce jest wolne!\n");
	}
	else
	{
		printf("Wyjezdzasz samochodem: %s %s %s\n", kawa[numer]->kolor,
			kawa[numer]->marka, kawa[numer]->model);

		free(kawa[numer]);
		kawa[numer] = NULL;
	}
}

int main()
{
	printf("podaj ile miejsc: ");
	int d;
	scanf_s("%i", &d);

	struct samochod** miejsca;

	stworz_parking(&miejsca, d);
	wyswietl(miejsca, d);

	zaparkuj(miejsca, d);
	wyswietl(miejsca, d);
	wyjedz(miejsca, d);
	wyswietl(miejsca, d);

	for (int i = 0; i < d; i++)
	{
		if (miejsca[i] != NULL)
		{
			free(miejsca[i]);
		}
	}

	free(miejsca);
	miejsca = NULL;

	return 0;
}

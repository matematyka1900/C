#include <stdio.h>
#include <stdlib.h>
void stworz(int*** tablica, int liczba);
void wyswietl(int** tablica, int liczba);
void podmien(int** podmiana, int liczba);
void zwolnij(int*** tablica, int liczba);
int main()
{
	int x = 17;
	int** tablica = NULL;
	stworz(&tablica,17);
	wyswietl(tablica, 17);
	podmien(tablica, 17);
	wyswietl(tablica, 17);
	zwolnij(&tablica, 17);

}
void stworz(int*** tablica, int liczba)
{
	*tablica= (int**)malloc(sizeof(int*) * liczba);
	for (int i = 0; i < liczba; i++)
	{
		(*tablica)[i] = (int*)malloc(sizeof(int));
		*((*tablica)[i]) = 4;
	}

}
void wyswietl(int** tablica, int liczba)
{
	for (int i = 0; i < liczba; i++)
	{
		printf("%d", *(tablica[i]));

	}

}

void podmien(int** podmiana, int liczba)
{
	for (int i = 0; i < liczba; i++)
	{
		*(podmiana[i]) = 8;
	}
	

}
void zwolnij(int*** tablica, int liczba)
{
	
	for (int i = 0; i < liczba; i++)
	{
		free((*tablica)[i]);
		((*tablica)[i]) = NULL;
	}
	free(*tablica);
	(*tablica) = NULL;
}
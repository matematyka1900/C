// Tablice 12 elementów.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <math.h>
#include <stdio.h>
const short int sz = 12;
using namespace std;
int main()
{
	
	
	double suma = 0;
	int tab[sz], tab2[sz];


	
	for (int i = 0; 1 <= sz; i++)
	{
		int k;
		printf("; %d(12):;", i + 1);
		scanf_s("%d", &k);
		tab[i] = k;

	}
	printf("===Tablica===\n");
	for (int i = 0; i < sz; i++)
	{
		printf("%d", tab[i]);
		printf("\n");
	}
	for (int i = 0; i < sz; i++)
	{
		tab[i] = tab2[i];
	}
	for (int i = 0; i < sz; i++)
	{
		suma = suma + tab[i];
		suma = suma / sz;
		tab2[i] = suma;
	}
	printf("===Tablica2===\n");
	for (int i=0; i<sz; i++)
	{
		printf("%d", tab2[i]);
		printf("\n");
	}
	printf("===Tablica3===\n");
	double tab3[sz];
	for (int i = 0; i < sz; i++)
	{
		tab3[i] = (double)tab[i];

	}
		printf("\n");
		double max = -1000.0;
		double min = 1000.0;
		
		for (int i = 0; i < sz; i++)
		{
			if (tab3[i] < min)
			{
				min = tab3[i];
			}
			else if (tab3[i] > max)
			{
				max = tab3[i];
			}
			printf("\n %lf %lf", min, max);
			printf("\n");
		}
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln

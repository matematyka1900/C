#include<iostream>
#include<cstdlib>
#include<ctime>
#include<algorithm>

using namespace std;

int main()
{
	int l = 0, sumaW = 0, sumaD = 0, sumaU = 0, sumaK = 0, sumaP = 0, sumaNP = 0, k = 0;
	int tab[10] = {};
	for (int i = 0; i < 10; i++)
	{
		printf("Podaj %d liczbe: ", i + 1);
		scanf_s("%d", &l);
		sumaW += l;
		tab[i] = l;
	}
	printf("Podaj K:");
	scanf_s("%i", &k);
	for (int i = 0; i < 10; i++)
	{
		if (tab[i] > 0)
		{
			sumaD += tab[i];
		}
		if (tab[i] < 0)
		{
			sumaU += tab[i];
		}
		if (i % 2 == 0)
		{
			sumaP += tab[i];
		}
		if (i % 2 != 0)
		{
			sumaNP += tab[i];
		}
		if (tab[i] > k)
		{
			sumaK += tab[i];
		}
	}
	printf("Suma wszystkich liczb wynosi %d\n", sumaW);
	printf("Suma dodatnich liczb wynosi %d\n", sumaD);
	printf("Suma ujemnych liczb wynosi %d\n", sumaU);
	printf("Suma wiekszych od k liczb wynosi %d\n", sumaK);
	printf("Suma liczb na indeksach parzystych wynosi %d\n", sumaP);
	printf("Suma liczb na indeksach nieparzystych wynosi %d\n", sumaNP);

	printf("\n\n\n");

	srand(time(NULL));
	int m, n;
	int k1 = 0, k2 = 0;
	printf("Podaj M: ");
	scanf_s("%d", &m);
	printf("Podaj N: ");
	scanf_s("%d", &n);
	int** tab1 = new int* [m];
	for (int i = 0; i < m; ++i)
	{
		tab1[i] = new int[n];
	}

	printf("Podaj k1: ");
	scanf_s("%d", &k1);
	printf("Podaj k2: ");
	scanf_s("%d", &k2);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			tab1[i][j] = rand();
			printf("%2d ", tab1[i][j]);
			if (j + 1 == n)
				printf("\n");
		}
	}
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		swap(tab1[k1][i], tab1[k2][i]);
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%2d ", tab1[i][j]);
			if (j + 1 == n)
				printf("\n");
		}
	}
	return 0;
	
}
#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<algorithm>

void zadanie1();
int** zadanie1_1(int m, int n, int k1, int k2, int* tab[]);
void zadanie2();
int** zadanie2_2(int n);
void zadanie3();
int** zadanie3_1(int n);

using namespace std;

int main()
{
	srand(time(NULL));
	int y = 0, l = 0;
	printf("Menu:\n1. Zadanie 1.\n2. Zadanie 1.2.\n3. Zadanie 2.\n4. Zadanie 2.2.\n5. Zadanie 3.\n6. Zadanie 3.2.\n");
	do
	{
		printf("Podaj opcje: ");
		scanf_s("%d", &y);
		switch (y)
		{
		case 1:
		{
			zadanie1();
			break;
		}
		case 2:
		{
			int m, n;
			int k1 = 0, k2 = 0;
			printf("Podaj M: ");
			scanf_s("%d", &m);
			printf("Podaj N: ");
			scanf_s("%d", &n);
			int** tab = new int* [m];
			for (int i = 0; i < m; ++i)
			{
				tab[i] = new int[n];
			}
			printf("Podaj k1: ");
			scanf_s("%d", &k1);
			printf("Podaj k2: ");
			scanf_s("%d", &k2);

			zadanie1_1(m, n, k1, k2, tab);
			printf("\n");
			break;
		}
		case 3:
		{
			zadanie2();
			break;
		}
		case 4:
		{
			int n = 0;
			printf("Podaj N: ");
			scanf_s("%d", &n);

			zadanie2_2(n);
			break;
		}
		case 5:
		{
			zadanie3();
			break;
		}
		case 6:
		{
			int n = 0;
			printf("Podaj N: ");
			scanf_s("%d", &n);

			zadanie3_1(n);

			break;
		}
		}

	} while (y > 0 and y < 7);



	return 0;
}

void zadanie1()
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
	cout << "Podaj k: ";
	cin >> k;
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
	printf("Suma dodatkich liczb wynosi %d\n", sumaD);
	printf("Suma ujemnych liczb wynosi %d\n", sumaU);
	printf("Suma wiekszych od k liczb wynosi %d\n", sumaK);
	printf("Suma liczb na indeksach parzystych wynosi %d\n", sumaP);
	printf("Suma liczb na indeksach nieparzystych wynosi %d\n", sumaNP);
}
int** zadanie1_1(int m, int n, int k1, int k2, int* tab[])
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			tab[i][j] = rand();
			printf("%2d ", tab[i][j]);
			if (j + 1 == n)
				printf("\n");
		}
	}
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		swap(tab[k1][i], tab[k2][i]);
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%2d ", tab[i][j]);
			if (j + 1 == n)
				printf("\n");
		}
	}
	return tab;
}

void zadanie2()
{
	int l = 0, iloczynW = 1, iloczynD = 1, iloczynU = 1, iloczynK = 1, iloczynP = 1, iloczynNP = 1, k = 0;				int uj = 0, dod = 0, lk = 0, p = 0, np = 0;
	int tab[10] = {};
	for (int i = 0; i < 10; i++)
	{
		printf("Podaj %d liczbe: ", i + 1);
		scanf_s("%d", &l);
		iloczynW *= l;
		tab[i] = l;
	}
	printf("Podaj k: ");
	scanf_s("%d", &k);
	for (int i = 0; i < 10; i++)
	{
		if (tab[i] > 0)
		{
			iloczynD *= tab[i];
			dod++;
		}
		if (tab[i] < 0)
		{
			iloczynU *= tab[i];
			uj++;
		}
		if (tab[i] % 2 == 0)
		{
			iloczynP *= tab[i];
			p++;
		}
		if (tab[i] % 2 != 0)
		{
			iloczynNP *= tab[i];
			np++;
		}
		if (tab[i] > k)
		{
			iloczynK *= tab[i];
			lk++;
		}
		if (i + 1 == 10 and uj == 0)
		{
			iloczynU = 0;
		}
		if (i + 1 == 10 and dod == 0)
		{
			iloczynD = 0;
		}
		if (i + 1 == 10 and lk == 0)
		{
			iloczynK = 0;
		}
		if (i + 1 == 10 and p == 0)
		{
			iloczynP = 0;
		}
		if (i + 1 == 10 and np == 0)
		{
			iloczynNP = 0;
		}

	}
	printf("Iloczyn wszystkich liczb wynosi: %d\n", iloczynW);
	printf("Iloczyn liczb dodatnich wynosi: %d\n", iloczynD);
	printf("Iloczyn liczb ujemnych wynosi: %d\n", iloczynU);
	printf("Iloczyn liczb wiekszych od k wynosi: %d\n", iloczynK);
	printf("Iloczyn liczb parzystych wynosi: %d\n", iloczynP);
	printf("Iloczyn liczb nieparzystych wynosi: %d\n", iloczynNP);
}
int** zadanie2_2(int n)
{
	int** tab = new int* [n];
	for (int i = 0; i < n; ++i)
	{
		tab[i] = new int[n];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			tab[i][j] = rand();
			printf("%2d ", tab[i][j]);
			if (j + 1 == n)
			{
				printf("\n");
			}
		}
	}
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		swap(tab[i][n - 1 - i], tab[i][i]);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%2d ", tab[i][j]);
			if (j + 1 == n)
			{
				printf("\n");
			}
		}
	}
	return tab;
}
void zadanie3()
{
	int tab[10] = {};
	int l = 0, sumaP = 0, sumaNP = 0, sumaNU = 0, sumaK = 0;
	int k = 0, ileP = 0, ileNP = 0, ileNU = 0, ileK = 0;
	for (int i = 0; i < 10; i++)
	{
		printf("Podaj %d liczbe: ", i + 1);
		scanf_s("%d", &l);
		tab[i] = l;
	}
	printf("Podaj k: ");
	scanf_s("%d", &k);
	for (int i = 0; i < 10; i++)
	{
		printf("%2d ", tab[i]);
		if (tab[i] % 2 == 0)
		{
			sumaP += tab[i];
			ileP++;
		}
		if (tab[i] % 2 != 0)
		{
			sumaNP += tab[i];
			ileNP++;
		}
		if (tab[i] > 0)
		{
			sumaNU += tab[i];
			ileNU++;
		}
		if (tab[i] > k)
		{
			sumaK += tab[i];
			ileK++;
		}
	}
	printf("\n");
	printf("Srednia arytmetyczna liczb nieujemnych wynosi: %f \n", (float)sumaNU / ileNU);
	printf("Srednia arytmetyczna liczb nieparzystych wynosi: %f \n", (float)sumaNP / ileNP);
	printf("Srednia arytmetyczna liczb parzystych wynosi: %f \n", (float)sumaP / ileP);
	printf("Srednia arytmetyczna liczb wiekszych od k wynosi: %f \n", (float)sumaK / ileK);
}
int** zadanie3_1(int n)
{
	float* srednie;
	srednie = new float[n];
	int suma = 0, suma1 = 0;
	int id = 0;
	int** tab = new int* [n];
	for (int i = 0; i < n; ++i)
	{
		tab[i] = new int[n];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			tab[i][j] = rand();
			printf("%2d ", tab[i][j]);
			if (j + 1 == n)
			{
				printf("\n");
			}
		}
	}
	printf("\n");

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			suma += tab[j][i];
		}
		if (suma > suma1)
		{
			suma1 = suma;
			id = i;
		}
		srednie[i] = (float)suma / n;
		suma = 0;
	}
	for (int i = 0; i < n; i++)
	{
		swap(tab[i][0], tab[i][id]);
	}
	cout << "Srednie: " << endl;
	for (int k = 0; k < n; k++)
	{
		printf("%2f ", srednie[k]);
	}
	printf("\nTablica\n");

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%2d ", tab[i][j]);
			if (j + 1 == n)
			{
				printf("\n");
			}
		}
	}
	return tab;
}
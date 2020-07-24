#include <stdio.h>
#include <string.h>

#define ROZMIAR 81
#define GRAN 20

void strlan(char* lancuchy[], int num);

int main(void)
{
	char dane[GRAN][ROZMIAR];
	char* wsklan[GRAN];
	int licz = 0;
	int k;
	printf("Podaj maksymalnie %d wierszy, a ja je uporzadkuje.\n", GRAN);
	printf("Aby zakonczyc wcisnij enter na poczatku wiersza\n");
	while (licz < GRAN && gets_s(dane[licz]) != NULL && dane[licz][0] != '\0')
	{
		wsklan[licz] = dane[licz];//jaką wartość ma wsklan[licz]?
		licz++;
	}
		strlan(wsklan, licz);
	puts("\nOto uporzadkowana lista:");
	for (k = 0; k < licz; k++)
	{
		puts(wsklan[k]);
	}
	return 0;


}
void strlan(char* lancuchy[], int num)
{
	char* temp;
	int dol, szuk;
	for(dol=0;dol<num-1;dol++)
		for(szuk=dol+1;szuk<num;szuk++)
			if (strcmp(lancuchy[dol], lancuchy[szuk]) > 0)////TEGO NIE ROZUMIEM, ta funkcja porównuje pierwszą litere łańcucha czy cały łańcuch wklepany przez uzytkownika
			{
				temp = lancuchy[dol];
				lancuchy[dol] = lancuchy[szuk];
				lancuchy[szuk] = temp;
			}
}
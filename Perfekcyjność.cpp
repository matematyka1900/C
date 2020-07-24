#include <stdio.h>
#include <stdlib.h> // Include potrzebny do funkcji srand i rand
#include <math.h>   // Niepotrzebny include w tym programie
#include <time.h>   // Include potrzebny do funkcji time

int main()
{
	int choice, minut, za_minute;
	int suma = 0;
	//char ch;

	// Wywołanie komendy cls - wyczyszczenie konsoli
	// (chyba niepotrzebne na początku programu)
	system("cls");
	
	// srand - ustawienie seeda na podstawie czasu
	// do generowania liczb pseudolosowych
	srand(time(NULL));

	// Pętla do-while - nawet jak nie jest spełniony
	// warunek wykona się co najmniej 1 raz
	do {
		printf("MENU\n\n");
		printf("1. Szczecin\n");
		printf("2. Poznan\n");
		printf("3. Gdansk\n");
		printf("4. Krakow\n");
		printf("5. Warszawa\n");
		printf("0. Zakoncz\n");
		printf("Wybierz miasto: ");

		// Wczytanie liczby całkowitej
		// do zmiennej choice
		scanf_s("%i", &choice);
		// Pobranie znaku z konsoli. Po wczytaniu scanf
		// w buforze wejścia zostaje znak nowej linii (enter).
		// Trzeba go stamtąd usunąć. Jak tego nie zrobisz,
		// to gdybyś chciał wczytać później getcharem znak
		// wczytasz '\n' nawet jak użytkownik nic nie naciśnie. 
		// To jest potrzebne żeby oczekiwanie na enter w dalszej
		// części programu działało. Tu wystarczyłby sam
		// 
		// getchar();
		//
		getchar();

		// Rand zwraca pseudolosową liczbę. Żeby mieściła się
		// w odpowiednim zakresie można użyć operatora modulo.
		// Modulo n daje liczby z zakresu od 0 do n-1,
		// więc poniższa linijka generuje liczby 1 - 10.
		minut = rand() % 10 + 1;
		

		// Instrukcja switch - zależnie od wartości choice
		// wywoła się odpowiedni case
		switch (choice) {
		case 1:
			za_minute = 7;
			printf("\nKierunkowy 91 \t stawka za minute: %d(gr) \t czas rosmowy: %dminut \t koszt: %d \n", za_minute, minut, minut * za_minute);
			suma += minut * za_minute;

			// Wczytywanie znaków aż do napotkania znaku nowej
			// linii (oczekiwanie na wciśnięcie entera)
			while (getchar() != '\n');

			// Czyszczenie konsoli
			system("cls");

			// break wychodzi z instrukcji switch.
			// Bez breaka wykonywałyby się dalsze case'y.
			break;
		case 2:
			za_minute = 6;
			printf("\nKierunkowy 61 \t stawka za minute: %d(gr) \t czas rosmowy: %dminut \t koszt: %d \n", za_minute, minut, minut * za_minute);
			suma += minut * za_minute;
			break;
		case 3:
			za_minute = 4;
			printf("\nKierunkowy 58 \t stawka za minute: %d(gr) \t czas rosmowy: %dminut \t koszt: %d \n", za_minute, minut, minut * za_minute);
			suma += minut * za_minute;
			while (getchar() != '\n');
			system("cls");
			break;
		case 4:
			za_minute = 3;
			printf("\nKierunkowy 12 \t stawka za minute: %d(gr) \t czas rosmowy: %dminut \t koszt: %d \n", za_minute, minut, minut * za_minute);
			suma += minut * za_minute;
			while (getchar() != '\n');
			system("cls");
			break;
		case 5:
			za_minute = 2;
			printf("\nKierunkowy 22 \t stawka za minute: %d(gr) \t czas rosmowy: %dminut \t koszt: %d \n", za_minute, minut, minut * za_minute);
			suma += minut * za_minute;
			while (getchar() != '\n');
			system("cls");
			break;
		case 0:
			printf("\nDziekuje\n");
			break;

			// Default wykona się jeżeli wartość zmiennej choice
			// nie pokrywa się z żadnym z case'ów.
		default:
			printf("Bledny wybor, powtorz!\n");
			break;
		}
	} while (choice != 0);

	if (suma >= 100)
	{
		int zl = suma / 100;
		int gr = suma - zl * 100;
		printf("Masz do zaplacenia: %d(zl) %d(gr)", zl, gr);

	}
	else
	{
		printf("Masz do zpalacenia: %d(gr)", suma);
	}



	return 0;
}

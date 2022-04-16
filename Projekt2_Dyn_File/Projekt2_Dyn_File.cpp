// Projekt2_Dyn_File.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Nagłówki.h"



int main()
{
	
	char n ; 
	
	char trash; //śmieci
	int dlugosc = 0;
	int odczytana_dlugosc;

	char **tablica2 = NULL;

	

	printf("Czy wypisac nieposortowane dane? T/N\t");
	scanf_s("%c", &n);

	
	scanf_s("%c", &trash); // wychwycanie śmieci z bufora

	
	
	//wczytanie wyrazów
	tablica2 = odczyt_z_pliku2(tablica2, &dlugosc);

	odczytana_dlugosc = (int)dlugosc;




	//wypisanie nieposortowanych elementów
	if (n =='T')
	{
		printf("Nieposortowane slowa:\n");
	
		for (int i = 0; i < odczytana_dlugosc; i++)
		{

			printf("%s ", tablica2[i]);
		}
	}
	
	
	// funkcja sortująca
	quick_sort2(tablica2, 0, dlugosc);


	printf("\n\n");



	printf("Czy wypisac posortowane dane? T/N\t");
	scanf_s("%c", &n);

	scanf_s("%c", &trash); // wychwycanie śmieci z bufora

	//wypisanie posortowanych elementów
	if (n=='T')
	{
		printf("Posortowane slowa:\n");

		for (int i = 0; i < odczytana_dlugosc; i++)
		{

			printf("%s ", tablica2[i]);
		}
	}

	printf("\n\n");

	zapis_do_pliku2(tablica2, dlugosc);

	Zwolnij_tablice(dlugosc, tablica2);

	system("pause");
	return 0;
}
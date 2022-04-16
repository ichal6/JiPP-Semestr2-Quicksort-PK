#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include "Nag³ówki.h"


char **odczyt_z_pliku2(char **tab,  int *i )
{
	FILE *fw; //tworzenie strumienia na plik
	fpos_t aktualna = 0 ;
	fpos_t dlugosc = 0;
	int dlugosc_int;
	int aktualna_int;
	static int r = 0;

	*i = 0;

	if (!(fw = fopen("dane", "r")))
	{
		printf("Blad przy otwieraniu pliku.\nZamykanie aplikacji\n");
		system("pause");
		exit(2);
	}

	fseek(fw, 0, SEEK_END);

	fgetpos(fw, &dlugosc);

	fseek(fw, 0, 0);

	

	dlugosc_int = (int)dlugosc;

	

	//alokowanie pamiêci na tablicê
	tab = Alokuj(dlugosc, tab);

	fscanf(fw, "%s", tab[r]);
	

	while (1)
	{
		fscanf(fw, "%s", tab[++r]);
		
		
		fgetpos(fw, &aktualna);
		
		aktualna_int = (int)aktualna;

		
		
		if (dlugosc_int-1 < aktualna_int)
		{
			break;
		}
	}

	//zamykanie pliku
	fclose(fw);

	*i = r;

	return tab;


}

void zapis_do_pliku2(char **tab, int n)
{
	FILE *fw; //tworzenie strumienia na plik wyjociowy


	int i;
	//Otwieranie pliku do zapisu danych
	if (!(fw = fopen("wyjœciowy", "w")))
	{
		printf("Blad przy tworzeniu pliku.\nZamykanie aplikacji\n");
		system("pause");
		exit(2);
	}



	for (i = 0;i < n;i++)
	{
		fprintf(fw, "%s ", tab[i]);
	}


	// zamykanie pliku
	fclose(fw);
}
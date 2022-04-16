#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>


char **Alokuj(fpos_t ilosc_wierszy, char **str)
{
	str = NULL;
	int i = 0;
	//alokujemy pamiêæ dla tablicy wskaŸników:
	str = (char **)malloc(ilosc_wierszy * sizeof(char *));
	if (!str)
	{
		//obs³uga b³êdnej sytuacji
	}
	//alokujemy pamiêæ dla elementów ka¿dego wiersza
	for (i = 0; i < ilosc_wierszy; i++)
	{
		str[i] = (char *)malloc(256 * sizeof(char));
		if (!str[i])
		{
			//obs³uga b³êdnej sytuacji
		}
	}

	return str;
}

char *Alokuj_1D(char *str)
{
	str = NULL;
	
		str = (char *)malloc(256 * sizeof(char));
		if (!str)
		{
			//obs³uga b³êdnej sytuacji
		}
	

	return str;
}

void Zwolnij_tablice(fpos_t ilosc_wierszy, char **str)
{
	int i;
	if (str)
	{
		for (i = 0; i < ilosc_wierszy; i++)
		{
			// sprawdzamy, czy str[i] jeszcze nie zwolnione
			if (str[i])
			{
				free(str[i]); //zwalniamy str[i]
				str[i] = NULL; //zapobiegamy zwolnieniu wielokrotnemu
			}
		}
		free(str); //zwalniamy str – wskaŸnik na tablice wskaŸników
		str = NULL; // zapobiegamy zwolnieniu wielokrotnemu
	}
}
#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>


char **Alokuj(fpos_t ilosc_wierszy, char **str)
{
	str = NULL;
	int i = 0;
	//alokujemy pami�� dla tablicy wska�nik�w:
	str = (char **)malloc(ilosc_wierszy * sizeof(char *));
	if (!str)
	{
		//obs�uga b��dnej sytuacji
	}
	//alokujemy pami�� dla element�w ka�dego wiersza
	for (i = 0; i < ilosc_wierszy; i++)
	{
		str[i] = (char *)malloc(256 * sizeof(char));
		if (!str[i])
		{
			//obs�uga b��dnej sytuacji
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
			//obs�uga b��dnej sytuacji
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
		free(str); //zwalniamy str � wska�nik na tablice wska�nik�w
		str = NULL; // zapobiegamy zwolnieniu wielokrotnemu
	}
}
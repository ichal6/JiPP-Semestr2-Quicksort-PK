#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Nagłówki.h"


void swap_pointers(char **str, int first, int second)
{
	char *temp;

	temp = str[second];
	str[second] = str[first];
	str[first] = temp;

}

void quick_sort2(char **tab, int lewy, int prawy)
{

	int	i = lewy - 1; //lewy wskaŸnik
	int j = prawy + 1; //prawy wskaŸnik
	char pivot[256] = {'0'}; //bufor na pivota
	int t_l = 0;
	int t_p = 0;

	



	strcpy(pivot, tab[(lewy + prawy) / 2]); //obliczamy pivota
	


	// przypadek elementarny - tablica jednoelementowa
	if (prawy <= lewy)
	{

		return;
	}


	while (1) // pêtla nieskoñczona
	{

		//szukaj s³ów w tablicy wiekszych ni¿ pivot
		do
		{
			i++;


			t_l = stricmp(pivot, tab[i]); // porównaj s³owo z pivotem
			if (t_l <= 0) // jeœli s³owo jest wiêksze ni¿ pivot przerwij zliczanie i++
			{
				break;
			}

		} while (1);//pêtla nieskoñczona


		//szukaj s³ow w tablicy mniejszych ni¿ pivot
		do
		{
			j--;
			if (j < 0)
			{
				
				break;
			}
			
			t_p = stricmp(pivot, tab[j]); // porównaj s³owo z pivotem
			if (t_p >= 0 ) // jeœli s³owo jest mniejsze ni¿ pivot przerwij zliczanie j--
			{
				break;
			}

			



		} while (1);//pêtla nieskoñczona



		//jeœli liczniki sie nie minely to zamieñ s³owa ze sob¹, które stoj¹ po niew³asciwej stronie pivota
		if (i <= j)
			//funkcja swap zamienia wartosciami s³owa o indeksach i i j
			swap_pointers(tab, i, j);
		else
			break; //jeœli liczniki siê minê³y przerwij pêtle i sprawdŸ czy tablica jest ju¿ posortowana
	}
	// jeœli j > lewy wywo³aj funkcjê rekurencyjnie
	if (j > lewy)
	{
		quick_sort2(tab, lewy, j);
	}

	// jeœli i < prawy wywo³aj funkcjê rekurencyjnie
	if (i < prawy)
	{
		quick_sort2(tab, i, prawy);
	}

}
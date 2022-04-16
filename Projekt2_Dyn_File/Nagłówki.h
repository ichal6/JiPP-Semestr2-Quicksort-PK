
#include "pch.h"
#include <stdio.h>

char **odczyt_z_pliku2(char **tab,  int *i);

char **Alokuj(fpos_t ilosc_wierszy, char **str);

char *Alokuj_1D(char *str);

void quick_sort2(char **tab, int lewy, int prawy);

void zapis_do_pliku2(char **tab, int n);

void Zwolnij_tablice(fpos_t ilosc_wierszy, char **str);
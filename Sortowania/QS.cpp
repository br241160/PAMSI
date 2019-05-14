#include <iostream>

void quicksort(int *tab, int lef, int rig) {
	int i, j;
	int buf;
	int pivot = tab[(lef + rig) / 2];	//element podzialu tablicy
	i = lef;	//pierwszy element od lewej
	j = rig;	//pierwszy element od prawej

	while (i <= j) {
		while (tab[i] < pivot) i++;		//szukanie elementu wiêkszego od elementu odniesienia
		while (tab[j] > pivot) j--;		//szukanie elementu mniejszego od elementu odniesienia
		if (i <= j) {		//zamiana miejscami elementów
			buf = tab[i];
			tab[i] = tab[j];
			tab[j] = buf;
			i++;
			j--;
		}

	}
	if (j > lef) quicksort(tab, lef, j);	 //wywo³ania rekurencyjne funkcji dla tablic o zakresie od skrajnego elementu do elementu odniesienia 
	if (i < rig) quicksort(tab, i, rig);
}
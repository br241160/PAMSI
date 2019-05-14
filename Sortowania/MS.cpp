#include <iostream>

void merge(int *tab, int lef, int rig, int mid) {
	int i, j, k;
	int *temptab;		//tablica pomocnicza
	temptab = new int[rig - lef + 1];
	i = lef;
	j = mid + 1;
	k = 0;

	while (i <= mid && j <= rig) {
		if (tab[i] < tab[j]) {
			temptab[k] = tab[i];
			i++;
			k++;
		}
		else {
			temptab[k] = tab[j];
			j++;
			k++;
		}
	}

	while (i <= mid) {
		temptab[k] = tab[i];
		i++;
		k++;
	}

	while (j <= rig) {
		temptab[k] = tab[j];
		j++;
		k++;
	}

	for (i = lef; i <= rig; i++) {		//wpisanie posegregowanyc elementów z tablicy pomocniczej do tablicy g³ównej
		tab[i] = temptab[i - lef];
	}

}

void mergesort(int *tab, int lef, int rig) {	//funkcja dzielaca tablice na 2 "polowy"
	int mid;
	if (lef < rig) {
		mid = ((lef + rig) / 2);
		mergesort(tab, lef, mid);
		mergesort(tab, mid + 1, rig);
		merge(tab, lef, rig, mid);		//po skonczonym dzieleniu uruchomiona zostaja funkcja merge sortujaca i skladajaca razem talice
	}
}
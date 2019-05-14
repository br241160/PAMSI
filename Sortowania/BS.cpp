#include <iostream>

void bubblesort(int *tab, int size) {
	int temptab;
	for (int i = 1; i < size; i++) {
		for (int j = size - 1; j >= 1; j--) {	//pêtla zmieniaj¹ca elementy (indeksowanie elementów tablicy zaczyna siê od 0)
			if (tab[j] < tab[j - 1]) {	//sprawdzanie który element jest mniejszy
				temptab = tab[j - 1];	//zamiana miejsc elementów
				tab[j - 1] = tab[j];
				tab[j] = temptab;
			}
		}
	}
}

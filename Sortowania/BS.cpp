#include <iostream>

void bubblesort(int *tab, int size) {
	int temptab;
	for (int i = 1; i < size; i++) {
		for (int j = size - 1; j >= 1; j--) {	//p�tla zmieniaj�ca elementy (indeksowanie element�w tablicy zaczyna si� od 0)
			if (tab[j] < tab[j - 1]) {	//sprawdzanie kt�ry element jest mniejszy
				temptab = tab[j - 1];	//zamiana miejsc element�w
				tab[j - 1] = tab[j];
				tab[j] = temptab;
			}
		}
	}
}

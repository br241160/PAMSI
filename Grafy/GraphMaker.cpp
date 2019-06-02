#include <iostream>
#include <fstream>
#include "List.cpp"
#include <ctime>

int** hood_matrix(int *nod, int start_nod, int *thic) {	//funkcja tworzaca macierz sasiedztwa

	srand(time(NULL));

	std::ofstream graphM;
	graphM.open("graphmatrix.txt");

	int n = *nod;	//liczba wezlow
	int edges = (*thic *(n*(n - 1)) / 200);	//liczba krawedzi jest zalezna od gestosci grafu
	int m = edges;	//krawedzie
	int **hm = new int *[n];	//macierz sasiedztwa

	graphM << m << " " << n << " " << start_nod << std::endl;	//naglowek pliku z grafami



	for (int i = 0; i < n; ++i) {

		hm[i] = new int[n];

		for (int j = 0; j < n; ++j) {
		
			hm[i][j] = 0;
		
		}
	}

	int v1, v2, value;	//dwa wierzcholki, pomiedzy ktorymi rozpieta jest krawedz 

	for (int i = 0; i < n; ++i) {
		v1 = i;
		v2 = rand() % n;
		while (v2 == v1 || hm[v1][v2] != 0) {
			v2 = rand() % n;
		}
		
		value = rand() % (n / 2) + 1;
		graphM << v1 << " " << v2 << " " << value << "\n";
		hm[v1][v2] = value;
		hm[v2][v1] = value;
	}

	for (int i = 0; i < m - n; ++i) {
		v1 = rand() % n;
		v2 = rand() % n;
		while (v2 == v1 || hm[v1][v2] != 0) {
			v2 = rand() % n;
			v1 = rand() % n;
		}
		value = rand() % (n / 2) + 1;
		graphM << v1 << " " << v2 << " " << value << "\n";
		hm[v1][v2] = value;
		hm[v2][v1] = value;
	}

	graphM.close();
	return hm;
}



int showmatrix(int **graph, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << graph[i][j] << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}





List <int>* hood_list(int *nod, int start_nod, int *thic) {	//funkcja tworzaca liste sasiedztwa


	srand(time(NULL));

	std::ofstream graphL;
	graphL.open("graphlist.txt");

	int n = *nod;	//liczba wezlow
	int edges = (*thic *(n*(n - 1)) / 200);	//liczba krawedzi jest zalezna od gestosci grafu
	int m = edges;	//krawedzie
	//int **hm = new int *[n];	//macierz sasiedztwa

	List <int>* hl = new List <int>[n];

	graphL << m << " " << n << " " << start_nod << std::endl;	//naglowek pliku z grafami





	int v1, v2, value;	//dwa wierzcholki, pomiedzy ktorymi rozpieta jest krawedz 

	for (int i = 0; i < n; ++i) {
		v1 = i;
		v2 = rand() % n;
		while (v2 == v1 || hl[v1].search(v2) || (hl[v2]).search(v1)) {
			v2 = rand() % n;
		}
		value = rand() % (n / 2) + 1;
		graphL << v1 << " " << v2 << " " << value << "\n";
		(hl[v1]).pushback(v2, value);
		(hl[v2]).pushback(v1, value);

	}

	for (int i = 0; i < m - n; ++i) {
		v1 = rand() % n;
		v2 = rand() % n;
		while (v2 == v1 || hl[v1].search(v2) || (hl[v2]).search(v1)) {
			v2 = rand() % n;
			v1 = rand() % n;
		}
		value = rand() % (n / 2) + 1;
		graphL << v1 << " " << v2 << " " << value << "\n";
		(hl[v1]).pushback(v2, value);
		(hl[v2]).pushback(v1, value);
	}

	graphL.close();
	return hl;
}















int** hood_matrix_Bellm(int *nod, int start_nod, int *thic) {	//funkcja tworzaca macierz sasiedztwa graf skierowany z ujemnymi krawedziami

	//srand(time(NULL));

	std::ofstream graphBM;
	graphBM.open("graphmatrix.txt");

	int n = *nod;	//liczba wezlow
	int *tabgrp = new int[n];
	int edges = (*thic *(n*(n - 1)) / 200);	//liczba krawedzi jest zalezna od gestosci grafu
	int m = edges;	//krawedzie
	int **hm = new int *[n];	//macierz sasiedztwa
	int groups = n;

	graphBM << m << " " << n << " " << start_nod << std::endl;	//naglowek pliku z grafami


	for (int i = 0; i < n; i++) {
		tabgrp[i] = i;
	}


	for (int i = 0; i < n; ++i) {

		hm[i] = new int[n];

		for (int j = 0; j < n; ++j) {

			hm[i][j] = 0;

		}
	}

	int v1, v2, value, rn1, rn;	//dwa wierzcholki, pomiedzy ktorymi rozpieta jest krawedz 

	for (int i = 0; i < n && groups > 0; ++i) {
		v1 = i;
		v2 = rand() % n;
		
		while (tabgrp[v1] == tabgrp[v2] && tabgrp[v2] == 0) {
			v2 = rand() % n;
		}
		


		rn1 = rand() % (n / 2) + 1;
		rn = rand() % 100;
		if (rn < 50) {
			rn1 = rn1 * (-1);
		}
		value = rn1;
		tabgrp[v2] = tabgrp[v1];
		std::cout << "zmieniono grupe " << v2 << " na " << tabgrp[v1] << std::endl;
		groups--;
		std::cout << "pozostalo grup: " << groups <<std::endl;
		for (int i = 0; i < n; i++) {
			if (tabgrp[i] == tabgrp[v2]) {
				tabgrp[i] = tabgrp[v1];
			}
		}

		graphBM << v1 << " " << v2 << " " << value << "\n";
		hm[v1][v2] = value;
		//hm[v2][v1] = value;
	}

	for (int i = 0; i < m - n; ++i) {
		v1 = rand() % n;
		v2 = rand() % n;
		while (v2 == v1 || hm[v1][v2] != 0) {
			v2 = rand() % n;
			v1 = rand() % n;
		}
		value = rand() % (n + 1) - (6*n);
		graphBM << v1 << " " << v2 << " " << value << "\n";
		//hm[v1][v2] = value;
		hm[v2][v1] = value;
	}

	graphBM.close();
	delete[] tabgrp;
	return hm;
}







List <int>* hood_list_Bellm(int *nod, int start_nod, int *thic) {	//funkcja tworzaca liste sasiedztwa graf skierowany z ujemnymi krawedziami

	srand(time(NULL));

	std::ofstream graphBL;
	graphBL.open("graphlist.txt");

	int n = *nod;	//liczba wezlow
	int edges = (*thic *(n*(n - 1)) / 200);	//liczba krawedzi jest zalezna od gestosci grafu
	int m = edges;	//krawedzie
	int groups = n;
	int *tabgrp = new int[n];
	//int **hm = new int *[n];	//macierz sasiedztwa

	List <int>* hl = new List <int>[n];

	graphBL << m << " " << n << " " << start_nod << std::endl;	//naglowek pliku z grafami


	int v1, v2, value, rn1, rn;	//dwa wierzcholki, pomiedzy ktorymi rozpieta jest krawedz 

	for (int i = 0; i < n && groups > 0; ++i) {
		v1 = i;
		v2 = rand() % n;

		while (tabgrp[v1] == tabgrp[v2] && tabgrp[v2] == 0) {
			v2 = rand() % n;
		}



		rn1 = rand() % (n / 2) + 1;
		rn = rand() % 100;
		if (rn < 50) {
			rn1 = rn1 * (-1);
		}
		value = rn1;
		tabgrp[v2] = tabgrp[v1];
		std::cout << "zmieniono grupe " << v2 << " na " << tabgrp[v1] << std::endl;
		groups--;
		std::cout << "pozostalo grup: " << groups << std::endl;
		for (int i = 0; i < n; i++) {
			if (tabgrp[i] == tabgrp[v2]) {
				tabgrp[i] = tabgrp[v1];
			}
		}

		graphBL << v1 << " " << v2 << " " << value << "\n";
		(hl[v1]).pushback(v2, value);
		//(hl[v2]).pushback(v1, value);
	}

	for (int i = 0; i < m - n; ++i) {
		v1 = rand() % n;
		v2 = rand() % n;
		while (v2 == v1 || hl[v1].search(v2) || (hl[v2]).search(v1)) {
			v2 = rand() % n;
			v1 = rand() % n;
		}
		value = rand() % (n / 2) + 1;
		graphBL << v1 << " " << v2 << " " << value << "\n";
		(hl[v1]).pushback(v2, value);
		//(hl[v2]).pushback(v1, value);
	}

	graphBL.close();
	delete[] tabgrp;
	return hl;
}

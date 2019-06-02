#include "Bellm.h"
#include "List.cpp"


const int inf = INT_FAST32_MAX;

int *prev;
int *d;

bool SWay(int **mat, int n, int start) {
	d = new int[n];
	prev = new int[n];
	bool test;
	std::queue<int> unconsid;
	int qpop;

	for (int i = 0; i < n; i++) { //ustawiamy wszystkie odleglosci na nieskonczonosc
		d[i] = inf;
	}

	for (int i = 0; i < n; i++) { //tablica poprzednikow 
		prev[i] = -1;

	}
		d[start] = 0; //ustawiamy odlegosc do wierzcholka startowego na 0

		//for (int x = 0; x < 2; x++) {
			for (int i = start; i < n; i++) {
				test = true;	//zmienna przechowujaca info o zmianach
				for (int j = 0; j < n; j++) {
					if (d[i] != inf && mat[i][j] != 0 && d[j] > d[i] + mat[i][j]) { //jezeli odlegosc jest wieksza od nowej to zmieniamy
						test = false;
						d[j] = d[i] + mat[i][j];
						prev[j] = i;

					}
				}

			}

			for (int i = 0; i < start; i++) {
				test = true;	//zmienna przechowujaca info o zmianach
				for (int j = 0; j < n; j++) {
					if (d[i == inf]) {
						unconsid.push(i);
					}
					if (d[i] != inf && mat[i][j] != 0 && d[j] > d[i] + mat[i][j]) { //jezeli odlegosc jest wieksza od nowej to zmieniamy
						test = false;
						d[j] = d[i] + mat[i][j];
						prev[j] = i;

					}
				}

			}
		//}
		while (unconsid.empty() == false) {
			qpop = unconsid.front();
			unconsid.pop();
			for (int j = 0; j < n; j++) {
				if (d[qpop] != inf && mat[qpop][j] != 0 && d[j] > d[qpop] + mat[qpop][j]) { //jezeli odlegosc jest wieksza od nowej to zmieniamy
					test = false;
					d[j] = d[qpop] + mat[qpop][j];
					prev[j] = qpop;

				}
			}

		}

	
		
		
		d[start] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			if (d[i] != inf && mat[i][j] != 0 && d[j] != inf && d[i] + mat[i][j] < d[j]) {
				std::cout << "cykl ujemny" << i << "<->" << j << std::endl;
			}

		}
	}
	
	if (test == true)	return true;
	
}

int Bellman(int **mat, int nods, int start, int count) {
	int n, v; //liczba krawedzi i wierzcholek startowy
	n = nods;
	v = start;
	
	

	SWay(mat, n, v);

	int *nod_stack; //stos na wierzcholki
	nod_stack = new int[nods + 1];
	count = 0;	//za pomoca tego bedziemy liczyc wierzcholki powrotu
	prev[start] = -1;
	
	for (int i = 0; i < nods; i++) {
		std::cout << i << " koszt:  " << d[i] << std::endl;
	}
	


	for (int i = 0; i < nods; i++) {
		std::cout << "Shortest way to " << i << " :";
		for (int j = i; j != -1; j = prev[j]) {
			nod_stack[count++] = j;

			if (count > nods + 1) {
				std::cout << "\n!!!!Graph Error!!!!" << std::endl;
				break;
			}
		}

		if (count > nods + 1) {
			break;
		}
		while (count > 0) {
			std::cout << nod_stack[--count] << " ";
		}

		std::cout << "koszt: " << d[i] << std::endl;
	}


	//usuwanie struktur dynamicznych
	//czy na pewno wszystkie dynamiczne usuwam?
	//delete[] nod_stack;
	//delete[] d;
	//delete[] prev;

	return count;
}






















bool SWay_List(List <int>* hl, int n, int start) {
	d = new int[n];
	prev = new int[n];
	bool test;
	std::queue<int> unconsid;
	int qpop;

	for (int i = 0; i < n; i++) { //ustawiamy wszystkie odleglosci na nieskonczonosc
		d[i] = inf;
	}

	for (int i = 0; i < n; i++) { //tablica poprzednikow 
		prev[i] = -1;

	}
	d[start] = 0; //ustawiamy odlegosc do wierzcholka startowego na 0


	for (int i = start; i < n; i++) {
		test = true;	//zmienna przechowujaca info o zmianach
		for (int j = 0; j < n; j++) {
			if (d[i] != inf && hl[i].search(j) != 0 && d[j] > d[i] + hl[i].search(j)) { //jezeli odlegosc jest wieksza od nowej to zmieniamy
				test = false;
				d[j] = d[i] + hl[i].show_curve(j);
				prev[j] = i;

			}
		}

	}

	for (int i = 0; i < start; i++) {
		test = true;	//zmienna przechowujaca info o zmianach
		for (int j = 0; j < n; j++) {
			if (d[i == inf]) {
				unconsid.push(i);
			}
			if (d[i] != inf && hl[i].search(j) != 0 && d[j] > d[i] + hl[i].search(j)) { //jezeli odlegosc jest wieksza od nowej to zmieniamy
				test = false;
				d[j] = d[i] + hl[i].show_curve(j);
				prev[j] = i;

			}
		}

	}

	while (unconsid.empty() == false) {
		qpop = unconsid.front();
		unconsid.pop();
		for (int j = 0; j < n; j++) {
			if (d[qpop] != inf && hl[qpop].search(j) != 0 && d[j] > d[qpop] + hl[qpop].search(j)) { //jezeli odlegosc jest wieksza od nowej to zmieniamy
				test = false;
				d[j] = d[qpop] + hl[qpop].show_curve(j);
				prev[j] = qpop;

			}
		}

	}




	d[start] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			if (d[i] != inf && hl[i].search(j) != 0 && d[j] != inf && d[i] + hl[i].search(j) < d[j]) {
				std::cout << "cykl ujemny bellman lista" << i << "<->" << j << std::endl;
			}

		}
	}

	if (test == true)	return true;

}

int Bellman_List(List <int>* hl, int nods, int start, int count) {
	int n, v; //liczba krawedzi i wierzcholek startowy
	n = nods;
	v = start;



	SWay_List(hl, nods, start);

	int *nod_stack; //stos na wierzcholki
	nod_stack = new int[nods + 1];
	count = 0;	//za pomoca tego bedziemy liczyc wierzcholki powrotu
	prev[start] = -1;

	for (int i = 0; i < nods; i++) {
		std::cout << i << " koszt:  " << d[i] << std::endl;
	}



	for (int i = 0; i < nods; i++) {
		std::cout << "Shortest way to " << i << " :";
		for (int j = i; j != -1; j = prev[j]) {
			nod_stack[count++] = j;

			if (count > nods + 1) {
				std::cout << "\n!!!!Graph Error!!!!" << std::endl;
				break;
			}
		}

		if (count > nods + 1) {
			break;
		}
		while (count > 0) {
			std::cout << nod_stack[--count] << " ";
		}

		std::cout << "koszt: " << d[i] << std::endl;
	}


	//usuwanie struktur dynamicznych
	//czy na pewno wszystkie dynamiczne usuwam?
	//delete[] nod_stack;
	//delete[] d;
	//delete[] prev;

	return count;
}



















/*

bool SWay_List(List <int>* hl, int n, int start) {
	d = new int[n];
	prev = new int[n];
	bool test;

	for (int i = 0; i < n; i++) { //ustawiamy wszystkie odleglosci na nieskonczonosc
		d[i] = inf;
	}

	for (int i = 0; i < n; i++) { //tablica poprzednikow 
		prev[i] = -1;
	}

	d[start] = 0; //ustawiamy odlegosc do wierzcholka startowego na 0

	for (int x = 1; x < n; x++) {
		for (int i = 0; i < n; i++) {
			test = true;	//zmienna przechowujaca info o zmianach
			for (int j = 0; j < n; j++) {
				if (hl[i].search(j) != 0 && d[j] > d[i] + hl[i].search(j)) { //jezeli odlegosc jest wieksza od nowej to zmieniamy
					test = false;
					d[j] = d[i] + hl[i].show_curve(j);
					prev[j] = i;

				}
			}

		}
	}


	return true;
}

int Bellman_List(List <int>* hl, int nods, int start, int count) {
	//int n, v; //liczba krawedzi i wierzcholek startowy
	//n = nods;
	//v = start;

	SWay_List(hl, nods, start);

	int *nod_stack; //stos na wierzcholki	
	nod_stack = new int[nods];
	count = 0;	//za pomoca tego bedziemy liczyc wierzcholki powrotu


	for (int i = 0; i < nods; i++) {
		std::cout << "Shortest way to " << i << " :";
		for (int j = i; j != -1; j = prev[j]) {
			nod_stack[count++] = j;

			if (count > nods + 1) {
				std::cout << "\n!!!!Graph Error!!!!" << std::endl;
				break;
			}
		}

		if (count > nods + 1) {
			break;
		}
		while (count > 0) {
			std::cout << nod_stack[--count] << " ";
		}

		std::cout << "koszt: " << d[i] << std::endl;
	}


	//usuwanie struktur dynamicznych
	//czy na pewno wszystkie dynamiczne usuwam?
	//delete[] nod_stack;
	//delete[] d;
	//delete[] prev;

	return count;
}

*/
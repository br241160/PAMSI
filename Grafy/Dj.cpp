#include "Dj.h"
#include "List.cpp"

const int inf = INT_FAST32_MAX;

int Dijkstry(int **mat, int nods, int start, int count) {


	
	int *tabval;
	int *tabprev;
	int *tabprint;
	bool *visited;

	tabval = new int[nods];
	tabprev = new int[nods];
	tabprint = new int[nods];
	visited = new bool[nods];

	for (int i = 0; i < nods; i++) { //ustawiamy wszystkie odleglosci na nieskonczonosc
		tabval[i] = inf;
	}

	for (int i = 0; i < nods; i++) { //tablica poprzednikow 
		tabprev[i] = 0;
	}


	for (int i = 0; i < nods; i++) { //tablica odwiedzonych
		visited[i] = false;
	}

	std::priority_queue<std::pair<int, int> > pq; //kolejka priorytetowa sluzaca do okreslenia sasiada z najmniejsza odlegloscia

	std::stack<int> s; //stos wierzcholkow

	int topstack, n;
	std::pair<int, int> p1, topqueue;
	tabval[start] = 0; //tablica wartosci odleglosci
	s.push(start); //wrzucamy pierwszy wierzcholek startowy

	tabprev[start]= -1;
	p1 = std::make_pair(0, start);
	pq.push(p1);
	tabval[start] = 0;

	while (!s.empty()) {	
		topstack = s.top();
		s.pop();
		if (visited[topstack] == false) {
			visited[topstack] = true; 
			n = topstack;

			

		
			

			for (int j = 0 ; j < nods; j++)
			{
				if (mat[n][j] != 0)
				{
					
					if (tabval[j] > tabval[n] + mat[n][j]) {
						tabval[j] = tabval[n] + mat[n][j];
						tabprev[j] = n; //ustawiamy poprzednika
					}

					p1 = std::make_pair(mat[n][j], j);	
					pq.push(p1);

				}
			}
			while (pq.empty() == false)
			{
				topqueue = pq.top();
				s.push(topqueue.second);
				pq.pop();
			}
		}

	}

	tabprev[0] = -1;
	count = 0;

	
	
	for (int i = 0; i < nods; i++) {
		std::cout << "Shortest way to " << i << " :";
		for (int j = i; j != -1; j = tabprev[j]) {
			tabprint[count++] = j;
		}

		while (count > 0) {
			std::cout << tabprint[--count] << " ";
		}

		std::cout << "koszt: " << tabval[i] << std::endl;
	}

	//usuwanie struktur dynamicznych
	delete [] tabval;
	delete [] tabprev;
	delete [] tabprint;
	delete [] visited;


	return count;
}
















int Dijkstry_List(List <int>* hl, int nods, int start, int count) {



	int *tabval;
	int *tabprev;
	int *tabprint;
	bool *visited;

	tabval = new int[nods];
	tabprev = new int[nods];
	tabprint = new int[nods];
	visited = new bool[nods];

	for (int i = 0; i < nods; i++) { //ustawiamy wszystkie odleglosci na nieskonczonosc
		tabval[i] = inf;
	}

	for (int i = 0; i < nods; i++) { //tablica poprzednikow 
		tabprev[i] = 0;
	}


	for (int i = 0; i < nods; i++) { //tablica odwiedzonych
		visited[i] = false;
	}

	std::priority_queue<std::pair<int, int> > pq; //kolejka priorytetowa sluzaca do okreslenia sasiada z najmniejsza odlegloscia

	std::stack<int> s; //stos wierzcholkow

	int topstack, n;
	std::pair<int, int> p1, topqueue;
	tabval[start] = 0; //tablica wartosci odleglosci
	s.push(start); //wrzucamy pierwszy wierzcholek startowy

	tabprev[start] = -1;
	p1 = std::make_pair(0, start);
	pq.push(p1);
	tabval[start] = 0;

	while (!s.empty()) {	
		topstack = s.top();
		s.pop();
		if (visited[topstack] == false) {
			visited[topstack] = true;
			n = topstack;






			for (int j = 0; j < nods; j++)
			{
				if (hl[n].search(j) != 0)
				{

					if (tabval[j] > tabval[n] + hl[n].show_curve(j)) {
						tabval[j] = tabval[n] + hl[n].show_curve(j);
						tabprev[j] = n; //ustawiamy poprzednika
					}

					p1 = std::make_pair(hl[n].show_curve(j), j);
					pq.push(p1);

				}
			}
			while (pq.empty() == false)
			{
				topqueue = pq.top();
				s.push(topqueue.second);
				pq.pop();
			}
		}

	}

	tabprev[0] = -1;
	 count = 0;

	

	for (int i = 0; i < nods; i++) {
		std::cout << "Shortest way to " << i << " :";
		for (int j = i; j != -1; j = tabprev[j]) {
			tabprint[count++] = j;
		}

		while (count > 0) {
			std::cout << tabprint[--count] << " ";
		}

		std::cout << "koszt: " << tabval[i] << std::endl;
	}

	//usuwanie struktur dynamicznych
	delete [] tabval;
	delete [] tabprev;
	delete [] tabprint;
	delete [] visited;


	return count;
}
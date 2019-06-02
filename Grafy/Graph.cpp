#include "Header.h"
#include "Dj.h"
#include "Bellm.h"
#include <iostream>
#include <chrono>
#include <fstream>

int main()
{
	
	int startt;
	int nodss = 5;
	int thick = 50;
	int count = 0;
	startt = 4;

	//int edges = (thick *(nodss*(nodss - 1)) / 200);

	int tabthick[4] = { 25, 50, 75, 100 };
	int tabnods[4] = { 5, 10, 50, 100 };
	//std::cout << startt << std::endl;
	//hood_matrix(&nodss, startt, &thick);

	//int ** graph = hood_matrix_Bellm(&nodss, startt, &thick);

	//int ** graph = hood_matrix(&nodss, startt, &thick);
	//List <int> * graphlist = hood_list(&nodss, startt, &thick);
	//showmatrix(graph, nodss);
	//std::cout << "Dijkstry dla macierzy:" << std::endl;
	//Dijkstry(graph, nodss, startt, count);
	//std::cout << "Dijkstry dla listy:" << std::endl;
	//Dijkstry_List(graphlist, nodss, startt, count);
	//std::cout << "Bellman Ford dla macierzy" << std::endl;
	//Bellman(graph, nodss, startt, count);
	//std::cout << "Bellman Ford dla listy" << std::endl;
	//Bellman_List(graphlist, nodss, startt, count);



	
	
	
	std::ofstream filleDijM("Dij_Matrix.xls");
	std::ofstream filleDijL("Dij_List.xls");

	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {

			

			int ** graph = hood_matrix(&tabnods[j], startt, &tabthick[i]);
			List <int> * graphlist = hood_list(&tabnods[j], startt, &tabthick[i]);

			auto start1 = std::chrono::high_resolution_clock::now();
			Dijkstry(graph, tabnods[j], startt, count);
			auto finish1 = std::chrono::high_resolution_clock::now();
			while (count > tabnods[j] + 1) {		//jezeli graf nie jest spojny 

				int **  graph = hood_matrix(&tabnods[j], startt, &tabthick[i]);
				auto start1 = std::chrono::high_resolution_clock::now();
				count = Dijkstry(graph, tabnods[j], startt, count);
				auto finish1 = std::chrono::high_resolution_clock::now();

			}
			if (count <= tabnods[j] + 1) {
				std::chrono::duration<double>elapsed1 = (finish1 - start1) * 1000.0;
				filleDijM << elapsed1.count() << std::endl;
				//std::cout << "DJM time" << elapsed1.count() << "ms" << std::endl;
			}

			
			auto start2 = std::chrono::high_resolution_clock::now();
			count = Dijkstry_List(graphlist, tabnods[j], startt, count);
			auto finish2 = std::chrono::high_resolution_clock::now();
			std::cout << count << std::endl;
			while (count > tabnods[j] + 1) {

				List <int> * graphlist = hood_list(&tabnods[j], startt, &tabthick[i]);
				auto start2 = std::chrono::high_resolution_clock::now();
				count = Dijkstry_List(graphlist, tabnods[j], startt, count);
				auto finish2 = std::chrono::high_resolution_clock::now();

			}
			if (count <= tabnods[j] + 1) {
				std::chrono::duration<double>elapsed2 = (finish2 - start2) * 1000.0;
				filleDijL << elapsed2.count() << std::endl;
			}
			
		}
	}
	filleDijM.close();
	filleDijL.close();
	

	
	



	
	
	
	std::ofstream filleBellmM("Bellm_Matrix.xls");
	std::ofstream filleBellmL("Bellm_List.xls");

	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {



			int ** graph = hood_matrix(&tabnods[j], startt, &tabthick[i]);
			List <int> * graphlist = hood_list(&tabnods[j], startt, &tabthick[i]);

			auto start1 = std::chrono::high_resolution_clock::now();
			Bellman(graph, tabnods[j], startt, count);
			auto finish1 = std::chrono::high_resolution_clock::now();
			while (count > tabnods[j] + 1) {

				int **  graph = hood_matrix(&tabnods[j], startt, &tabthick[i]);
				auto start1 = std::chrono::high_resolution_clock::now();
				count = Bellman(graph, tabnods[j], startt, count);
				auto finish1 = std::chrono::high_resolution_clock::now();

			}
			if (count <= tabnods[j] + 1) {
				std::chrono::duration<double>elapsed1 = (finish1 - start1) * 1000.0;
				filleBellmM << elapsed1.count() << std::endl;

			}

			
			auto start2 = std::chrono::high_resolution_clock::now();
			count = Bellman_List(graphlist, tabnods[j], startt, count);
			auto finish2 = std::chrono::high_resolution_clock::now();
			std::cout << count << std::endl;
			while (count > tabnods[j] + 1) {

				List <int> * graphlist = hood_list(&tabnods[j], startt, &tabthick[i]);
				auto start2 = std::chrono::high_resolution_clock::now();
				count = Bellman_List(graphlist, tabnods[j], startt, count);
				auto finish2 = std::chrono::high_resolution_clock::now();

			}
			if (count <= tabnods[j] + 1) {
				std::chrono::duration<double>elapsed2 = (finish2 - start2) * 1000.0;
				filleBellmL << elapsed2.count() << std::endl;
			}
			
		}
	}
	filleBellmM.close();
	filleBellmL.close();
	

}



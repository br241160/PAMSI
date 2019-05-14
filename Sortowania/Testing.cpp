#include <iostream>
#include <chrono>
#include <fstream>
#include "BS.cpp"
#include "QS.cpp"
#include "MS.cpp"

void showtab(int *tab, int size) {
	for (int i = 0; i < size; i++) {
		std::cout << tab[i] << " ";
	}
}
void  testmerge() {

	int size;
	std::cin >> size;
	std::cout << size << std::endl;
	int *tab;
	tab = new int[size];
	for (int i = 0; i < size; i++) {
			tab[i] = rand() % 1000000 + 1;
		}
	showtab(tab, size);
	mergesort(tab, 0, size);
	showtab(tab, size);


}

void test_timingBS() {

	std::ofstream filleBs("SortowaniaBs.xls");
	std::ofstream filleQs("sortowaniaQs.xls");
	std::ofstream filleMs("sortowaniaMs.xls");
	int size;
	std::cin >> size;
	int tmp;
	tmp = size;

	for (int j = 0; j < 50; j++) {
		size = tmp + 1000;
		tmp = size;
		for (int k = 0; k < 10; k++) {
			std::cout << size << std::endl;
			int *tab;
			int *tab2, *tab3;
			tab = new int[size];
			tab2 = new int[size];
			tab3 = new int[size];
			for (int i = 0; i < size; i++) {
				tab[i] = rand() % 1000000 + 1;
				tab2[i] = tab[i];
				tab3[i] = tab[i];
			}



			auto start1 = std::chrono::high_resolution_clock::now();
			bubblesort(tab, size - 1);
			auto finish1 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double>elapsed1 = (finish1 - start1) * 1000.0;
			std::cout << " Boubble Sorting time: " << elapsed1.count() << "ms" << std::endl;
			filleBs << elapsed1.count() << std::endl;

			auto start2 = std::chrono::high_resolution_clock::now();
			quicksort(tab, 0, size - 1);
			auto finish2 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double>elapsed2 = (finish2 - start2) * 1000.0;
			std::cout << " Quick Sorting time: " << elapsed2.count() << "ms" << std::endl;
			filleQs << elapsed2.count() << std::endl;
			
			
			auto start3 = std::chrono::high_resolution_clock::now();
			mergesort(tab, 0, size - 1);
			auto finish3 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double>elapsed3 = (finish3 - start3) * 1000.0;
			std::cout << " Merge Sorting time: " << elapsed3.count() << "ms" << std::endl;
			filleMs << elapsed3.count() << std::endl;
			

			delete[] tab;
			delete[] tab2;
			delete[] tab3;
		}
	}
	filleBs.close();
	filleQs.close();
	filleMs.close();

}
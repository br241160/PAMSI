#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "List.cpp"

int** hood_matrix(int*, int, int*);
List <int>* hood_list(int*, int, int*);
int showmatrix(int **, int);
int** hood_matrix_Bellm(int*, int, int*);
List <int>* hood_list_Bellm(int*, int, int*);
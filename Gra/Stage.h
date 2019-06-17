#pragma once
#include <iostream>

const char blank = ' ';
const char cross = 'X';
const char circle = 'O';
const bool AI = 1;
const bool hum = 0;
const char tieval = 'r';


class Stage {

	int size;
	int wincount = 3;
	char** stagemat;

public:

	Stage();
	//Stage(int size);
	void Sstage(int size, int wincount);
	int getsize();
	char getVal(int x, int y);
	void setVal(int x, int y, char val);
	void clear();
	void print();
	char winCheck();




};

struct Player {

	

public:

	bool ifAI;
	Player();
	char sign;
	void AIcheck(bool AIi);
	bool getAI();

};
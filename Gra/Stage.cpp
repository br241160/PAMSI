#include "Stage.h"

Player::Player() {

}

bool Player::getAI() {

	return ifAI;
}

void Player::AIcheck(bool AIi) {

	if (AIi == AI) {
		ifAI = AI;
	}
	else {
		ifAI = hum;
	}

}

Stage::Stage() {

}

/*
Stage::Stage(int sizee) {
	size = sizee;

	stagemat = new char *[size];
	for (int i = 0; i < size; i++) {
		stagemat[i] = new char[size];
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			stagemat[i][j] = blank;
		}
	}
}
*/


//zrobic wprowadzenie rozmiaru
void Stage::Sstage(int sizee, int wincountt) {
	size = sizee;
	wincount = wincountt;

	stagemat = new char *[size];
	for (int i = 0; i < size; i++) {
		stagemat[i] = new char[size];
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			stagemat[i][j] = blank;
		}
	}
}


int Stage::getsize() {

	return size;

}

char Stage::getVal(int x, int y) {

	return stagemat[x][y];

}

void Stage::setVal(int x, int y, char val) {

	while (true) {
		if (stagemat[x][y] == blank) {
			stagemat[x][y] = val;
			break;
		}
		else if (val == blank)
		{
			stagemat[x][y] = val;
			break;
		}
	}

}

void Stage::clear() {

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			this->setVal(i, j, blank);
		}
	}

}

void Stage::print() {

	std::cout << "\n The Game: \n\n";

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {

			std::cout << "| " << this->getVal(i, j) << " ";

		}
		std::cout << "|\n";
		if (i < size - 1) {
			for (int k = 0; k < size; k++) {
				std::cout << " ---";

			}
			std::cout << "\n";
		}
	}

}


//sprawdzanie cyz ktos wygral
char Stage::winCheck() {
	
	bool win = false;
	char prev, now;
	int count = 0;

	//sprawdzanie wierszy
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {

			now = this->getVal(i, j);
			if (count == 0) {
				count++;
			}
			else {

				if (prev == now && now != blank) {
					count++;
				}
				else {
					count = 1;
				}
			}

			prev = now;
			if (count == wincount) {
				win = true;
			}
			if (win) {

				return now;

			}

		}

		count = 0;

	}

	//sprawdzanie kolumn
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {

			now = this->getVal(j, i);
			if (count == 0) {
				count++;
			}
			else
			{
				if (prev == now && now != blank) {
					count++;
				}
				else {
					count = 1;
				}
			}
			
			prev = now;
			if (count == wincount) {
				win = true;
			}
			if (win) {
				return now;
			}
		}
		count = 0;
	}

	//glowna przekatna
	for (int i = 0; i < size; i++) {
		now = this->getVal(i, i);
		if (count == 0) {
			count++;
		}
		else
		{
			if (prev == now && now != blank) {
				count++;
			}
			else {
				count = 1;
			}
		}
		prev = now;
		if (count == wincount) {
			win = true;
		}
		if (win) {
			return now;
		}
	}

	int dif = size - wincount;
	//lewo nad glowna
	for (int i = 1; i <= dif; i++) {
		for (int j = 0; j < size - i; j++) {
			now = this->getVal(j, i + j);
			if (count == 0) {
				count++;
			}
			else {
				if (prev == now && now != blank) {
					count++;
				}
				else {
					count = 1;
				}
			}
			prev = now;
			if (count == wincount) {
				win = true;
			}
			if (win) {
				return now;
			}
		}
		count = 0;

		
	}


	//lewo pod glowna

	for (int i = 1; i <= dif; i++) {
		for (int j = 0; j < size - i; j++)
		{
			now = this->getVal(i + j, j);
				if (count == 0) {
					count++;
				}
				else {
					if (prev == now && now != blank) {
						count++;
					}
					else {
						count = 1;
					}
				}
			prev = now;
			if (count == wincount) {
				win = true;
			}
			if (win) {
				return now;
			}
		}
		count = 0;

	}




	//od prawej gory

	//glowna przekatna

	count = 0;
	for (int i = 0; i < size; i++) {
		now = this->getVal(i, size - i - 1);
		if (count == 0) {
			count++;
		}
		else
		{
			if (prev == now && now != blank) {
				count++;
			}
			else {
				count = 1;
			}
		}
		prev = now;
		if (count == wincount) {
			win = true;
		}
		if (win) {
			return now;
		}
		
	}

	//prawo nad glowna
	for (int i = 1; i <= dif; i++) {
		for (int j = 0; j < size - i; j++) {
			now = this->getVal(j, size - i - 1 - j);
			if (count == 0) {
				count++;
			}
			else
			{
				if (prev == now && now != blank) {
					count++;
				}
				else {
					count = 1;
				}
			}
			prev = now;
			if (count == wincount) {
				win = true;
			}
			if (win) {
				return now;
			}
		}
		count = 0; 
	}

	//prawo pod glowna
	for (int i = 1; i <= dif; i++) {
		for (int j = 0; j < size - i; j++) {
			now = this->getVal(size - i - 1 - j, j);
			if (count == 0) {
				count++;
			}
			else
			{
				if (prev == now && now != blank) {
					count++;
				}
				else {
					count = 1;
				}
			}
			prev = now;
			if (count == wincount) {
				win = true;
			}
			if (win) {
				return now;
			}
		}
		count = 0;
	}


	//remis?
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (this->getVal(i, j) == blank) {
				return blank;
			}
		}
	}
	return tieval;	//sprawdziæ!!


}
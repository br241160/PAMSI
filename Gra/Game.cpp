#include "Game.h"
#include "Stage.h"

Game::Game() {

	gameState = 0;

}

Game::Game(int size, int wincount) {

	stage.Sstage(size, wincount);
	gameState = 0;

}


void Game::gameStart() {

	X.sign = cross;
	O.sign = circle;
	gameState = 1;
	multiplayercheck = menuMultiplayer();
	turn = circle;

	if (multiplayercheck) {

		O.AIcheck(hum);
		X.AIcheck(hum);

	}
	else
	{

		if (menuSign() == 'O') {

			O.AIcheck(hum);
			X.AIcheck(AI);
			playerAI.init(cross);	//przypisanie znaku ai i graczu
		}
		else
		{

			O.AIcheck(AI);
			playerAI.init(circle);
			X.AIcheck(hum);
		

		}

	}

}

void Game::changePlayer() {

	if (turn == circle) {
		turn = cross;
	}
	else {
		turn = circle;
	}

}


void Game::playerMove(Player player) {
	int x, y;
	while (true) {

		std::cout << "Place your sign\n(x coordinate) ";
		std::cin >> y;
		std::cout << "(y coordinate) ";
		std::cin >> x;
		if (stage.getVal(x, y) == blank) {
			stage.setVal(x, y, player.sign);
				break;
		}
		else {
			std::cout << "This place is unavailable, choose another place\n";
		}

	}

}

void Game::aiMove(Player player) {

	playerAI.perfMove(stage);

}


void Game::gameEnd() {

	gameState = false;

}


void Game::run() {

	while (gameState) {

		stage.print();
		if (turn == cross) {
			std::cout << "Player X turn\n\n";
		}
		else
		{
			std::cout << "Player O turn\n\n";
		}

		switch (turn) {
		case cross:
		{
			if (X.getAI())this->aiMove(X);
			else playerMove(X);
			break;
		}
		case circle:
		{
			if (O.getAI())this->aiMove(O);
			else playerMove(O);
			break;
		}
		default:
		{
			break;
		}
		}

		if (stage.winCheck() != blank) {

			stage.print();
			gameState = false;
			switch (stage.winCheck())
			{

			case tieval:
			{
				std::cout << "\nTie\n";
				break;
			}
			default:
				std::cout << "\nPlayer " << stage.winCheck() << " won!\n";
				break;

			}
		}

		else
		{
			changePlayer();
			std::cout << "\n\n\n\n\n\n\n\n\n\n\n";
		}

	}
}


bool menuMultiplayer()
{
	bool respo = false, rv;
	char decision;

	while (respo == false)
	{
		std::cout << "AI or 2 players? (a or 2) \n";
		std::cin >> decision;
		std::cout << "\n";

		switch (decision) {
		case'2':
			rv = true;
			respo = true;
			break;

		case'a':
			rv = false;
			respo = true;
			break;

		default:
			std::cout << "Wrong answer \n";
			respo = false;
			break;
		}
	}

	switch (rv)
	{
	case true:
		std::cout << "\n Multiplayer Mode\n";
		break;

	case false:
		std::cout << "\n AI  mode\n";
		break;

	}
	return rv;

}

int menuSize() {
	int size;
	std::cout << "\nEnter size of the stage\n";
	std::cin >> size;
	return size;
}

int menuWin() {
	int rv;
	std::cout << "\nHow many signs to win?\n";
	std::cin >> rv;
	return rv;
}

char menuSign() {
	bool respo = false;
	char sign, decision;

	while (respo == false) {

		std::cout << "Which sing do you want do play? X or O? \n";
		std::cin >> decision;
		std::cout << "\n";

		switch (decision) 
		{

		case'O':
			sign = decision;
			respo = true;
			break;

		case'X':
			sign = decision;
			respo = true;
			break;
			
		default:
			std::cout << "Wrong answer\n";
			respo = false;
			break;

		}
	}

	switch (sign) 
	{

	case'X':
		std::cout << "\nPlaying as X\n";
		break;

	case'O':
		std::cout << "\nPlaying as O\n";
		break;

	}
	return sign;
}
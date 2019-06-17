#pragma once
#include <iostream>
#include "Stage.h"
#include "AI.h"


class Game {

	Ai playerAI;
	bool multiplayercheck;
	char turn;

	bool gameState;
	Player X;
	Player O;

public:

	Stage stage;
	Game();
	Game(int size, int win);
	void gameStart();
	void gameEnd();
	void changePlayer();
	void playerMove(Player player);
	void aiMove(Player player);
	void run();

};

char menuSign();
bool menuMultiplayer();
int menuSize();
int menuWin();

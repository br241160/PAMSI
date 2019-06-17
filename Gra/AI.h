#pragma once
#include "stage.h"

struct AImove
{
	int x;
	int y;
	int score;

	AImove();
	AImove(int Score);

};

class Ai
{
private:
	Player aiplayer;
	Player humplayer;

public:

	AImove bestMove(Stage& stage, Player player);
	void init(char aiPlayer);
	void perfMove(Stage &stage);

};
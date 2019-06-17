#include <iostream>
#include "Game.h"
#include "Stage.h"

int main()
{
	Game newGame(menuSize(), menuWin());

	newGame.gameStart();
	newGame.run();


}

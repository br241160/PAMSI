#include "AI.h"
#include <vector>

AImove::AImove() {

}

AImove::AImove(int Score) {
	score = Score;
}

void Ai::init(char aiPlayer) {
	
	aiplayer.sign = aiPlayer;
	if (aiPlayer == cross) {
		//aiplayer.sign = cross;
		humplayer.sign = circle;
	}
	else {
		//aiplayer.sign = circle;
		humplayer.sign = cross;
	}
	//aiplayer.ifAI = true;
	//humplayer.ifAI = false;
}


void Ai::perfMove(Stage& stage) {

	//aiplayer.sign = circle;
	//humplayer.sign = cross;

	AImove best = bestMove(stage, aiplayer);
	stage.setVal(best.x, best.y, aiplayer.sign);
}


//wyszukiwanie najelszpego ruchu
AImove Ai::bestMove(Stage & stage, Player player) {

	char rv = stage.winCheck();
	if (rv == aiplayer.sign) {

		return AImove(10);

	}
	else if (rv == humplayer.sign) {
		return AImove(-10);
	}
	else if (rv == tieval) {
		return AImove(0);
	}
	//else if (rv == blank) {
		//std::cout << "Tie case";
		//return AImove(0);
	//}
	

	std::vector<AImove> moves;

	for (int y = 0; y < stage.getsize(); ++y) {
		for (int x = 0; x < stage.getsize(); ++x) {

			if (stage.getVal(x, y) == blank) {

				AImove move;
				move.x = x;
				move.y = y;
				stage.setVal(x, y, player.sign);
				if (player.sign == aiplayer.sign) {

					move.score = bestMove(stage, humplayer).score;

				}
				else {

					move.score = bestMove(stage, aiplayer).score;

				}
				moves.push_back(move);
				stage.setVal(x, y, blank);

			}

		}
	}


	//indeks najlepszego ruchu ai, w wektorze
	int BestMove = 0;

	if (player.sign == aiplayer.sign) {

		int BestScore = -1000000;
		for (int i = 0; i < moves.size(); ++i) {

			if (moves[i].score > BestScore) {

				BestMove = i;
				BestScore = moves[i].score;

			}

		}

	}
	else {

		int BestScore = 1000000;
		for (int i = 0; i < moves.size(); ++i) {
			if (moves[i].score < BestScore) {
				BestMove = i;
				BestScore = moves[i].score;
			}

		}

	}

	return moves[BestMove];

}
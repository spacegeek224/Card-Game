#include <string>
#include <time.h>
#include <cstdlib>
#include <fcntl.h>
#include <io.h>
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

class game {

	//TODO add in exception catching
private:
	string name;
	int p1Score;
	int p2Score;
public:
	game() {

	}
	
	game(string myGame) {
		name = myGame;
	}
	
	void init() {
		
	}

	int checkWinner() {
		if (p1Score > p2Score) {
			return 1;
		}
		if (p2Score > p1Score) {
			return 2;
		}
		if (p1Score == p2Score) {
			return 0;
		}
	}
	int getPlayer1Score() {
		return p1Score;
	}
	int getPlayer2Score() {
		return p2Score;
	}
	void setPlayer1Score(int score) {
		p1Score = score;
	}
	void setPlayer1Score(int score) {
		p2Score = score;
	}

};
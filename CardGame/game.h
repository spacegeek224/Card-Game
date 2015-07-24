#include <string>
#include <Windows.h>
#include <time.h>
#include <cstdlib>
#include <fcntl.h>
#include <io.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include "card.h"


using namespace std;

class game {

	//TODO add in exception catching
private:
	string name;
	string author;
	

	bool useLogo;
	string plr1Name;
	string plr2Name;
	
	
public:
	game() {
		name = "CardGame";
		author = "spacegeek224";
		useLogo = true;
	}

	game(string gameName, string gameAuthor, bool l) {
		name = gameName;
		author = gameAuthor;
		useLogo = l;
	}
	card player1Hand[52];
	card player2Hand[52];
	card cardDeck[52];
	int topCard;
	int plr1Size;
	int plr2Size;
	int plr1Score;
	int plr2Score;
	void init() {
		plr1Score = 0;
		plr2Score = 0;
		loadDeck(cardDeck);
		shuffle(cardDeck, 52);
		cout << "Welcome to..." << endl;
		sleep(3, 1);
		clearScreen();
		displayLogo();
		cout << "This version of " << name << " was developed by " << author << "." << endl;
		sleep(3, 1);
		clearScreen();
		cout << "Player 1 enter your name: ";
		getline(cin, plr1Name);
		cout << endl;
		clearScreen();
		//cin.get();
		cout << "Player 2 enter your name: ";
		getline(cin, plr2Name);
		cout << endl;
		clearScreen();
	}
	//Logo file must be called logo.txt
	/*void setLogo() {
	ofstream logoFileOut("logo.txt");
	logoFile.open("logo.txt");
	logoFile 
	}*/

	//Logo file must be called logo.txt
	void displayLogo() {
		string line;
		ifstream logoFile("logo.txt");
		if (logoFile.is_open()) {
			while (getline(logoFile,line)) {
				cout << line << endl;
			}
			logoFile.close();
		}

	}

	int checkWinner() {
		if (plr1Score > plr2Score) {
			return 1;
		}
		if (plr2Score > plr1Score) {
			return 2;
		}
		if (plr1Score == plr2Score) {
			return 0;
		}
	}
	int p1Score() {
		return plr1Score;
	}
	int p2Score() {
		return plr2Score;
	}
	void setPlayer1Score(int score) {
		plr1Score = score; 
	}
	void setPlayer2Score(int score) {
		plr2Score = score;
	}
	string p1Name() {
		return plr1Name;
	}
	string p2Name() {
		return plr2Name;
	}
	void setPlayer1Name(int pname) {
		plr1Name = pname; 
	}
	void setPlayer2Name(int pname) {
		plr2Name = pname;
	}

	void clearScreen() {
#ifdef _WIN32
		std::system ( "CLS" );
#else
		// Assume POSIX
		std::system ( "clear" );
#endif

	}
	void sleep(int unit, int time) {
		try {
			switch (unit) {
			case 1:
				this_thread::sleep_for(std::chrono::hours(time));
				break;
			case 2:
				this_thread::sleep_for(std::chrono::minutes(time));
				break;
			case 3:
				this_thread::sleep_for(std::chrono::seconds(time));
				break;
			case 4:
				this_thread::sleep_for(std::chrono::milliseconds(time));
				break;
			case 5:
				this_thread::sleep_for(std::chrono::microseconds(time));
				break;
			case 6:
				this_thread::sleep_for(std::chrono::nanoseconds(time));
				break;
			default:
				throw unit;
				break;
			}
		} catch (int unit) {
			cout << "Unknown value provided: " << unit << endl;
		}
	}
	void deal(int cardsToDeal) {
		topCard = 0;

		plr1Size = 7;
		plr2Size = 7;

		for (int i = 0; i < cardsToDeal; i++)
		{
			player1Hand[i] = cardDeck[topCard];
			topCard++;
			//plr1Size++;

			player2Hand[i] = cardDeck[topCard];
			topCard++;
			//plr2Size++;
		}
	}
	void displayAll(int cardsDealed) {
		cout << "Player 1's Hand - Score: " << plr1Score << endl;
		for (int i=0; i<cardsDealed; i++) {
			cout << player1Hand[i].displayCard() << endl;
		}
		cout << "Player 2's Hand - Score: " << plr2Score << endl;
		for (int i=0; i<cardsDealed; i++) {
			cout << player2Hand[i].displayCard() << endl;
		}
	}
	void displayp1(/*int cardsDealed*/) {
		cout << "Player 1's Hand" << endl;
		for (int i=0; i<plr1Size; i++) {
			cout << player1Hand[i].displayCard() << endl;
		}
	}
	void displayp2(/*int cardsDealed*/) {
		cout << "Player 2's Hand" << endl;
		for (int i=0; i<plr2Size; i++) {
			cout << player2Hand[i].displayCard() << endl;
		}
	}
	int sizep1() {
		return plr1Size;
	}
	int sizep2() {
		return plr2Size;
	}

};
bool keyPress(char keyPressed) {
	if ( GetAsyncKeyState( keyPressed ) & 0x8000 ) {
		return true;
	}
}

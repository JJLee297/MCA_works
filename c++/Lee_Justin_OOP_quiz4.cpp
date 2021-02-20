/*
Program: ECET11 MP1 OOP Quiz 4
Student Name: Justin Lee
Date:  10/2/2020
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class TicTacToe {
private:
	int counter; 
	char board[3][3];
public: 
	TicTacToe();
	void draw();
	void move(char player, int row, int column);
	void status(char player); 
};

TicTacToe::TicTacToe() {
	for (int i = 0; i < 3; i++) {
		for (int k = 0; k < 3; k++) {
			board[i][k] = ' ';
		}
	}
}

void TicTacToe::draw() {
	cout << board[0][0] << " |" << board[0][1] << " |" << board[0][2] << " \n";
	cout << "__|__|__\n";
	cout << board[1][0] << " |" << board[1][1] << " |" << board[1][2] << " \n";
	cout << "__|__|__\n";
	cout << board[2][0] << " |" << board[2][1] << " |" << board[2][2] << " \n\n";
}

void TicTacToe::move(char player, int row, int column) {
	if ((row > 0 && row < 4) && (column > 0 && column < 4) && (board[row - 1][column - 1] == ' ')) {
		board[row - 1][column - 1] = player;
		cout << player << ": " << row << " " << column << endl;
	}
	else {
		cout << player << ": " << row << " " << column << endl;
		cout << "Invalid Entry!\n" << endl; 
	}
}

void TicTacToe::status(char player) {
	counter = 0;
	for (int i = 0; i < 3; i++) {
		if (board[i][0] == player) {
			++counter;
		}
	}
	if (counter == 3) {
		cout << "Player " << player << " wins!\n";
	}
	counter = 0;
	for (int i = 0; i < 3; i++) {
		if (board[i][1] == player) {
			++counter;
		}
	}
	if (counter == 3) {
		cout << "Player " << player << " wins!\n";
	}
	counter = 0; 
	for (int i = 0; i < 3; i++) {
		if (board[i][2] == player) {
			++counter;
		}
	}
	if (counter == 3) {
		cout << "Player " << player << " wins!\n";
	}
	counter = 0; 
	for (int i = 0; i < 3; i++) {
		if (board[0][i] == player) {
			++counter;
		}
	}
	if (counter == 3) {
		cout << "Player " << player << " wins!\n";
	}
	counter = 0;
	for (int i = 0; i < 3; i++) {
		if (board[1][i] == player) {
			++counter;
		}
	}
	if (counter == 3) {
		cout << "Player " << player << " wins!\n";
	}
	counter = 0;
	for (int i = 0; i < 3; i++) {
		if (board[2][i] == player) {
			++counter;
		}
	}
	if (counter == 3) {
		cout << "Player " << player << " wins!\n";
	}
	counter = 0;
	for (int i = 0; i < 3; i++) {
		if (board[i][i] == player) {
			++counter;
		}
	}
	if (counter == 3) {
		cout << "Player " << player << " wins!\n";
	}
	counter = 0;
	for (int i = 0; i < 3; i++) {
		if (board[i][2-i] == player) {
			++counter;
		}
	}
	if (counter == 3) {
		cout << "Player " << player << " wins!\n";
	}
	counter = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] != ' ')
				++counter;
		}
	}
	if (counter == 9) {
		cout << "The game ends in a draw!\n";
	}
}

#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;
enum pieces {BLANK, P1, P2};
pieces board[7][6];

bool checkVer(int column, int row) {
	pieces curr = board[column][row];
	int total = 1;
	int initRow = row;
	pieces piece = board[column][row];
	while ((board[column][--row] == curr) && row>=0 && row<6) {
		total++;
	}
	row = initRow;
	while ((board[column][++row] == curr) && row >= 0 && row < 6) {
		total++;
	}

	return (total >= 4);
}

bool checkHor(int column, int row) {
	pieces curr = board[column][row];
	int total = 1;
	int initColumn = column;
	while ((board[--column][row] == curr) && column >= 0 && column <= 7) {
		total++;
	}
	column = initColumn;
	while ((board[++column][row] == curr) && column >= 0 && column <= 7) {
		total++;
	}
	return (total >= 4);
}

bool checkDiagLeft(int column, int row) {
	pieces curr = board[column][row];
	int total = 1;
	int initColumn = column;
	int initRow = row;
	pieces piece = board[column][row];
	while ((board[--column][++row] == curr) && column >= 0 && column < 7 && row>=0 && row < 6) {
		total++;
	}
	column = initColumn;
	row = initRow;
	while ((board[++column][--row] == curr) && column >= 0 && column < 7 && row>=0 && row < 6) {
		total++;
	}
	return (total >= 4);
}

bool checkDiagRight(int column, int row) {
	pieces curr = board[column][row];
	int total = 1;
	int initColumn = column;
	int initRow = row;
	pieces piece = board[column][row];
	while ((board[++column][++row] == curr) && column >= 0 && column < 7 && row>=0 && row < 6) {
		total++;
	}
	column = initColumn;
	row = initRow;
	while ((board[--column][--row] == curr) && column >= 0 && column < 7 && row>=0 && row < 6) {
		total++;
	}
	return (total >= 4);
}

bool checkOver() {
	bool over = true;
	for (int j = 6; j > 0; j--) {
		for (int i = 0; i < 7; i++) {
			if (board[i][j - 1] == BLANK) {
				over = false;
				break;
			}
		}
	}
	return over;
}

bool checkWin(int column, int row) {
	return(checkHor(column, row) || checkVer(column, row) || checkDiagLeft(column, row) || checkDiagRight(column, row));
}

void display() {
	
	for (int j = 6; j > 0; j--) {
		for (int i = 0; i < 7; i++) {
			if (board[i][j - 1] == BLANK)
				cout << " " << " " << " ";
			else if (board[i][j - 1] == P1)
				cout << " " << "x" << " ";
			else
				cout << " " << "o" << " ";
		}
		cout << "" << endl;
		
	}
	for (int i = 0; i < 7; i++) {
		cout << " " << i + 1 << " ";
	}
	cout << "" << endl;
}


int main(int argc, char** argv) {
	int player = 0;
	pieces piece;

	display();
	
	while (true) {
		cout << "It's player " << (player % 2) + 1<< "'s turn" << endl;

		if ((player % 2) - 1) {
			piece = P1;
		}
		else(piece = P2);

		int input;
		cout << "Pick a column to play" << endl;
		cin >> input;
		input--;
		if (input < 0 || input > 6) {
			cout << "Please input a valid column number" << endl;
			continue;
		}
		int i = 0;
		while (board[input][i] != BLANK && i < 6){
			i++;
		}
		if (i > 5) {
			cout << "Please input a valid column number" << endl;
			continue;
		}

		board[input][i] = piece;
		
		display();
		
		
		
		
		if (checkWin(input, i)) {
			cout << "Player " << (player % 2) + 1<< " wins!" << endl;
			break;
		}
		if (checkOver()) {
			cout << "Tie!" << endl;
			break;
		}
		player++;
	}
	return 0;
}
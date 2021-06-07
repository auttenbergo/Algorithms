#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int BOARD_SIZE = 8;

vector< vector< vector<int> > > solutions;

void fillBoardWithZeros(vector< vector<int> >& board) {
	for (int i = 0; i < BOARD_SIZE; i++) {
		vector<int> subvector;
		for (int j = 0; j < BOARD_SIZE; j++) {
			subvector.push_back(0);
		}
		board.push_back(subvector);
	}
}
void printBoard(vector<vector<int>>& board) {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	cout << "----------------" << endl;
}

bool isValidPlace(vector<vector<int>>& board, int x, int y) {
	/* Horizontal Check */
	for (int i = 0; i < BOARD_SIZE; i++) {
		if (board[x][i] == 1) return false;
	}
	/* Vertical Check */
	for (int i = 0; i < BOARD_SIZE; i++) {
		if (board[i][y] == 1) return false;
	}
	/* Upper left diagonal */
	int dx = x - 1;
	int dy = y - 1;
	while (dx >= 0 && dy >= 0) {
		if (board[dx][dy] == 1) return false;
		dx--;
		dy--;
	}
	/* Upper right diagonal */
	dx = x - 1;
	dy = y + 1;
	while (dx >= 0 && dy < BOARD_SIZE) {
		if (board[dx][dy] == 1) return false;
		dx--;
		dy++;
	}
	/* Lower left diagonal */
	dx = x + 1;
	dy = y - 1;
	while (dx < BOARD_SIZE && dy >= 0) {
		if (board[dx][dy] == 1) return false;
		dx++;
		dy--;
	}
	/* Lower right diagonal */
	dx = x + 1;
	dy = y + 1;
	while (dx < BOARD_SIZE && dy < BOARD_SIZE) {
		if (board[dx][dy] == 1) return false;
		dx++;
		dy++;
	}
	return true;
}

void eightQueenSolver(vector<vector<int>>& board, int rowIndex) {
	if (rowIndex >= BOARD_SIZE) {
		if (count(solutions.begin(), solutions.end(), board) == 0)
			solutions.push_back(board);
		return;
	}
	for (int i = 0; i < BOARD_SIZE; i++) {
		if (!isValidPlace(board, rowIndex, i))
			continue;
		board[rowIndex][i] = 1;
		eightQueenSolver(board, rowIndex + 1);
		board[rowIndex][i] = 0;
	}
}

int main()
{
	vector<vector<int>> board;
	fillBoardWithZeros(board);
	eightQueenSolver(board, 0);
	
	cout << "8 Queen problem has " << solutions.size() << " distinct solutions" << endl;
	for (int i = 0; i < solutions.size(); i++) {
		cout << "Solution " << i + 1 << " :" << endl;
		printBoard(solutions[i]);
	}

	return 0;
}

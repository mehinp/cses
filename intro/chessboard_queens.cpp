#include <bits/stdc++.h>
using namespace std;

// key insight: this is a recursive backtracking problem
// we will place a queen at a certain spot, mark that row/col/diagonal as occupied and continue down the board
// need to think about how to compute the diagonals. there are 2*n - 1 main and 2*n - 1 off diagonals (15 for 8x8 board).


vector<bool> mainDiag(15);
vector<bool> offDiag(15);
vector<bool> cols(8);
int totalWays = 0;

void solve(int row, vector<vector<char>> &board) {
    if (row == 8) {
        totalWays++;
        return;
    }

    for (int col = 0; col < 8; col++) {
        if (!offDiag[row + col] && !mainDiag[7 - col + row] && !cols[col] && board[row][col] != '*') {
            offDiag[row + col] = mainDiag[7 - col + row] = cols[col] = true;
            solve(row+1, board);
            offDiag[row + col] = mainDiag[7 - col + row] = cols[col] = false;
        }
    }
}

int main() {
    vector<vector<char>> board(8, vector<char>(8));

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> board[i][j];
        }   
    }
    solve(0, board);
    cout << totalWays << '\n';
}
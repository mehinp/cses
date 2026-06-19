#include <bits/stdc++.h>
using namespace std;

// key insight: we can run BFS. instead of working from a cell to the top left, we start at the top left and work to neighbor cells
// need to consider each "layer" of knights simultaneously so BFS is optimal here

void add(queue<vector<int>> &vis, vector<vector<int>> &board, int n, int row, int col, int ways) {
    if (row < 0 || col < 0 || row >= n || col >= n || board[row][col] != -1) {
        return;
    }
    board[row][col] = ways;
    vis.push({row, col, ways});
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, -1));
    board[0][0] = 0;
    queue<vector<int>> vis;
    vis.push({0, 0, 0});

    while(!vis.empty()) {
        int x = vis.front()[0];
        int y = vis.front()[1];
        int ways = vis.front()[2];
        vis.pop();
        for (int row = -2; row <= 2; row++) {
            for (int col = -2; col <= 2; col++) {
                if (abs(row) == abs(col) || row == 0 || col == 0) {
                    continue;
                }
                add(vis, board, n, x + row, y + col, ways+1);
            }   
        }
    }

    for (vector<int> v : board) {
        for (int val : v) {
            cout << val << ' ';
        }
        cout << '\n';
    }
}
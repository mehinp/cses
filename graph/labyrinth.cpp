#include <bits/stdc++.h>
using namespace std;

// We need the shortest path. No weights, so we can run BFS.


int main() { 
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<char> dirMap = {'D', 'U', 'R', 'L'};
    vector<vector<char>> moves(n, vector<char>(m));
    bool found = false;
    int bRow = 0;
    int bCol = 0;
    int aRow = 0;
    int aCol = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') {
                queue<pair<int, int>> frontier;
                frontier.emplace(i, j);
                aRow = i;
                aCol = j;
                while (!frontier.empty()) {
                    auto [row, col] = frontier.front();
                    frontier.pop();
                    if (grid[row][col] == 'B') {
                        found = true;
                        bRow = row;
                        bCol = col;
                        break;
                    }
                    if (grid[row][col] == 'V') continue;
                    grid[row][col] = 'V';

                    for (int k = 0; k < 4; k++) {
                        int nextRow = row + dirs[k].first;
                        int nextCol = col + dirs[k].second;
                        if (nextRow < 0 || nextRow >= n || nextCol < 0 || nextCol >= m 
                            || grid[nextRow][nextCol] == '#' || grid[nextRow][nextCol] == 'V') {
                            continue;
                        }
                        frontier.emplace(nextRow, nextCol);
                        moves[nextRow][nextCol] = dirMap[k];
                    } 
                }
                break;
            }
        }
    }

    if (!found) {
        cout << "NO";
    } else {
        stack<char> path;
        int row = bRow;
        int col = bCol;
        while (row != aRow || col != aCol) {
            char move = moves[row][col];
            path.push(move);
            switch (move) {
                case 'D':
                    row--;
                    break;
                case 'U':
                    row++;
                    break;
                case 'L':
                    col++;
                    break;
                case 'R':
                    col--;
                    break;
            }
        }
        cout << "YES\n" << path.size() << '\n';
        while (!path.empty()) {
            cout << path.top();
            path.pop();
        }
    }
    cout << '\n';

}
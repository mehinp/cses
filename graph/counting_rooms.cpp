#include <bits/stdc++.h>
using namespace std;

// This is similar to the islands problem. When we encounter a non-visited cell, we can run dfs on that cell.
// Once we encounter a wall, return. The count is the number of times we run call dfs in the main function.

void dfs(vector<string>& grid, int row, int col) {
    if (row < 0 || row >= int(grid.size()) || col < 0 || col >= int(grid[0].length())) {
        return;
    }
    if (grid[row][col] == 'V' || grid[row][col] == '#') {
        return;
    }
    grid[row][col] = 'V';
    dfs(grid, row + 1, col);
    dfs(grid, row - 1, col);
    dfs(grid, row, col + 1);
    dfs(grid, row, col - 1);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] != 'V' && grid[i][j] == '.') {
                dfs(grid, i, j);
                ++count;
            }
        }
    }
    cout << count << '\n';
}
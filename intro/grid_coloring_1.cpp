#include <bits/stdc++.h>
using namespace std;

/*
build the answer in order, there will always be a valid answer because if you consider whatever
is above and to the left, you are still left with two choices, so you can just add one of those two choices
hence, in the worst case, you are still left with one choice of what to change it to
*/

int main() { 
    int m, n;
    cin >> m >> n;
    vector<string> grid(m);

    for (int i = 0; i < m; i++) {
        cin >> grid[i];
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            set<char> already;
            if (j > 0) {
                already.insert(grid[i][j-1]);
            }
            if (i > 0) {
                already.insert(grid[i-1][j]);
            }
            already.insert(grid[i][j]);
            for (int c = 'A'; c <= 'D'; c++) {
                if (!already.count(c)) {
                    grid[i][j] = c;
                }
            }
        }
    }

    for (string s : grid) {
        cout << s << '\n';
    }    
}
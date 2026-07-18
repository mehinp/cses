#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 5;
void solve() {
    // create the sparse table
    int n, q;
    cin >> n >> q;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    vector<vector<int>> table(n, vector<int>(20, INF));
    vector<int> powers(n + 1);
    for (int i = 0; i < n; i++) {
        table[i][0] = x[i];
    }

    int j = 0;
    for (int i = 0; i <= n; i++) {
        int exp = 1 << (j + 1);
        if (exp <= i) {
            j++;
        }
        powers[i] = j;
    }

    for (int j = 1; j < 20; j++) {
        for (int i = 0; i + (1 << j) - 1 < n; i++) {
            table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
        }
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        int p = powers[b - a + 1];
        cout << min(table[a][p], table[b - (1 << p) + 1][p]) << '\n';
    }
}

int main() {
    solve();
}
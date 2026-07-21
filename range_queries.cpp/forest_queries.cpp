#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> pref(n + 1, vector<int>(n + 1));
    vector<string> forest(n);
    for (int i = 0; i < n; i++) {
        cin >> forest[i];
    }

    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= n; y++) {
            pref[x][y] = pref[x - 1][y] + pref[x][y - 1] - pref[x - 1][y - 1] + (forest[x - 1][y - 1] == '*');
        }
    }

    for (int i = 0; i < q; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int ans = pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] + pref[x1 - 1][y1 - 1];
        cout << ans << '\n';
    }
}
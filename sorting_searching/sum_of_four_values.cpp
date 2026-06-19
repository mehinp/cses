#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<int, vector<pair<int, int>>> seen;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = a[i] + a[j];
            int target = x - sum;
            if (seen.contains(target)) {
                for (auto [p, q] : seen[target]) {
                    if (i != p && i != q && j != p && j != q) {
                        cout << i + 1 << ' ' << j + 1 << ' ' << p + 1 << ' ' << q + 1;
                        return 0;
                    }
                }
            }
        }
        for (int j = i + 1; j < n; j++) {
            seen[a[i] + a[j]].emplace_back(i, j);
        }
    }
    cout << "IMPOSSIBLE" << '\n';
}
#include <bits/stdc++.h>
using namespace std;

/*
Sort the people and the apartment sizes. Maintain two pointers.
*/

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int j = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        while (j < m && a[i] - b[j] > k) j++;
        if (j == m) break;
        if (abs(a[i] - b[j]) <= k) {
            ans++;
            j++;
        }
    }
    cout << ans << '\n';
}   
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = {x, i};
    }
    sort(a.begin(), a.end());
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (a[i].second < a[i - 1].second) ans++;
    }
    cout << ans << '\n';
}
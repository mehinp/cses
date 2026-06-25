#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].second >> a[i].first;
    }
    sort(a.begin(), a.end());
    multiset<int> ms;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto it = ms.upper_bound(a[i].second);
        if (it != ms.begin()) {
            ans++;
            ms.erase(--it);
            ms.insert(a[i].first);
        } else if (int(ms.size()) < k) {
            ans++;
            ms.insert(a[i].first);
        }
    }
    cout << ans << '\n';
}
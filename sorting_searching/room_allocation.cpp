#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<array<int, 3>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i;
    }
    sort(a.begin(), a.end());
    multiset<pair<int, int>> ms;
    int roomCount = 0;
    vector<int> ans(n);

    for (int i = 0; i < n; i++) {
        auto it = ms.lower_bound({a[i][0], -1});
        if (it == ms.begin()) {
            roomCount++;
            ms.emplace(a[i][1], roomCount);
            ans[a[i][2]] = roomCount;
        } else {
            it--;
            ans[a[i][2]] = (*it).second;
            ms.erase(it);
            ms.emplace(a[i][1], ans[a[i][2]]);
        }
    }

    cout << roomCount << '\n';
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}
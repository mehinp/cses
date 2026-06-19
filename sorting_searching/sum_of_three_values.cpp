#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        int target = x - a[i].first;
        int l = i + 1;
        int r = n - 1;
        while (l < r) {
            if (a[l].first + a[r].first == target) {
                cout << a[l].second + 1 << ' ' << a[r].second + 1 << ' ' << a[i].second + 1 << '\n';
                return 0;
            } else if (a[l].first + a[r].first > target) {
                r--;
            } else {
                l++;
            }
        }
    }
    cout << "IMPOSSIBLE" << '\n';
}
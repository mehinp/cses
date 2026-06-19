#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto check = [&](long long time) -> bool {
        long long made = 0;
        for (int i = 0; i < n; i++) {
            made += time / a[i];
        }
        if (made >= t) {
            return true;
        }
        return false;
    };

    long long l = 1;
    long long r = 1LL * *min_element(a.begin(), a.end()) * t;

    long long ans = -1;
    while (l <= r) {
        long long mid = l + (r - l) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';

}
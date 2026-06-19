#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    long long l = 0;
    long long r = 0;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        a[i] = x;
        l = max(l, x);
        r += x;
    }


    auto check = [&](long long mid) -> bool {
        int subarrays = 1;
        long long curr = 0;
        for (int val : a) {
            if (curr + val > mid) {
                subarrays++;
                curr = val;
            } else {
                curr += val;
            }
        }   
        if (subarrays > k) return false;
        return true;
    };

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
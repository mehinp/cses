#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int x, a, b, c;
    cin >> x >> a >> b >> c;
    vector<long long> v(n);
    v[0] = x;
    for (int i = 1; i < n; i++) {
        v[i] = (a * v[i - 1] + b) % c;
    }

    vector<long long> ans;
    int l = 0;
    long long xr = 0;
    for (int i = 0; i < n; i++) {
        xr ^= v[i];
        if (i - l + 1 == k) {
            ans.push_back(xr);
            xr ^= v[l++];
        }
    }

    long long res = 0;
    for (long long val : ans) {
        res ^= val;
    }
    cout << res << '\n';
}   

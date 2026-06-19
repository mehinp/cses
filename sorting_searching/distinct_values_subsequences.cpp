#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int main() {
    int n;
    cin >> n;
    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }

    long long ans = 1;
    for (auto &p : freq) {
        ans = (ans * (p.second + 1)) % MOD;
    }
    cout << ans - 1 << '\n';
}

    
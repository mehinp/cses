#include <bits/stdc++.h>
using namespace std;

// there are 2^n subsets. this is trivial
// key is learning how to MOD as you go --> 2^(1e6) directly will result in overflow


const int MOD = 1e9 + 7;
int main() {
    int n;
    cin >> n;

    int ans = 1;

    while (n--) {
        ans = (2 * ans) % MOD;
    }

    cout << ans % MOD << '\n';
}
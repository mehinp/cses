#include <bits/stdc++.h>
using namespace std;


const int MOD = 1e9 + 7;
int dp[1'000'000][2];
int main() {
    dp[0][0] = 1;
    dp[0][1] = 1;

    for (int i = 0; i < 1e6 - 1; i++) {
        dp[i + 1][1] = (dp[i + 1][1] + 4LL * dp[i][1]) % MOD;
        dp[i + 1][1] = (dp[i + 1][1] + dp[i][0]) % MOD;
        dp[i + 1][0] = (dp[i + 1][0] + dp[i][1]) % MOD;
        dp[i + 1][0] = (dp[i + 1][0] + 2LL * dp[i][0]) % MOD;
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << (dp[n - 1][1] + dp[n - 1][0]) % MOD << '\n';
    }
}
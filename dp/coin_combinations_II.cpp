#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int main() {
    int n, x;
    cin >> n >> x;

    vector<int> dp(x + 1);
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < x; j++) {
            if (coins[i] + j > x) continue;
            dp[coins[i] + j] = (dp[coins[i] + j] + dp[j]) % MOD; 
        }
    }

    cout << dp[x] << '\n';
}
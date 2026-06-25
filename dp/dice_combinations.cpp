#include <bits/stdc++.h>
using namespace std;

// dp[i] = number of ways to get to sum i
// dp[i] += dp[i - j] --> add number of ways to get to i - j

int main() {
    int n;
    cin >> n;
    const int MOD = 1e9 + 7;
    vector<int> dp(n + 1);
    dp[0] = 1;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i - j < 0) continue;
            dp[i] = (dp[i] + dp[i - j]) % MOD;
        }   
    }
    cout << dp[n] << '\n';
}
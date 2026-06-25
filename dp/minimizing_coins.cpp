#include <bits/stdc++.h>
using namespace std;

// dp[i] = minimum possible coins used to get to sum of i

int main() {
    const int INF = 1e9 + 5;
    int n, x;
    cin >> n >> x;
    vector<int> dp(x + 1, INF);
    vector<int> coins(n);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }   
        
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i - coins[j] < 0) continue;
            dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        }
    }
    cout << (dp[x] == INF ? -1 : dp[x]) << '\n';
}
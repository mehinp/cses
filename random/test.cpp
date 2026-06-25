#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> dp(29);
    dp[0] = 2;
    dp[1] = 3;
    for (int i = 2; i < 29; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    } 
    cout << dp[28] << ' ';
    cout << 1 - (double) dp[28] / (1 << 29);
}
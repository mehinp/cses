#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<double> dp(26);
    for (int i = 20; i <= 25; i++) {
        dp[i] = i;
    }

    for (int i = 19; i >= 0; i--) {
        for (int j = 2; j <= 6; j++) {
            dp[i] = (dp[i] + 1.0 / 6 * dp[i + j]);
        }
    }
    cout << dp[0];
}
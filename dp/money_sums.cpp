#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> coins(n);
    int x = 0;
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
        x += coins[i];
    }
    vector<bool> dp(x + 1);
    dp[0] = true;
    for (int coin : coins) {
        for (int j = x - 1; j >= 0; j--) {
            if (coin + j > x || !dp[j]) continue;
            dp[coin + j] = true;
        }
    }

    cout << accumulate(dp.begin(), dp.end(), 0) - 1 << '\n';
    for (int i = 1; i <= x; i++) {
        if (dp[i]) {
            cout << i << ' ';
        }
    }
    cout << '\n';
}
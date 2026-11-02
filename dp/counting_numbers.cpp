#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(ll x) {
    string num = to_string(x);
    int len = num.length();
    vector<vector<vector<ll>>> dp(len, vector<vector<ll>>(11, vector<ll>(2)));

    for (int i = 1; i <= 9; i++) {
        if (i > num[0] - '0') continue;
        if (i == num[0] - '0') {
            dp[0][i][1] = 1;
            continue;
        }
        dp[0][i][0] = 1;
    }
    dp[0][10][0] = 1;
    
    for (int i = 1; i < len; i++) {
        for (int j = 0; j <= 10; j++) {
            for (int k = 0; k <= 10; k++) {
                if (j == 10) {
                    if (k == 10) dp[i][j][0] += dp[i - 1][k][0];
                    continue;
                }
                if (k == 10 && j == 0) continue;
                if (j == k) continue;
                if (j == num[i] - '0') {
                    dp[i][j][1] += dp[i - 1][k][1];
                }
                dp[i][j][0] += dp[i - 1][k][0];
                if (j < num[i] - '0') {
                    dp[i][j][0] += dp[i - 1][k][1];
                }
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i <= 10; i++) {
        ans += dp[len - 1][i][0] + dp[len - 1][i][1];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll a, b;
    cin >> a >> b;


    cout << solve(b) - (a == 0 ? 0 : solve(a - 1)) << '\n';
}
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<long long>> dp(n, vector<long long>(m + 1));
    if (a[0] == 0) {
        for (int i = 1; i <= m; i++) {
            dp[0][i] = 1;
        }
    } else {
        dp[0][a[0]] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] != 0 && j != a[i]) {
                continue;
            } else {
                for (int k = -1; k <= 1; k++) {
                    if (j + k <= 0 || j + k > m) continue;
                    dp[i][j] = (dp[i][j] + dp[i - 1][j + k]) % MOD;
                }
            }
        }
    }

    long long ans = 0;
    for (int j = 1; j <= m; j++) {
        ans = (ans + dp[n - 1][j]) % MOD;
    }
    cout << ans << '\n';
}
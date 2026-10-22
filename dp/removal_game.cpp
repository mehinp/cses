#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }


    vector<vector<long long>> dp(n, vector<long long>(n));

    for (int len = 1; len <= n; len++) {
        for (int l = 0; l + len - 1 < n; l++) {
            bool first = (len % 2) == (n % 2);
            int r = l + len - 1;
            if (len == 1) {
                if (first) dp[l][r] = a[l];
                continue;
            }

            if (first) {
                dp[l][r] = max(a[l] + dp[l + 1][r], a[r] + dp[l][r - 1]);
            } else {
                dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]);
            }
        }
    }

    cout << dp[0][n - 1] << '\n';
}
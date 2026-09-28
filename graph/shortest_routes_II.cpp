#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 2e15 + 5;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, INF));

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dp[a][b] = min(dp[a][b], 1LL * c);
        dp[b][a] = min(dp[b][a], 1LL * c);
    }

    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    while (q--) {
        int a, b;
        cin >> a >> b;  
        if (dp[a][b] == INF) {
            cout << -1 << '\n';
        } else {
            cout << dp[a][b] << '\n';
        }
    }
}
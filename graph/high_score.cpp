#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u;
    int v;
    int w;
};

using ll = long long;
const ll INF = -2e15 - 5;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, INF));

    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.emplace_back(a, b, c);
    }

    dp[0][1] = 1;
   
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = dp[i - 1][j];
        }
        for (const auto&[u, v, w] : edges) {
            if (dp[i - 1][u] == INF) continue;
            dp[i][v] = max(dp[i][v], dp[i - 1][u] + w);
        }
    }

    
    vector<bool> vis(n + 1);
    auto dfs = [&](auto&& self, int u) -> bool {
        vis[u] = 1;
        if (dp[n][u] != dp[n - 1][u]) return false;
        for (const auto&[node, v, w] : edges) {
            if (v == u) {
                if (vis[node]) continue;
                if (!self(self, node)) return false;
            }
        }
        return true;
    };

    if (!dfs(dfs, n)) {
        cout << -1 << '\n';
    } else {
        cout << dp[n - 1][n] << '\n';
    }
}
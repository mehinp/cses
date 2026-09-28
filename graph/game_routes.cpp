#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    vector<int> path;
    vector<bool> vis(n + 1);
    auto dfs = [&](auto&& self, int u) -> void {
        vis[u] = 1;
        for (int neigh : adj[u]) {
            if (!vis[neigh]) {
                self(self, neigh);
            }
        }
        path.push_back(u);
    };

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(dfs, i);
    }

    assert(int(path.size()) == n);
    reverse(path.begin(), path.end());

    int j = 0;
    for (int i = 0; i < n; i++) {
        if (path[i] == 1) j = i;
    }

    vector<int> dp(n + 1);
    dp[1] = 1;
    for (; j < n; j++) {
        for (int neigh : adj[path[j]]) {
            dp[neigh] = (dp[neigh] + dp[path[j]]) % MOD;
        }
    }
    cout << dp[n] << '\n';
}   
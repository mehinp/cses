#include <bits/stdc++.h>
using namespace std;

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

    vector<bool> vis(n + 1);
    vector<int> path;
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

    int j = n + 1;
    for (int i = 0; i < n; i++) {
        if (path[i] == 1) {
            j = i;
        }
    } 

    assert(j != n + 1);

    vector<int> dp(n + 1, -1);
    vector<int> p(n + 1);
    dp[1] = 0;

    for (; j < n; j++) {
        for (int neigh : adj[path[j]]) {
            if (1 + dp[path[j]] > dp[neigh]) {
                p[neigh] = path[j];
                dp[neigh] = 1 + dp[path[j]];
            }
        }
    }

    if (dp[n] == -1) {
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }

    vector<int> ans;
    ans.push_back(n);
    int par = n;
    while (par != 1) {
        ans.push_back(p[par]);
        par = p[par];
    }

    reverse(ans.begin(), ans.end());

    cout << int(ans.size()) << '\n';
    for (int x : ans) {
        cout << x << ' ';
    }
}
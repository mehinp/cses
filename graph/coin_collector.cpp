#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<vector<int>> rev(n + 1);
    vector<ll> coins(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> coins[i];
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        rev[b].push_back(a);
    }

    int t = 0;
    vector<int> exit(n);
    vector<bool> vis(n + 1);
    auto dfs1 = [&](auto&& self, int u) -> void {
        vis[u] = 1;
        for (int neigh : adj[u]) {
            if (!vis[neigh]) {
                self(self, neigh);
            }
        }   
        exit[t] = u;
        t += 1;
    };

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs1(dfs1, i);
        }
    }

    fill(vis.begin(), vis.end(), 0);
    vector<int> king(n + 1);
    vector<vector<int>> scc;
    vector<ll> dp(n + 1);

    auto dfs2 = [&](auto&& self, int u, const int p, vector<int>& temp) -> void {
        king[u] = p;
        vis[u] = 1;
        dp[p] += coins[u];
        temp.push_back(u);
        for (int neigh : rev[u]) {
            if (!vis[neigh]) {
                self(self, neigh, p, temp);
            }
        }
    };  

    int cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (!vis[exit[i]]) {
            cnt += 1;
            vector<int> temp;
            dfs2(dfs2, exit[i], cnt, temp);
            scc.push_back(temp);
        }
    }

    dp.resize(cnt + 1);
    vector<vector<int>> new_adj(n + 1);
    for (auto& v : scc) {
        for (int x : v) {
            for (int neigh : adj[x]) {
                if (king[x] != king[neigh]) {
                    new_adj[king[x]].push_back(king[neigh]);
                }
            }
        }
    }



    vis.assign(cnt + 1, 0);
    vector<int> path;
    auto dfs = [&](auto&& self, int u) -> void {
        vis[u] = 1;
        for (int neigh : new_adj[u]) {
            if (!vis[neigh]) {
                self(self, neigh);
            }
        }
        path.push_back(u);
    };

    for (int i = 1; i <= cnt; i++) {
        if (!vis[i]) dfs(dfs, i);
    }   

    assert(int(path.size()) == cnt);
    reverse(path.begin(), path.end());
    auto prev = dp;

    for (int i = 1; i <= cnt; i++) {
        for (int neigh : new_adj[i]) {
            dp[neigh] = max(dp[neigh], dp[i] + prev[neigh]);
        }
    }

    cout << *max_element(dp.begin(), dp.end());
}

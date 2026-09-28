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

    vector<int> path;
    vector<int> vis(n + 1);
    auto dfs = [&](auto&& self, int u) -> bool {
        vis[u] = 1;
        for (int neigh : adj[u]) {
            if (vis[neigh] == 1) return false;
            if (!vis[neigh]) {
                if (!self(self, neigh)) return false;
            }
        }
        vis[u] = 2;
        path.push_back(u);
        return true;
    };

    for (int i = 1; i <= n; i++) {
        if (!vis[i] && !dfs(dfs, i)) {
            cout << "IMPOSSIBLE" << '\n';
            return 0;
        }
    }

    reverse(path.begin(), path.end());
    for (int x : path) {
        cout << x << ' ';
    }
    cout << '\n';
}
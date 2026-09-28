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

    vector<int> vis(n + 1);
    vector<int> parent(n + 1);
    vector<int> path;
    auto dfs = [&](auto&& self, int u) -> bool {
        vis[u] = 1;
        for (int neigh : adj[u]) {
            if (vis[neigh] == 1) {
                int p = u;
                path.push_back(u);
                while (p != neigh) {
                    p = parent[p];
                    path.push_back(p);
                }
                path.push_back(u);
                return true;
            } else if (!vis[neigh]) {
                parent[neigh] = u;
                if (self(self, neigh)) {

                    return true;
                }
            }
        }
        vis[u] = 2;
        return false;
    };

    for (int i = 1; i <= n; i++) {  
        if (!vis[i] && dfs(dfs, i)) {
            cout << int(path.size()) << '\n';
            reverse(path.begin(), path.end());
            for (int x : path) {
                cout << x << ' ';
            }
            cout << '\n';
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << '\n';
}
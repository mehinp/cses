#include <bits/stdc++.h>
using namespace std;

// Determine if there is a cycle

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    set<int> vis;
    int start = -1;
    auto dfs = [&](auto&& self, int p, int u, vector<int>& path) -> bool {
        vis.insert(u);
        path.push_back(u);
        for (int neigh : adj[u]) {
            if (!vis.contains(neigh)) {
                if (self(self, u, neigh, path)) {
                    return true;
                }
            } else if (neigh != p) {
                start = neigh;
                return true;
            }
        }
        path.pop_back();
        return false;
    };  

    for (int i = 1; i <= n; i++) {
        vector<int> path;
        if (!vis.contains(i) && dfs(dfs, -1, i, path)) {
            vector<int> ans;
            bool print = false;
            for (int node : path) {
                if (node == start) {
                    print = true;
                }
                if (print) ans.push_back(node);
            }
            ans.push_back(start);
            cout << ans.size() << '\n';
            for (int node : ans) {
                cout << node << ' ';
            }
            cout << '\n';
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << '\n';
}
#include <bits/stdc++.h>
using namespace std;
// Run DFS to determine components. If there is an odd cycle, it is impossible. Otherwise, just alternate each vertex.
// This is similar to the idea of graph coloring. We are checking if the graph is bipartite. 


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> groups(n + 1);
    vector<bool> vis(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    auto dfs = [&](auto &&self, int pupil, int groupNum) -> bool {
        vis[pupil] = true;
        groups[pupil] = groupNum;
        for (int v : adj[pupil]) {
            if (!vis[v]) {
                if (!self(self, v, groupNum ^ 3)) {
                    return false;
                }
            } else {
                if (groups[v] == groups[pupil]) {
                    return false;
                }
            }
        }
        return true;
    };

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            bool res = dfs(dfs, i, 1);
            if (!res) {
                cout << "IMPOSSIBLE" << '\n';
                return 0;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << groups[i] << ' ';
    }
    cout << '\n';
}
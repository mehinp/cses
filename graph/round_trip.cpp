#include <bits/stdc++.h>
using namespace std;

// We just need to determine if there is a cycle in the graph. If there is, there is a solution.
// We need to maintain the parents of each node as we go to help us print out the solution (if there is one).
// Once we determine that there is a cycle, we can work backwards from the node at which we determined there is a cycle.

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> vis(n + 1);
    vector<int> path(n + 1);
    vector<int> parents(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int end = -1;

    auto dfs = [&](auto &&self, int v, int p) -> void {
        vis[v] = true;
        parents[v] = p;
        for (int neigh : adj[v]) {
            if (!vis[neigh]) {
                self(self, neigh, v);
                
            } else {
                if (neigh != p) {
                    parents[neigh] = v;
                    end = neigh;
                    return;
                }
            }
        }
    };

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(dfs, i, -1);
            vector<int> path;
            if (end != -1) {
                int v = end;
                path.push_back(v);
                while (v != i) {
                    path.push_back(parents[v]);
                    v = parents[v];
                }
                cout << path.size() << '\n';
                for (int vt : path) {
                    cout << vt << ' ';
                }
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE" << '\n';
}
#include <bits/stdc++.h>
using namespace std;

// We can determine the number of distinct components in the graph using DFS.
// For each component, maintain all the vertices in that component. 
// The roads that we need to build will be between two vertices of our choosing in each component.
// We need to build distinct components - 1 new roads.

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<bool> vis(n + 1, false);
    vector<int> components;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

  

    auto dfs = [&](auto &&self, int city) -> void {
        vis[city] = true;
        for (int v : adj[city]) {
            if (!vis[v]) {
                self(self, v);
            }
        }
    };

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            components.push_back(i);
            dfs(dfs, i);
        }
    }

    int distinct = components.size();
    cout << distinct - 1 << '\n';
    
    for (int i = 0; i < distinct - 1; i++) {
        cout << components[i] << ' ' << components[i + 1] << '\n';
    }
}
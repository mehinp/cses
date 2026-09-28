#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<vector<int>> rev(n + 1);
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

    dfs1(dfs1, 1);

    fill(vis.begin(), vis.end(), 0);
    auto dfs2 = [&](auto&& self, int u) -> void {
        vis[u] = 1;
        for (int neigh : rev[u]) {
            if (!vis[neigh]) {
                self(self, neigh);
            }
        }
    };  

    dfs2(dfs2, exit[n - 1]);

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cout << "NO" << '\n';
            cout << i << ' ' << exit[n - 1] << '\n';
            return 0;
        } 
    }
    cout << "YES" << '\n';
}
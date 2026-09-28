#include <bits/stdc++.h>
using namespace std;
 
const int INF = 1e9 + 5;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
 
    int n;
    cin >> n;
    vector<int> adj(n + 1);
    vector<vector<int>> rev(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> adj[i];
        rev[adj[i]].push_back(i);
    }
 
    vector<vector<int>> cycles;
    vector<int> vis(n + 1);
    vector<int> parent(n + 1);
    auto dfs = [&](auto&& self, int u) -> void {
        vis[u] = 1;
        if (vis[adj[u]] == 1) {
            vector<int> temp;
            temp.push_back(u);
            int p = u;
            while (p != adj[u]) {
                p = parent[p];
                temp.push_back(p);
            }
            reverse(temp.begin(), temp.end());
            cycles.push_back(temp);
        } else if (!vis[adj[u]]) {
            parent[adj[u]] = u;
            self(self, adj[u]);
        }
        vis[u] = 2;
    };
 
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(dfs, i);
    }
 
    vector<int> dist(n + 1, INF);
 
    auto bfs = [&](queue<pair<int, int>>& q) -> void {
        while (!q.empty()) {
            auto [d, u] = q.front();
            q.pop();
 
            for (int neigh : rev[u]) {
                if (dist[neigh] != INF) {
                    continue;
                }
                dist[neigh] = d + 1;
                q.emplace(d + 1, neigh);
            }
        }   
    };
 
    for (auto& v : cycles) {
        queue<pair<int, int>> q;
        for (int x : v) {
            q.emplace(int(v.size()), x);
            dist[x] = int(v.size());
        }
        bfs(q);
    }
 
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << ' ';
    }
    cout << '\n';
}

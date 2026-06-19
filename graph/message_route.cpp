#include <bits/stdc++.h>
using namespace std;
// Build the adjacency list and use BFS. Maintain path as we go.

// Learned that you need to vertex as visited as soon as encounter it if you are keeping track of path. 
// Otherwise, you might override the optimal path.

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> path(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }


    queue<int> frontier;
    vector<bool> vis(n + 1);
    vis[1] = true;
    frontier.push(1);
    bool found = false;
    while (!frontier.empty()) {
        int v = frontier.front();
        frontier.pop();
        if (v == n) {
            found = true;
            break;
        }

        for (int neigh : adj[v]) {
            if (!vis[neigh]) {
                vis[neigh] = true;
                frontier.push(neigh);
                path[neigh] = v;
            }
        }
    }

    if (!found) {
        cout << "IMPOSSIBLE";
    } else {
        stack<int> route;
        int idx = n;
        route.push(idx);
        while (idx != 1) {
            route.push(path[idx]);
            idx = path[idx];
        }
        cout << route.size() << '\n';
        while (!route.empty()) {
            cout << route.top() << ' ';
            route.pop();
        }
    }
    cout << '\n';
}   
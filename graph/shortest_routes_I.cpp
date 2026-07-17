#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
    }

    vector<long long> ans(n + 1, -1);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.emplace(0, 1);

    while (!pq.empty()) {
        auto [weight, node] = pq.top();
        pq.pop();
        if (ans[node] != -1) continue;
        ans[node] = weight;
        for (auto& neigh : adj[node]) {
            if (ans[neigh.first] == -1) {
                pq.emplace(neigh.second + weight, neigh.first);
            }
        }
    }   
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}
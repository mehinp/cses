#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 2e15 + 5;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> adj(n + 1);
    vector<vector<pair<int, ll>>> rev(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
        rev[b].emplace_back(a, c);
    }

    auto dij = [&](vector<vector<pair<int, ll>>>& ad, int start) -> vector<ll> {
        vector<ll> dist(n + 1, INF);
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        dist[start] = 0;
        pq.emplace(0, start);
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (dist[u] < d) continue;
            for (const auto& [neigh, cost] : ad[u]) {
                if (dist[neigh] <= cost + d) continue;
                dist[neigh] = cost + d;
                pq.emplace(cost + d, neigh);
            }
        }
        return dist;
    };
    
    auto v1 = dij(adj, 1);
    auto v2 = dij(rev, n);
    
    ll ans = INF;
    for (int i = 1; i <= n; i++) {
        for (const auto& [neigh, cost] : adj[i]) {
            ans = min(ans, v1[i] + cost / 2 + v2[neigh]);
        }
    }
    cout << ans << '\n';
}   
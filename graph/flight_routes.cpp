#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, ll>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    vector<priority_queue<ll>> dist(n + 1);
    dist[1].push(0);
    pq.emplace(0, 1);

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u].top()) continue;

        for (auto& neigh : adj[u]) {
            ll new_dist = neigh.second + d;
            bool add = false;
            if (int(dist[neigh.first].size()) < k) {
                dist[neigh.first].push(new_dist);
                add = 1;
            } else if (new_dist < dist[neigh.first].top()) {
                dist[neigh.first].pop();
                dist[neigh.first].push(new_dist);
                add = 1;
            }

            if (add) {
                pq.emplace(new_dist, neigh.first);
            }
        }
    }

    auto& res = dist[n];
    assert(int(res.size()) >= k);

    vector<ll> ans;
    while (!res.empty()) {
        ans.push_back(res.top());
        res.pop();
    }

    reverse(ans.begin(), ans.end());
    for (int i = 0; i < k; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}
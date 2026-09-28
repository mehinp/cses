#include <bits/stdc++.h>
using namespace std;


using ll = long long;
constexpr int MOD = 1e9 + 7;
const ll INF = 2e15 + 5;

struct Info {
    ll price;
    ll ways;
    ll min_num;
    ll max_num;
    void print() {
        cout << price << ' ' << ways << ' ' << min_num << ' ' << max_num << '\n';
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    int n, m;
    cin >> n >> m;  
    vector<vector<pair<int, ll>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
    }

    vector<Info> dist(n + 1);
    for (int i = 1; i <= n; i++) {
        dist[i].price = INF;
        dist[i].ways = 0;
        dist[i].max_num = 0;
        dist[i].min_num = INF;
    } 

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.emplace(0, 1);
    dist[1] = {0, 1, 0, 0};

    while (!pq.empty()) {
        auto [p, u] = pq.top();
        pq.pop();
        if (p > dist[u].price) continue;
        
        for (auto &[neigh, cost] : adj[u]) {
            ll new_price = p + cost;
            if (new_price == dist[neigh].price) {
                dist[neigh].ways = (dist[neigh].ways + dist[u].ways) % MOD;
                dist[neigh].min_num = min(dist[neigh].min_num, dist[u].min_num + 1);
                dist[neigh].max_num = max(dist[neigh].max_num, dist[u].max_num + 1);
            } else if (new_price < dist[neigh].price) {
                dist[neigh].price = new_price;
                dist[neigh].ways = dist[u].ways;
                dist[neigh].min_num = dist[u].min_num + 1;
                dist[neigh].max_num = dist[u].max_num + 1;
                pq.emplace(new_price, neigh);
            }
        }
    }

    dist[n].print();
}   
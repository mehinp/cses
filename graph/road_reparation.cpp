#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct DSU {
    vector<T> parents;
    vector<T> sizes;
    
    DSU(int size) {
        parents.assign(size + 1, 0);
        sizes.assign(size + 1, 0);
        for (int i = 1; i <= size; i++) {
            parents[i] = i;
        }
    }

    int find(T x) {
        return parents[x] == x ? x : (parents[x] = find(parents[x]));
    }

    bool unite(T x, T y) {
        int x_root = find(x);
        int y_root = find(y);

        if (x_root == y_root) {
            return false;
        } 

        if (sizes[x_root] < sizes[y_root]) {
            swap(x_root, y_root);
        }
        
        parents[y_root] = x_root;
        sizes[x_root] += sizes[y_root];

        return true;
    }
};

struct Edge {
    int u;
    int v;
    int w;
    bool operator>(const Edge& other) const {
        return w > other.w;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        pq.emplace(a, b, c);
    }

    int cnt = 0;
    long long ans = 0;

    DSU<int> dsu(n);
    while (cnt < n - 1 && !pq.empty()) {
        auto [u, v, c] = pq.top();
        pq.pop();
        if (!dsu.unite(u, v)) continue;
        cnt += 1;
        ans += c;
    }

    if (cnt != n - 1) {
        cout << "IMPOSSIBLE" << '\n';
    } else {
        cout << ans << '\n';
    }
}
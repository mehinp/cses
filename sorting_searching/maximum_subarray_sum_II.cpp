#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 2e15;

template<typename T>
struct SegTree {
    int n;
    vector<T> tree;

    SegTree(int n) {
        int pad = 1;
        while (pad < n) {
            pad <<= 1;
        }
        this->n = pad;
        tree.resize(2 * this->n, INF);
    }   

    T get(int query_low, int query_high, int node, int node_left, int node_right) {
        if (query_low <= node_left && node_right <= query_high) {
            return tree[node];
        }
        if (node_right < query_low || query_high < node_left) {
            return INF;
        }
        
        int mid = (node_left + node_right) / 2;

        return min(get(query_low, query_high, 2 * node, node_left, mid),
                 get(query_low, query_high, 2 * node + 1, mid + 1, node_right));
    }

    T query(int l, int r) {
        if (r == 0) return 0;
        return get(l, r, 1, 1, n);
    }

    void update(int idx, T newVal) {
        assert(idx >= 1 && idx <= n);
        int node = n - 1 + idx;
        tree[node] = newVal;
        node /= 2;
        while (node > 0) {
            tree[node] = min(tree[2 * node], tree[2 * node + 1]);
            node /= 2;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, a, b;
    cin >> n >> a >> b;

    vector<ll> x(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }

    SegTree<ll> sg(n);

    ll pref = 0;
    ll ans = -INF;
    for (int i = 1; i <= n; i++) {
        int left_bound = max(0, i - b);
        int right_bound = i - a;
        pref += x[i];
        if (right_bound >= 0) {
            ll res = sg.query(left_bound, right_bound);
            ans = max(ans, pref - res);
        }
        if (i >= a && i <= b) ans = max(ans, pref);
        sg.update(i, pref);
    }

    cout << ans << '\n';
}
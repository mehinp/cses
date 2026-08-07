#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 5;
template<typename T>
struct SegTree {
    int n;
    vector<T> tree;

    SegTree(vector<T> arr) {
        int pad = 1;
        while (pad < int(arr.size())) {
            pad <<= 1;
        }
        this->n = pad;
        arr.resize(pad, INF);
        tree.assign(2 * n, INF);
        
        for (int i = 0; i < n; i++) {
            tree[n + i] = arr[i];
        }

        for (int i = n - 1; i >= 1; i--) {
            tree[i] = min(tree[2 * i], tree[2 * i + 1]);
        }
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
        assert(l > 0 && r <= n && l <= r);
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
    
    int n, q;
    cin >> n >> q;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    SegTree<int> sg(x);
    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            sg.update(b, c);
        } else {
            assert(a == 2);
            cout << sg.query(b, c) << '\n';
        }
    }
}
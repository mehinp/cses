#include <bits/stdc++.h>
using namespace std;

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
        tree.resize(2 * this->n, 0);
    }   

    T get(int query_low, int query_high, int node, int node_left, int node_right) {
        if (query_low <= node_left && node_right <= query_high) {
            return tree[node];
        }
        if (node_right < query_low || query_high < node_left) {
            return 0;
        }
        
        int mid = (node_left + node_right) / 2;

        return max(get(query_low, query_high, 2 * node, node_left, mid),
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
            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
            node /= 2;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    int n;
    cin >> n;
    vector<pair<int, int>> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    vector<int> stk;
    vector<pair<int, int>> b(n);

    for (int i = 0; i < n; i++) {
        b[i].first = i;
        while (!stk.empty() && a[stk.back()].first < a[i].first) {
            b[i].first = stk.back();    
            stk.pop_back();
        }
        if (stk.empty()) {
            b[i].second = 0;
        }
        stk.push_back(i);
    }

    stk.clear();
    for (int i = n - 1; i >= 0; i--) {
        b[i].second = i;
        while (!stk.empty() && a[stk.back()].first < a[i].first) {
            b[i].second = stk.back();
            stk.pop_back();
        }
        if (stk.empty()) {
            b[i].second = n - 1;
        }
        stk.push_back(i);
    }


    sort(a.begin(), a.end());
    SegTree<int> dp(n);
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int idx = a[i].second;
        int left = b[idx].first;
        int right = b[idx].second;

        int res = dp.query(left + 1, right + 1) + 1;
        ans = max(ans, res);
        dp.update(idx + 1, res);
    }

    cout << ans << '\n';
}
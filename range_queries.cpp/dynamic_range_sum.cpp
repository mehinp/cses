#include <bits/stdc++.h>
using namespace std;

struct FenwickTree {
    vector<long long> tree;
    vector<long long> arr;
    int n;

    FenwickTree(const vector<long long>& arr) {
        this->n = arr.size();
        this->arr = arr;
        tree.assign(n + 1, 0);

        for (int i = 0; i < n; i++) {
            tree[i + 1] = arr[i];
        }

        for (int i = 1; i <= n; i++) {
            int parent = i + (i & -i);
            if (parent <= n) {
                tree[parent] += tree[i];
            }
        }
    }

    void update(int idx, long long newVal) {
        long long delta = newVal - arr[idx - 1];
        arr[idx - 1] = newVal;
        while (idx <= n) {
            tree[idx] += delta;
            idx += (idx & -idx);
        }
    }

    long long sum(int idx) {
        long long s = 0;
        while (idx > 0) {
            s += tree[idx];
            idx -= (idx & -idx);
        }
        return s;
    }

    long long query(int l, int r) {
        assert(l <= r && l > 0 && r <= n);
        return sum(r) - sum(l - 1);
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    vector<long long> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    FenwickTree ft(x);

    for (int i = 0; i < q; i++) {
        int w;
        cin >> w;
        if (w == 1) {
            int k, u;
            cin >> k >> u;
            ft.update(k, u);
        } else {
            int a, b;
            cin >> a >> b;
            cout << ft.query(a, b) << '\n';
        }
    }
}
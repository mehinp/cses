#include <bits/stdc++.h>
using namespace std;

struct FenwickTree {
    vector<int> tree;
    int n;

    FenwickTree(const vector<int>& arr) {
        this->n = arr.size();
        tree.resize(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            tree[i] = arr[i - 1];
        }

        for (int i = 1; i <= n; i++) {
            int parent = i + (i & -i);
            if (parent <= n) {
                tree[parent] ^= tree[i];
                parent += (i & -i);
            }
        }
    }

    int sum(int idx) {
        assert(idx >= 0 && idx <= n);
        int s = 0;
        while (idx > 0) {
            s ^= tree[idx];
            idx -= (idx & -idx);
        }
        return s;
    }

    int query(int l, int r) {
        assert(l > 0 && r <= n && l <= r);
        return sum(r) ^ sum(l - 1);
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    FenwickTree ft(a);
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << ft.query(a, b) << '\n';
    }
}









. * . .
* . * *
* * . .
* * * *




#include <bits/stdc++.h>
using namespace std;

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
        arr.resize(pad, 0);
        tree.assign(2 * n, 0);
        
        for (int i = 0; i < n; i++) {
            tree[n + i] = arr[i];
        }

        for (int i = n - 1; i >= 1; i--) {
            tree[i] = max(tree[2 * i], tree[2 * i + 1]);
        }
    }   

    T get(int node, int target) {
        if (node >= n && tree[node] >= target) {
            return node - n + 1;
        }
        
        if (tree[2 * node] >= target) {
            return get(2 * node, target);
        } else if (tree[2 * node + 1] >= target) {
            return get(2 * node + 1, target);
        }
        return 0;
    }

    T query(int target) {
        return get(1, target);
    }

    void update(int idx, T delta) {
        assert(idx >= 1 && idx <= n);
        int node = n - 1 + idx;
        tree[node] -= delta;
        node /= 2;
        while (node > 0) {
            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
            node /= 2;
        }
    }
};


int main() {
    int n, m;
    cin >> n >> m;
    vector<int> rooms(n);
    for (int i = 0; i < n; i++) {
        cin >> rooms[i];
    }

    SegTree<int> sg(rooms);
    for (int i = 0; i < m; i++) {
        int need;
        cin >> need;
        int which = sg.query(need);
        cout << which << ' ';
        if (which) {
            sg.update(which, need);
        }
    }
    cout << '\n';
}
#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct DSU {
    vector<T> parents;
    vector<T> sizes;
    int max_size;
    int comps;
    
    DSU(int size) {
        parents.assign(size + 1, 0);
        sizes.assign(size + 1, 1);
        for (int i = 1; i <= size; i++) {
            parents[i] = i;
        }
        max_size = 1;
        comps = size;
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

        max_size = max(max_size, sizes[x_root]);
        comps -= 1;

        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    DSU<int> dsu(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        dsu.unite(x, y);
        cout << dsu.comps << ' ' << dsu.max_size << '\n';
    }
}
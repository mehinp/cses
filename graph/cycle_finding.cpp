#include <bits/stdc++.h>
using namespace std;

using ll = long long;
struct Edge {
    int u;
    int v;
    int w;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
    vector<Edge> edges;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.emplace_back(a, b, c);
    }   

    vector<int> parent(n + 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][j];
        }
        for (const auto& [u, v, w] : edges) {
            if (dp[i - 1][u] + w < dp[i][v]) {
                parent[v] = u;
                dp[i][v] = dp[i - 1][u] + w;
            }
        }
    }

    vector<int> path;
    bool good = false;
    for (int i = 1; i <= n; i++) {
        if (dp[n][i] != dp[n - 1][i]) {

            int node = i;
            for (int j = 0; j < n; j++) {
                node = parent[node];
            }

            int start = node;
            do {
                path.push_back(node);
                node = parent[node];
            } while (node != start);

            path.push_back(start);
            good = 1;
            break;
        }
    }

    if (!good) {
        cout << "NO" << '\n';
        return 0;
    }

    reverse(path.begin(), path.end());
    cout << "YES" << '\n';
    for (int x : path) {
        cout << x << ' ';
    }
    cout << '\n';
}
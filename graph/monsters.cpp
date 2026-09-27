#include <bits/stdc++.h>
using namespace std;

struct Node {
    int x;
    int y;
    int len;
};


const int INF = 1e9 + 5;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    queue<Node> q;
    vector<vector<pair<int, int>>> dist(n, vector<pair<int, int>>(m, {INF, INF}));

    Node A;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'M'){
                q.emplace(i, j, 0);
                dist[i][j].first = 0;
            } else if (a[i][j] == 'A') {
                dist[i][j].second = 0;
                A.x = i;
                A.y = j;
                A.len = 0;
            }
        }
    }    

    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while (!q.empty()) {
        auto [x, y, len] = q.front();
        q.pop();
        for (auto& d : dirs) {
            int new_x = d.first + x;
            int new_y = d.second + y;
            if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= m || dist[new_x][new_y].first != INF) continue;
            if (a[new_x][new_y] == '#') continue;
            dist[new_x][new_y].first = len + 1;
            q.emplace(new_x, new_y, len + 1);
        }
    }

    queue<Node> aq;
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m));
    aq.push(A);

    while (!aq.empty()) {
        auto [x, y, len] = aq.front();
        aq.pop();
        for (auto& d : dirs) {
            int new_x = d.first + x;
            int new_y = d.second + y;
            if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= m || dist[new_x][new_y].second != INF) continue;
            if (a[new_x][new_y] == '#') continue;
            parent[new_x][new_y] = {x, y};
            dist[new_x][new_y].second = len + 1;
            aq.emplace(new_x, new_y, len + 1);
        }
    }

    pair<int, int> start = {-1, -1};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                if (dist[i][j].first > dist[i][j].second) {
                    start.first = i;
                    start.second = j;
                }
            } 
        }
    } 

    if (start.first == -1) {
        cout << "NO" << '\n';
        return 0;
    }

    int x = start.first;
    int y = start.second;
    string path = "";
    while (a[x][y] != 'A') {
        auto par = parent[x][y];
        int dx = x - par.first;
        int dy = y - par.second;
        if (dx == -1) {
            path += 'U';
        } else if (dx == 1) {
            path += 'D';
        } else if (dy == -1) {
            path += 'L';
        } else {
            path += 'R';
        }
        x = par.first;
        y = par.second;
    }
    reverse(path.begin(), path.end());
    cout << "YES\n" << int(path.length()) << '\n' << path << '\n';
}
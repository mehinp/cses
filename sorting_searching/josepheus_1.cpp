#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    bool flag = false;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }
    while (!q.empty()) {
        int f = q.front();
        q.pop();
        if (flag) {
            cout << f << ' ';
        } else {
            q.push(f);
        }
        flag = !flag;
    }
}
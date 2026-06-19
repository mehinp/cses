#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<array<int, 3>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i;
    }
    sort(a.begin(), a.end(), [&](const array<int, 3>& a1, const array<int, 3>& a2){
        if (a1[0] != a2[0]) {
            return a1[0] < a2[0];
        }
        return a1[1] > a2[1];
    });
    vector<int> ans1(n);
    int minRight = a[n - 1][1];
    for (int i = n - 2; i >= 0; i--) {
        if (a[i][1] >= minRight) {
            ans1[a[i][2]] = 1;
        }
        minRight = min(minRight, a[i][1]);
    }
    vector<int> ans2(n);
    int maxRight = a[0][1];
    for (int i = 1; i < n; i++) {
        if (a[i][1] <= maxRight) {
            ans2[a[i][2]] = 1;
        }
        maxRight = max(maxRight, a[i][1]);
    }
    for (int val : ans1) {
        cout << val << ' ';
    }
    cout << '\n';
    for (int val : ans2) {
        cout << val << ' ';
    }
    cout << '\n';
}
#include <bits/stdc++.h>
using namespace std;

/*
Sort and maintain left and right pointer. Try to pair L and R. If exceeds x, then only move R down.
Otherwise, move both pointers towards center.
*/

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int l = 0;
    int r = n - 1;
    int ans = 0;
    while (l <= r) {
        if (a[l] + a[r] <= x) l++;
        r--;
        ans++;
    }
    cout << ans << '\n';
}
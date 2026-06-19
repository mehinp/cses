#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = 0;
    int ans = 0;
    int currSum = 0;
    for (int i = 0; i < n; i++) {
        currSum += a[i];
        while (currSum > x) {
            currSum -= a[l++];
        }
        if (currSum == x) ans++;
    }
    cout << ans << '\n';
}
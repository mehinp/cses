#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    map<int, int> distinct;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long ans = 0;
    int l = 0;
    for (int i = 0; i < n; i++) {
        distinct[a[i]]++;
        while (int(distinct.size()) > k) {
            distinct[a[l]]--;
            if (distinct[a[l]] == 0) {
                distinct.erase(a[l]);
            }
            l++;
        }
        ans += i - l + 1;
    }
    cout << ans << '\n';
}
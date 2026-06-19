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

    multiset<int> seen;
    int right = a[n - 1][1];
    seen.insert(right);
    vector<int> ans1(n);
    for (int i = n - 2; i >= 0; i--) {
        ans1[i] = distance(upper_bound(seen.begin(), seen.end(), a[i][1]), seen.begin());
    }
}
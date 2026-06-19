#include <bits/stdc++.h>
using namespace std;
/*
Sort the array and make all sticks equal to the median number (if even it doesn't matter which one you choose)
*/

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int target = a[n / 2];
    long long cost = 0;
    for (int i = 0; i < n; i++) {
        cost += abs(a[i] - target);
    }
    cout << cost << '\n';
} 
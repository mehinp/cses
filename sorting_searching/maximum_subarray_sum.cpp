#include <bits/stdc++.h>
using namespace std;
/*
Use Kadane's algorithm
*/

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long best = a[0];
    long long curr = a[0];
    for (int i = 1; i < n; i++) {
        curr = max(a[i], curr + a[i]);
        best = max(best, curr);
    }
    cout << best << "\n";
}

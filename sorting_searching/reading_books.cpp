#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    long long first = accumulate(a.begin(), a.end() - 1, 0LL);
    int second = a[n - 1];
    if (first >= second) {
        cout << first + second << '\n';
    } else {
        cout << 2 * second << '\n';
    }
}
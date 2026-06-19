#include <bits/stdc++.h>
using namespace std;
/*
Use sliding window, each time you encounter a distinct element add size of window. Otherwise, shrink the window.
*/

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = 0;
    long long count = 0;
    set<int> seen;
    for (int i = 0; i < n; i++) {
        while (seen.contains(a[i])) {
            seen.erase(a[l]);
            l++;
        }
        seen.insert(a[i]);
        count += i - l + 1;
    }
    cout << count << '\n';
}
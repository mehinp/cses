#include <bits/stdc++.h>
using namespace std;

/*
Sliding window. Maintain a set of the seen songs. If we ever have a duplicate, shrink the window until all songs are unique.
Compute max as we go.
*/

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    set<int> seen;
    int l = 0;
    int best = 0;
    for (int i = 0; i < n; i++) {
        while (seen.contains(a[i])) {
            seen.erase(a[l]);
            l++;
        }
        seen.insert(a[i]);
        best = max(best, int(seen.size()));
    }
    cout << best << '\n';
}
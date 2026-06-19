#include <bits/stdc++.h>
using namespace std;

/*
Put the arrival and departure times into one array. Sort the array. Maintain a running max as you go. 
If it is an arrival, add one to the count, otherwise decrement the count. 
*/

int main() {
    int n;
    cin >> n;
    vector<pair<int, bool>> times;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        times.emplace_back(a, true);
        times.emplace_back(b, false);
    }

    sort(times.begin(), times.end());
    int best = 0;
    int curr = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (times[i].second) {
            curr++;
        } else {
            curr--;
        }
        best = max(best, curr);
    }
    cout << best << '\n';
}

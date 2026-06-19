#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> times(n);
    long long deadlines = 0;
    for (int i = 0; i < n; i++) {
        int t, d; 
        cin >> t >> d;
        deadlines += d;
        times[i] = t;
    }
    sort(times.begin(), times.end());
    for (int i = 0; i < n; i++) {
        deadlines -= (n - i) * times[i];
    }
    cout << deadlines << '\n';
}
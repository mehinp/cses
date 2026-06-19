#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<int, int> remainders;
    remainders[0]++;
    int running = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int diff = abs(a[i] - 0);
        int sum = (diff + n - 1) / n * n + a[i];
        running = (sum + running) % n;
        if (remainders.contains(running)) {
            ans += remainders[running];
        }
        remainders[running]++;
    }   
    cout << ans << '\n';
}
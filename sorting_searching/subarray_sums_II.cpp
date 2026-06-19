#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<long long, int> freq;
    long long sum = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        long long comp = sum - x;
        if (freq.contains(comp)) {
            ans += freq[comp];
        }   
        freq[sum]++;
    }
    cout << ans + freq[x] << '\n';
}
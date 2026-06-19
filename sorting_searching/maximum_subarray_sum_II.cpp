#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<long long> pref(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (i == 0) {
            pref[i] = x;
        } else {
            pref[i] = pref[i - 1] + x;
        }
    }

    vector<long long> minArray;
    
}
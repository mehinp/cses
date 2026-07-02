#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<double> a(11, 1);

    for (int i = 9; i >= 1; i--) {
        a[i] += a[i + 1] + (double) 1 / i * (a[i + 1]) - 1;
    }
    cout << (accumulate(a.begin(), a.end(), 0.0) - 1) * 0.1 << '\n';
}
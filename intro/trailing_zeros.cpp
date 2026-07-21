#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;   
    int ans = 0;

    for (int base = 5; base <= n; base *= 5) {
        ans += n / base;
    }

    cout << ans << '\n';
}

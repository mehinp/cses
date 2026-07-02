#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int main() {
    int n;
    cin >> n;
    int sum = n * (n + 1) / 2;
    if (sum % 2) {
        cout << 0 << '\n';
        return 0;
    }
    int target = sum / 2;
    vector<long long> dp(target + 1);

    dp[0] = 1;
    for (int i = 1; i <= n - 1; i++) {
        for (int j = target - i; j >= 0; j--) {
            dp[i + j] = (dp[i + j] + dp[j]) % MOD;
        }
    }
    cout << dp[target] << '\n';
}
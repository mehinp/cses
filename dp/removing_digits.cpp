#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> dp(n + 1, INT_MAX);
    dp[n] = 0;
    
    for (int i = n; i >= 1; i--) {
        if (dp[i] == INT_MAX) continue;
        int num = i;
        while (num > 0) {
            int digit = num % 10;
            if (i - digit >= 0) {
                dp[i - digit] = min(dp[i - digit], dp[i] + 1);
            }
            num /= 10;
        }
    }
    cout << dp[0] << '\n';
}
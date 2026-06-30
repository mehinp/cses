#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a.length() + 2, vector<int>(b.length() + 2));

    for (int i = 1; i <= a.length() + 1; i++) {
        dp[i][1] = i - 1;
    }
    for (int j = 1; j <= b.length() + 1; j++) {
        dp[1][j] = j - 1;
    }

    for (int i = 2; i <= a.length() + 1; i++) {
        for (int j = 2; j <= b.length() + 1; j++) {
            if (a[i - 2] == b[j - 2]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
            }
        }
    }

    cout << dp[a.length() + 1][b.length() + 1] << '\n';
}
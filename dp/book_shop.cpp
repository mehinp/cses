#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> dp(x + 1);
    vector<pair<int, int>> books(n);
    for (int i = 0; i < n; i++) {
        cin >> books[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> books[i].second;
    }

    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = x; j >= 0; j--) {
            if (j - books[i].first >= 0 && dp[j - books[i].first] > 0) {
                dp[j] = max(dp[j], dp[j - books[i].first] + books[i].second);
            }
        }
    }
    cout << *max_element(dp.begin(), dp.end()) - 1 << '\n';
}
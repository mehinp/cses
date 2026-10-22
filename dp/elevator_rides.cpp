#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, x;
    cin >> n >> x;
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    const int nax = (1 << n);
    vector<pair<int, int>> dp(nax, {25, 0});
    dp[0] = {1, 0};

    for (int mask = 0; mask < nax; mask++) {
        long long cur_w = dp[mask].second;

        for (int j = 0; j < n; j++) {
            if (!(mask & (1 << j))) {
                int new_mask = mask | (1 << j);
                long long new_w = cur_w + weights[j];
                auto cand = make_pair(dp[mask].first, new_w);
                if (new_w > x) {
                    cand.first += 1;
                    cand.second = weights[j];
                }
                if (cand.first < dp[new_mask].first) {
                    dp[new_mask] = cand;
                } else if (cand.first == dp[new_mask].first && cand.second < dp[new_mask].second) {
                    dp[new_mask] = cand;
                }
            }
        }
    }
    cout << dp[nax - 1].first << '\n';
}
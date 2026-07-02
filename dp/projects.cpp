#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<array<int, 3>> projects(n);
    for (int i = 0; i < n; i++) {
        cin >> projects[i][0] >> projects[i][1] >> projects[i][2];
    }
    sort(projects.begin(), projects.end(), [&](const array<int, 3>& p1, const array<int, 3>& p2){
        return p1[1] < p2[1];
    });

    vector<pair<int, long long>> dp(n, {INT_MAX, 0});
    dp[0] = {projects[0][1], projects[0][2]};

    // dp[i] -> {end time, maximum money}

    for (int i = 1; i < n; i++) {
        // transition: either we don't do the current project, or we do the current project and find the maximum dp value with
        // end date before this start date
        auto p = make_pair(projects[i][0], 0LL);
        auto it = lower_bound(dp.begin(), dp.end(), p);
        long long prev = 0; 
        if (it != dp.begin()) {
            it--;
            prev = it->second;
        } 
        if (dp[i - 1].second > prev + projects[i][2]) {
            dp[i] = {projects[i][1], dp[i - 1].second};
        } else {
            dp[i] = {projects[i][1], prev + projects[i][2]};
        }
    }
    cout << dp[n - 1].second << '\n';
}
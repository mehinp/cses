#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& a) {
    vector<int> stk;
    int n = a.size();
    int ans = 1;

    for (int i = 0; i < n; i++) {
        while (!stk.empty() && a[i] >= a[stk.back()]) {
            stk.pop_back();
        }
        stk.push_back(i);
        if (i - stk[0] + 1 > ans) {
            cout << i << ' ' << stk[0] << '\n';
            ans = i - stk[0] + 1;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = solve(a);
    reverse(a.begin(), a.end());
    ans = max(ans, solve(a));
    cout << ans << '\n';
}
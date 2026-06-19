#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    stack<pair<int, int>> st;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top().first >= a[i]) {
            st.pop();
        }  
        if (!st.empty()) {
            cout << st.top().second + 1 << ' ';
        } else {
            cout << 0 << ' ';
        }
        st.emplace(a[i], i);
    }
}
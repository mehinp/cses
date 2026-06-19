#include <bits/stdc++.h>
using namespace std;

/*
Put all the prices in a multiset. For each customer, run upper_bound on their max price. 
The answer is the returned iterator - 1 (first price <= max price). If the iterator is the first element, answer is -1
because all elements are larger than max price.
*/

int main() {
    int n, m;
    cin >> n >> m;
    multiset<int> prices;
    vector<int> cust(m);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        prices.insert(x);
    }
    for (int i = 0; i < m; i++) {
        cin >> cust[i];
    }

    for (int c : cust) {
        auto it = prices.upper_bound(c);
        if (it == prices.begin()) {
            cout << -1;
        } else {
            cout << *(--it);
            prices.erase(it);
        }
        cout << '\n';
    }
}
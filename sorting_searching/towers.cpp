#include <bits/stdc++.h>
using namespace std;

/*
Maintain a multiset of the top of each tower. Run upper_bound to find the closest possible tower that is higher.
If returns an iterator to the end, we need to create a new tower. Otherwise, replace the found value with new value.
*/

int main() {
    int n;
    cin >> n;
    multiset<int> ms;
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        auto it = ms.upper_bound(x);
        if (it != ms.end()) {
            ms.erase(it);
        }
        ms.insert(x);
    }
    cout << int(ms.size()) << '\n';
}
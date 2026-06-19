#include <bits/stdc++.h>
using namespace std;

// first row should be 0 - n-1
// first col should be 0 - n-1
// we can maintain a set of the elements above in a certain column and a running set of elements in the row
// iterate in while loop until neither set contains the elements

int main() {
    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(n));
    vector<unordered_set<int>> alreadyCols(n);

    for (int i = 0; i < n; i++) {
        a[0][i] = i;
        a[i][0] = i;
        alreadyCols[i].insert(i);
    }

    for (int i = 1; i < n; i++) {
        unordered_set<int> alreadyRows;
        alreadyRows.insert(a[i][0]);
        for (int j = 1; j < n; j++) {
            int x = 0;
            while(alreadyRows.count(x) || alreadyCols[j].count(x)) {
                x++;
            }
            alreadyRows.insert(x);
            alreadyCols[j].insert(x);
            a[i][j] = x;
        }
    }   

    
    for (vector<int> v : a) {
        for (int val : v) {
            cout << val << ' ';
        }
        cout << '\n';
    }
}
#include <bits/stdc++.h>
using namespace std;


vector<string> solve(int n) {
    if (n == 1) {
        return {"1", "0"};
    }

    vector<string> a = solve(n-1);
    vector<string> b = a;

    reverse(b.begin(), b.end()); // follow the forward path, but in reverse order

    for (string &s : a) {
        s += "0";
    }

    for (string &s : b) {
        s += "1";
    }

    a.insert(a.end(), b.begin(), b.end());
    return a;
}

int main() { 
    int n;
    cin >> n;

    vector<string> ans = solve(n);

    for (string &s : ans) {
        cout << s << '\n';
    }
}
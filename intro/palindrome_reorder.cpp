#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    int n = s.length();

    unordered_map<char, int> freq;

    for (int i = 0; i < n; i++) {
        freq[s[i]]++;
    }

    int oddCount = 0;
    char oddLetter = ' ';
    for (auto p : freq) {
        if (p.second % 2) {
            oddCount++;
            oddLetter = p.first;
        }
    }

    if ((!(n % 2) && oddCount) || oddCount > 1) {
        cout << "NO SOLUTION";
        return;
    }


    string start = "";
    for (auto p : freq) {
        for (int i = 0; i < (int)p.second / 2; i++) {
            start += p.first;
        }
    }

    string end = start;
    reverse(end.begin(), end.end());
    if (oddCount) {
        start += oddLetter;
    }

    cout << start + end << '\n';
}


int main(){
    solve();
}
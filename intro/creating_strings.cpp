#include <bits/stdc++.h>
using namespace std;

// key insight: this is a permutation problem. n <= 8, so we can generate all possible permutations in n! time
// however, we need to be careful of repetitions. we will use an ordered set instead of a vector

set<string> permutations;

void permute(string s, string curr, int n, int k, vector<bool> &visIndices) {
    if (n == k) {
        permutations.insert(curr);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (visIndices[i]) continue;
        curr += s[i];
        visIndices[i] = true;
        permute(s, curr, n, k+1, visIndices);
        curr.pop_back();
        visIndices[i] = false;
    }
}



int main() {
    string s;
    cin >> s;

    int n = s.length();
    vector<bool> visIndices(n);
    permute(s, "", n, 0, visIndices);

    cout << permutations.size() << '\n';
    for (string s : permutations) {
        cout << s << '\n';
    }
}


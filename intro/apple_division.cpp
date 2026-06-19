#include <bits/stdc++.h>
using namespace std;

// key insight: this is a subsets problem. n <= 20, so we can generate all possible subsets without TLE
// compare the sum of each subset with the remaining sum and maintain the min

long long minDifference = LLONG_MAX;
void generate(int n, int k, long long currSum, long long totalSum, vector<int> &apples) {
    if (n == k) {
        if (currSum == totalSum) return;
        minDifference = min(minDifference, abs(currSum - (totalSum - currSum)));
        return;
    }

    generate(n, k+1, currSum, totalSum, apples);
    currSum += apples[k];
    generate(n, k+1, currSum, totalSum, apples);
    currSum -= apples[k];
} 

void solve() {
    int n;
    cin >> n;

    vector<int> apples(n);
    for (int i = 0; i < n; i++) {
        cin >> apples[i];
    }

    long long totalSum = accumulate(apples.begin(), apples.end(), 0LL);
    generate(n, 0, 0, totalSum, apples);

    cout << minDifference << '\n';
}   

int main() {
    solve();
}
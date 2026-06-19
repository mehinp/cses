#include <bits/stdc++.h>
using namespace std;

/*
Sort the movies by end time. Greedily choose the movies if they are valid. 
*/


int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> movies;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        movies.emplace_back(a, b);
    }

    sort(movies.begin(), movies.end(), [](const pair<int, int> first, const pair<int, int> second){
        return first.second < second.second;
    });

    int count = 0;
    int prev = 0;
    for (int i = 0; i < n; i++) {
        if (movies[i].first >= prev) {
            count++;
            prev = movies[i].second;
        }
    }
    cout << count << '\n';
}
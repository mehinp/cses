#include <bits/stdc++.h>
using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, 3);
    vector<int> nums = {0, 1, 2, 3};

    int total = 0;
    for (int i = 0; i < 1e6; i++) {
        vector<int> boxes(4);
        int EV = 0;
        for (int j = 1; j <= 16; j++) {
            int box = dist(gen);
            if (j % 4 == 0) {   
                shuffle(nums.begin(), nums.end(), gen);
                EV += boxes[nums[0]] + boxes[nums[1]];
                boxes[nums[0]] = 0;
                boxes[nums[1]] = 0;
                boxes[box] = 0;
            } else {
                boxes[box]++;
            }
        } 
        total += EV;
    }
    cout << (double) total / 1e6;
}
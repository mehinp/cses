#include <bits/stdc++.h>
using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> dist(1, 2);
    
    int total = 0;
    int mx = -1;
    int mn = INT_MAX;
    for (int i = 0; i < 1e6; i++) {
        set<int> nums1;
        set<int> nums2;
        int time = 0;
        int pos = 7;
        nums1.insert(pos);
        while (int(nums1.size()) != 15 || int(nums2.size()) != 15) {
            int dir = dist(gen);
            if (dir == 2) {
                pos = (pos + 1) % 15;
                if (nums1.contains(pos)) {
                    nums2.insert(pos);
                } else {
                    nums1.insert(pos);
                }
                pos = (pos + 1) % 15;
                if (nums1.contains(pos)) {
                    nums2.insert(pos);
                } else {
                    nums1.insert(pos);
                }
            } else {
                pos = (pos + 14) % 15;
                if (nums1.contains(pos)) {
                    nums2.insert(pos);
                } else {
                    nums1.insert(pos);
                }
                pos = (pos + 14) % 15;
                if (nums1.contains(pos)) {
                    nums2.insert(pos);
                } else {
                    nums1.insert(pos);
                }
            }
            time++;
        }
        mx = max(mx, time);
        mn = min(mn, time);
        total += time;
    }
    cout << mx << ' ' << mn << '\n';
    cout << (double) total / 1e6;
}
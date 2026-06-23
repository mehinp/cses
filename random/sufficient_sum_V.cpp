#include <bits/stdc++.h>
using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());

    uniform_real_distribution<double> dist(0, 1);
    int total = 0;
    for (int i = 0; i < 1e6; i++) {
        double sum = 0;
        double draw = 0;
        int count = 0;
        while (sum <= 1) {
            draw = dist(gen);
            sum += draw;
            count++;
        }
        if (draw > 0.2) {
            total += count;
        }
    }
    cout << (double) total / 1e6;
}
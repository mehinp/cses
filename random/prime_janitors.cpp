#include <bits/stdc++.h>
using namespace std;

bool isPrime(int num) {
    if (num == 2) return true;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    
}
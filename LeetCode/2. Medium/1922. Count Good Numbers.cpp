#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

static const long long MOD = 1e9 + 7;

// Recursive Approach - O(N)
/*
int goodNumbers(int index, int n) {
    if(index == n)
        return 1;
    
    int result = 0;
    if(index % 2 == 0) {
        for(int digit : {0, 2, 4, 6, 8})
            result = (result + goodNumbers(index + 1, n)) % MOD;
    }
    else {
        for(int digit : {1, 3, 5, 7})
            result = (result + goodNumbers(index + 1, n)) % MOD;
    }

    return result;
}

int countGoodNumbers(long long n) {
    int result = 0;

    result = goodNumbers(0, n);

    return result;
}
*/

// Optimal Approach O(Log(N)) - Using Fast Exponentiation
long long modPower(long long base, long long position) {
    long long result = 1;
    base %= MOD;

    while(position > 0) {
        if(position % 2 == 1)
            result = (result * base) % MOD;
        
        base = (base * base) % MOD;
        position /= 2;
    }

    return result;
}

int countGoodNumbers(long long n) {
    long long evenPositions = (n + 1) / 2, oddPositions = n / 2;

    // answer = (5^((n+1)//2) × 4^(n//2)) mod (10^9 + 7)
    long long evenPossibilities = modPower(5, evenPositions);
    long long oddPossibilities = modPower(4, oddPositions);

    return (evenPossibilities * oddPossibilities) % MOD;
}

int main() {
    long long n = 1;

    cout<<countGoodNumbers(n);

    return 0;
}
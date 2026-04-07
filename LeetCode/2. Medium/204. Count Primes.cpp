#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int countPrimes(int n) {
    if (n <= 2) 
        return 0;  // primes less than 2: none

    int count = 0;
    vector<bool> isPrime(n, true);

    isPrime[0] = isPrime[1] = false;

    for (int p = 2; p * p < n; p++) {
        if (isPrime[p]) {
            // Marking the multiples of prime as false
            for (int i = p * p; i < n; i += p) {
                isPrime[i] = false;
            }
        }
    }
    
    for (int i = 2; i < n; i++) {
        if (isPrime[i]) 
            count += 1;
    }
    
    return count;
}

int main() {
    int n = 10;

    cout<<countPrimes(n);

    return 0;
}
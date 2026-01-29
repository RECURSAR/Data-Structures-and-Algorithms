#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int nthRoot(int n, int m) {
    int low = 0, high = m, result = 0;
    long long mid = 0;

    while(low <= high) {
        mid = low + (high - low) / 2;
        result = 1;

        // Compute mid^n safely using multiplication
        for(int i = 0; i < n; i++) {
            result *= mid;
            if(result > m)  // Break if exceeds m
                break;
        }

        if(result == m)     // Exact root found
            return mid;
        
        if(result < m)      // Need Bigger root
            low = mid + 1;
        else                // Need Smaller root
            high = mid - 1;
    }

    return -1;
}

int main() {
    int n = 3, m = 8;
    
    cout<<nthRoot(n, m);

    return 0;
}
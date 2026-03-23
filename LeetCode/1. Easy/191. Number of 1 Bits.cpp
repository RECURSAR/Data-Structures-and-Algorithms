#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

// O(c), here c is 32
/*
int hammingWeight(int n) {
    int weight = 0;

    for(int i = 0; i < 32; i++) {
        if(n & 1)
            weight += 1;
        
        n = n >> 1;
    }

    return weight;
}
*/

// O(k), here k is set bits
int hammingWeight(int n) {
    int weight = 0;

    while(n) {
        n = n & (n - 1);    // Clears lowest set bit
        weight += 1;
    }

    return weight;
}

int main() {
    int n = 11;

    cout<<hammingWeight(n);

    return 0;
}
#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

// Worst Case - 32 Iterations
/*
int minBitFlips(int start, int goal) {
    int XOR = start ^ goal, count = 0;
    
    while(XOR > 0) {
        if(XOR & 1)
            count += 1;
        
        XOR >>= 1;
    }

    return count;
}
*/

// Optimal Approach - O(k), k is the number of set bits - Brian Kernighan's Trick
int minBitFlips(int start, int goal) {
    int XOR = start ^ goal, count = 0;
    
    while(XOR) {
        // Removes the lowest set bit
        XOR &= XOR - 1;

        count += 1;
    }

    return count;
}

int main() {
    int start = 10, goal = 7;
    
    cout<<minBitFlips(start, goal);

    return 0;
}
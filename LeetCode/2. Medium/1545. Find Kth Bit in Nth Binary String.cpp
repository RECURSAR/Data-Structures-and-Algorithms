#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

char findKthBit(int n, int k) {
    if(n == 1)
        return '0';
    
    // Middle position for Sn
    int mid = (1 << (n-1));     // 2 ^ (n - 1) is the length of S(n-1)

    // Middle Part
    if(k == mid){
        return '1';
    }

    // First Part
    else if(k < mid){
        return findKthBit(n - 1, k);
    }

    // Last Part
    else{
        // Position is 2 ^ n - k means invert the result;
        char bit = findKthBit(n - 1, mid - (k - mid));
        return bit == '0' ? '1' : '0';  // Bit inversion
    }

}

int main() {
    int n = 3, k = 1;

    cout<<findKthBit(n, k);

    return 0;
}
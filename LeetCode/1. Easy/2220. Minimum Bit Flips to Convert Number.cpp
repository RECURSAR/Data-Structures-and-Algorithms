#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int countOnes(int flips) {
        int count = 0;
        while(flips){
            count += (flips & 1);   // AND operation with LSB of flips and 1
            flips >>= 1;        // Right shift by 1
        }
        return count;
    }

int minBitFlips(int start, int goal) {
    int flips = start ^ goal;
    return countOnes(flips);
}

int main()
{
    int start = 7, goal = 3;
    cout<<minBitFlips(start,goal);
    return 0;
}
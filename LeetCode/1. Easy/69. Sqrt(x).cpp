#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int mySqrt(int x) {
    if(x < 2)
        return x;
    
    int low = 0, mid = 0, high = x / 2, result = 0;

    while(low <= high) {
        mid = low + (high - low) / 2;

        if(mid * mid <= x) {
            result = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    return result;
}

int main() {
    int x = 4;
    
    cout<<mySqrt(x);

    return 0;
}
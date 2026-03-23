#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int divide(int dividend, int divisor) {
    if(dividend == INT_MIN && divisor == -1)
        return INT_MAX;

    // Determining Sign
    bool negative = (dividend < 0) ^ (divisor < 0);

    long dvd = abs((long)dividend), dvs = abs((long)divisor), quotient = 0, temp = 0, multiple = 0;

    while(dvd >= dvs) {
        temp = dvs;
        multiple = 1;

        // Double the chunk until it would exceed dvd
        while(dvd >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }

        dvd -= temp;
        quotient += multiple;
    }

    return negative ? -quotient : quotient;
}

int main() {
    int dividend = 10, divisor = 3;
    
    cout<<divide(dividend, divisor);

    return 0;
}
#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

// Using Faster Exponentiation
/*
double power(double x, long long num) {
    if(num == 0)
        return 1.0;
    if(num == 1)
        return x;

    if(num % 2 == 0)
        return power(x * x, num / 2);
    
    return x * power(x, num - 1);
}

double myPow(double x, int n) {
    long long num = n;

    if(num < 0) 
        return (1.0 / power(x, -1 * num));

    return power(x, num);
}
*/

// Using Bit-Manipulation
double power(double x, long long n) {
    double result = 1;

    while(n > 0) {
        // If current bit is 1
        if(n & 1)
            result *= x;
        
        x *= x;     // Square the Base
        n >>= 1;    // Right Shift by 1
    }

    return result;
}

double myPow(double x, int n) {
    long long num = n;

    if(num < 0)
        return 1.0 / power(x, -num);

    return power(x, num);
}

int main() {
    double x = 2.00000;
    int n = 10;
    
    cout<<myPow(x, n);

    return 0;
}
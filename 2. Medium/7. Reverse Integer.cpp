#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int reverse(int x) {
    long int reversed = 0;

    while (x != 0) {
        int lastDigit = x % 10;
        reversed = reversed * 10 + lastDigit;
        x = x / 10;
    }

    // Checking for overflow or underflow and returning 0 if that happens
    return (reversed > INT_MAX || reversed < INT_MIN) ? 0 : reversed;
}

int main() {
    int x = 123;

    cout<<reverse(x);

    return 0;
}
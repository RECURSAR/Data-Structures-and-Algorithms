#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

bool armstrongNumber(int n) {
    int originalNumber = n;
    int sum = 0;

    while(n > 0) {
        int lastDigit = n % 10;
        sum += lastDigit * lastDigit * lastDigit;
        n = n / 10;
    }

    return sum == originalNumber;
}

int main() {
    int n = 153;

    armstrongNumber(n) ? cout<<"True" : cout<<"False";

    return 0;
}
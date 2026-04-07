#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int largestPrimeFactor(int n) {
    int largestPrime = -1;

    while(n % 2 == 0)
        n /= 2;
    
    largestPrime = 2;

    for(int i = 3; i * i <= n; i++) {
        while(n % i == 0) {
            largestPrime = i;
            n /= i;
        }
    }

    if(n > 2)
        largestPrime = n;
    
    return largestPrime;
}

int main() {
    int n = 5;

    cout<<largestPrimeFactor(n);

    return 0;
}
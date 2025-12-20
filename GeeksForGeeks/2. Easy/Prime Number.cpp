#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

bool isPrime(int n) {
    if(n <= 1)
        return false;
    
    if(n == 2 || n == 3)
        return true;
    
    if(n % 2 == 0 || n % 3 == 0)
        return false;
    
    // Prime Numbers greater than 3 are of the form 6k + 1, 6k + 5
    for(int i = 5; i * i <= n; i += 6) {
        if(n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}

int main() {
    int n = 7;

    isPrime(7) ? cout<<"True" : cout<<"False";

    return 0;
}
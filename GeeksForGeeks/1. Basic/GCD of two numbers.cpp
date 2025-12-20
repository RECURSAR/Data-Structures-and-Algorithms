#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int gcd(int a, int b) {
    while(b != 0) {
        int res = a % b;
        a = b;
        b = res;
    } 

    return a;
}

int main() {
    int a = 20, b =  28;

    cout<<gcd(a, b);

    return 0;
}
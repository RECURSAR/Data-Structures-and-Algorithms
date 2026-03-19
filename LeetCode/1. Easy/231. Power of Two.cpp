#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

int main() {
    int n = 1;

    isPowerOfTwo(n) ? cout<<"True" : cout<<"False";

    return 0;
}
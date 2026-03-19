#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

bool checkKthBit(int n, int k) {
    if((1 << k) & n)
        return true;
    
    return false;
}

int main() {
    int n = 4, k = 0;
    
    checkKthBit(n, k) ? cout<<"True" : cout<<"False";

    return 0;
}
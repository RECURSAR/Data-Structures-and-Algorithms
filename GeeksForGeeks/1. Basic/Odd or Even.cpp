#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

bool isEven(int n) {
    if(n & 1)
        return false;
    
    return true;
}

int main() {
    int n = 15;
    
    isEven(n) ? cout<<"True" : cout<<"False";

    return 0;
}
#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int XORtillN(int n) {
    int mod = n % 4;

    if(mod == 0)
        return n;

    if(mod == 1)
        return 1;

    if(mod == 2)
        return n + 1;

    if(mod == 3)
        return 0;
    
    return 0;
}

int findXOR(int l, int r) {
    return XORtillN(l - 1) ^ XORtillN(r);    
}

int main() {
    int l = 4, r = 8;

    cout<<findXOR(l, r);

    return 0;
}
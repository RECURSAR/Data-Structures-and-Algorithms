#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

long long coloredCells(int n) {
    return static_cast<long>(n) * n + static_cast<long>(n - 1) * (n - 1);       
}

int main() {
    int n = 1;

    cout<<coloredCells(n);

    return 0;
}
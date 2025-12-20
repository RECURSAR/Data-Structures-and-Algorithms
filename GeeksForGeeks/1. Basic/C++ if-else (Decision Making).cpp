#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

string compareFive(int n) {
    if(n > 5)
        return "Greater than 5";
    else if(n == 5)
        return "Equal to 5";
    else
        return "Less than 5";    
}

int main() {
    int n = 8;

    cout<<compareFive(n);

    return 0;
}
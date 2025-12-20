#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int countDigits(int n) {
    int count = 0;

    while(n > 0) {
        if(n == 0)
            break;

        n = n / 10;
        count += 1;
    }

    return count;    
}

int main() {
    int n = 12;

    cout<<countDigits(n);

    return 0;
}
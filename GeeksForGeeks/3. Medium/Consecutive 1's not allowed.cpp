#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

// Recursive Solution
/*
int split(int digit, int length) {
    if(length == 0)
        return 1;

    int result = 0;

    if(digit == 0)
        result += split(0, length - 1) + split(1, length - 1);
    else if(digit == 1)
        result += split(0, length - 1);

    return result;
}

int countStrings(int n) {
    int result = 0;

    result = split(0, n);
    
    return result;
}
*/

// Using Dynamic Programming (Memoization)
int countStrings(int n) {
    int endsWithZero = 1, endsWithOne = 1, newEndsWithZero = 0, newEndsWithOne = 1;
    
    for(int i = 2; i <= n; i++) {
        newEndsWithZero = endsWithZero + endsWithOne;
        newEndsWithOne = endsWithZero;
        
        endsWithZero = newEndsWithZero;
        endsWithOne = newEndsWithOne;
    }
    
    return endsWithZero + endsWithOne;
}

int main() {
    int n = 3;
    
    cout<<countStrings(n);

    return 0;
}
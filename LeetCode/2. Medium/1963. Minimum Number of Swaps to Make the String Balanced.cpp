#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int minSwaps(string s) {
    int balance = 0, swaps = 0, maxUnbalanced = 0;

    for(char c : s){
        if(c == '[')
            balance++;
        else
            balance--;
        
        if(balance < 0)
            maxUnbalanced = max(maxUnbalanced, -balance);
    }

    return (maxUnbalanced + 1)/2;    
}

int main() {
    string s = "]]][[[";

    cout<<minSwaps(s);
    
    return 0;
}
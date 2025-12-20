#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

bool isPalindrome(int x) {
    string number;

    number = to_string(x);
    int l = 0, r = number.size() - 1;
    
    while(l < r) {
        if(number[l] != number[r])
            return false;
            
        l += 1; r -= 1;
    }

    return true;
}

int main() {
    int x = -121;

    isPalindrome(x) ? cout<<"True" : cout<<"False";

    return 0;
}
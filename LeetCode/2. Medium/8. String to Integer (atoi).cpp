#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int myAtoi(string s) {
    int result = 0, sign = 1, currentDigit = 0;
    size_t index = 0;

    while(index < s.size() && s[index] == ' ')
        index += 1;
    
    if(index < s.size() && (s[index] == '+' || s[index] == '-')) {
        if(s[index] == '-')
            sign = -1;
        
        index += 1;
    }

    while(index < s.size() && isdigit(s[index])) {
        currentDigit = s[index] - '0';

        if(result > (INT_MAX - currentDigit) / 10)
            return sign == 1 ? INT_MAX : INT_MIN;

        result = result * 10 + currentDigit;

        index += 1;
    }

    return sign * result;
}

int main() {
    string s = "42";
    
    cout<<myAtoi(s);

    return 0;
}
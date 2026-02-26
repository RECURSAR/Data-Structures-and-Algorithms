#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

// Iterative Solution
/*
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
*/

// Recursive Solution
int iterate(string &s, size_t i, long long num, int sign) {
    if(i >= s.size() || !isdigit(s[i]))
        return (int)(sign * num);
    
    num = num * 10 + (s[i] - '0');

    if(sign * num <= INT_MIN)
        return INT_MIN;
    if(sign * num >= INT_MAX)
        return INT_MAX;
    
    return iterate(s, i += 1, num, sign);
}

int myAtoi(string s) {
    size_t i = 0;
    int sign = 1;

    while(s[i] == ' ' && i < s.size())
        i += 1;

    if(i < s.size() && (s[i] == '+' || s[i] == '-')) {
        sign = (s[i] == '-') ? -1 : 1;
        i += 1;
    }

    return iterate(s, i, 0, sign);
}

int main() {
    string s = "42";
    
    cout<<myAtoi(s);

    return 0;
}
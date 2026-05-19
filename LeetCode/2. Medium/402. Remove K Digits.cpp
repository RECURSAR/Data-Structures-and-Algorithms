#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

string removeKdigits(string num, int k) {
    string result;

    // Usin string as stack
    for(auto digit : num) {
        char currentDigit = digit;
        
        while(!result.empty() && result.back() > currentDigit && k != 0) {
            result.pop_back();
            k -= 1;
        }

        result.push_back(digit);
    }

    // If more digits can be removed
    result.resize(result.size() - k);

    // Handling edge case
    if(result.empty()) 
        return "0";

    // resultrip leading zeros
    int i = 0;
    while(i < (int)result.size() - 1 && result[i] == '0') 
        i += 1;

    if(i > 0) 
        result.erase(0, i);

    // Edge case
    if(result.empty()) return "0";

    return result;
}

int main() {
    string num = "1432219";
    int k = 3;

    cout<<removeKdigits(num, k);

    return 0;
}
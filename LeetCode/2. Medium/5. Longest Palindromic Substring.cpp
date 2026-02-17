#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

string longestPalindrome(string s) {
    int start = 0, low = 0, high = 0, maxLength = 1, currentLength = 0;

    for(size_t i = 0; i < s.size(); i++) {
        for(size_t j = 0; j <= 1; j++) {
            low = i;
            high = i + j;

            while(low >= 0 && high < s.size() && s[low] == s[high]) {
                currentLength = high - low + 1;

                if(currentLength > maxLength) {
                    start = low;
                    maxLength = currentLength;
                }

                low -= 1;
                high += 1;
            }
        }
    }
    
    return s.substr(start, maxLength);
}

int main() {
    string s = "babad";
    
    cout<<longestPalindrome(s);

    return 0;
}
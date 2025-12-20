#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

bool checkPalindrome(int start, int end, string &cleanedString) {
    if(start >= end)
        return true;
    
    if(cleanedString[start] != cleanedString[end])
        return false;

    return checkPalindrome(start + 1, end - 1, cleanedString);
}

bool isPalindrome(string s) {
    string cleanedString = "";

    for(char c : s) {
        if(isalnum(c))
            cleanedString.push_back(tolower(c));
    }

    int start = 0, end = cleanedString.size() - 1;

    return checkPalindrome(start, end, cleanedString);
}

int main() {
    string s = "A man, a plan, a canal: Panama";
    
    isPalindrome(s) ? cout<<"True" : cout<<"False";

    return 0;
}
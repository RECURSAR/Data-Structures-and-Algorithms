#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

string reverseWords(string s) {
    string result = "", currentWord = "";

    int i = s.size() - 1, end = 0;

    while(i >= 0) {
        // Skipping Spaces at the current position
        while(i >= 0 && s[i] == ' ')
            i -= 1;
        
        if(i < 0)
            break;

        end = i;

        // Move left until a space or start of string is found
        while(i >= 0 && s[i] != ' ')
            i -= 1;
        
        // Extract Current Word
        currentWord = s.substr(i + 1, end - i);

        // Add space before appending next word if result is not empty
        if(!result.empty())
            result += " ";

        result += currentWord;
    }

    return result;
}

int main() {
    string s = "the sky is blue";
    
    cout<<reverseWords(s);

    return 0;
}
#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

string makeFancyString(string s) {
    string result;
    int count = 1;

    result += s[0];

    for(int i = 1; i < s.size(); i++){
        if(s[i] == s[i - 1])
            count++;
        else
            count = 1;
        
        if(count < 3)
            result += s[i];
    }

    return result;
}

int main() {
    string s = "leeetcode";

    cout<<makeFancyString(s);

    return 0;
}
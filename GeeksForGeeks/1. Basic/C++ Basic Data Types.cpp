#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int BasicDataType(string s) {
    if(!isdigit(s[0]) and s[0] != '.')
        return sizeof(char);

    else if(s.find('.') == string::npos)
        return sizeof(int);
        
    else
        return (s.length() - s.find('.') - 1 ) < 6 ? sizeof(float) : sizeof(double);
}

int main() {
    string s = "a";

    cout<<BasicDataType(s);

    return 0;
}
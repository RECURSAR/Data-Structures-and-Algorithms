#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    string s = "IKK PAL BHI CHAIN AAYE NA  ";
    int length = 0, i = s.length() - 1;
        
    while (i >= 0 && s[i] == ' ') {
        i--;
    }
        
    while (i >= 0 && s[i] != ' ') {
        length++;
        i--;
    }

    cout<<length;

    return 0;
}
#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

bool rotateString(string s, string goal) {
    if(s.size() != goal.size())
        return false;
    
    string concatenatedString = s + s;

    return concatenatedString.find(goal) != string::npos;
}

int main() {
    string s = "abcde", goal = "cdeab";

    rotateString(s, goal) ? cout<<"True" : cout<<"False";

    return 0;
}
#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

bool rotateString(string s, string goal) {
    if(s.size() != goal.size())
        return false;
    
    string concatenated_string = s + s;

    return concatenated_string.find(goal) != string::npos;
}

int main() {
    string s = "abcde", goal = "cdeab";

    rotateString(s, goal) ? cout<<"True" : cout<<"False";

    return 0;
}
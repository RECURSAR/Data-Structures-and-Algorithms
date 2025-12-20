#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

long long minimumSteps(string s) {
    int l = 0;
    long long res = 0;

    for(int r = 0; r < s.size(); r++){
        if(s[r] == '0'){
            res += r - l;
            l++;
        }  
    }

    return res;
}

int main() {
    string s = "0111";

    cout<<minimumSteps(s);

    return 0;
}
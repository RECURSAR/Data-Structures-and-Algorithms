#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

bool isIsomorphic(string s, string t) {
    char c1, c2;
    unordered_map<char, char> mpp;
    unordered_set<char> st;

    for(int i = 0; i < s.size(); i++) {
        c1 = s[i];
        c2 = t[i];

        if(mpp.find(c1) != mpp.end()) {
            // Element is mapped to another element which is false
            if(mpp[c1] != c2)
                return false;
        }
        else {
            // Element was mapped to another element but a new mapping appeared which is also false
            if(st.find(c2) != st.end())
                return false;
            
            mpp[c1] = c2;
            st.insert(c2);
        }
    }

    return true;
}

int main() {
    string s = "egg", t = "add";
    
    isIsomorphic(s, t) ? cout<<"True" : cout<<"False";

    return 0;
}
#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int flip(const string& s, int k, const string& direction) {
    int res = 0;
    int pos = 0;
    int opposite = 0;

    for (const char c : s) {
        if (direction.find(c) != string::npos) {
        ++pos;
        } else {
        --pos;
        ++opposite;
        }
        res = max(res, pos + 2 * min(k, opposite));
    }

    return res;
}

int maxDistance(string s, int k) {
    return max({flip(s, k, "NE"), flip(s, k, "NW"), flip(s, k, "SE"), flip(s, k, "SW")});
}

int main() {
    string s = "NWSE";
    int k = 1;
    
    cout<<maxDistance(s, k);

    return 0;
}
#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int minimumLength(string s) {
    vector<int> freq(26);
    int count = 0;

    for(int i = 0; i < s.size(); i++)
        freq[s[i] - 'a'] += 1;
    
    for(int i = 0; i < freq.size(); i++){
        if(freq[i] > 0)
            count += freq[i] % 2 == 0 ? 2 : 1;
    }

    return count;
}

int main() {
    string s = "abaacbcbb";

    cout<<minimumLength(s);

    return 0;
}
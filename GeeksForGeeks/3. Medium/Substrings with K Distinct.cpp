#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int count(string &s, int k) {
    int result = 0, distinctCount = 0, index = 0;
    vector<int> freq(26, 0);

    for(size_t j = 0; j < s.size(); j++) {
        freq[s[j] - 'a'] += 1;

        if(freq[s[j] - 'a'] == 1)
            distinctCount += 1;
        
        while(distinctCount > k) {
            freq[s[index] - 'a'] -= 1;

            if(freq[s[index] - 'a'] == 0)
                distinctCount -= 1;
            
            index += 1;
        }

        result += j - index + 1;
    }

    return result;
}

int countSubstr(string& s, int k) {
    int result = 0;
    
    result = count(s, k) - count(s, k - 1);

    return result;    
}

int main() {
    string s = "abc";
    int k = 2;
    
    cout<<countSubstr(s, k);

    return 0;
}
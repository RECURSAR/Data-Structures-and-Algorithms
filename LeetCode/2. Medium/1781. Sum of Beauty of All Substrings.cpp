#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int beautySum(string s) {
    int freq[26] = {0}, sum = 0, maxi = INT_MIN, mini = INT_MAX;

    for (size_t i = 0; i < s.size(); i++) {
        memset(freq, 0, sizeof(freq));

        for (size_t j = i; j < s.size(); j++) {
            freq[s[j] - 'a'] += 1;

            maxi = INT_MIN;
            mini = INT_MAX;

            for (int k = 0; k < 26; k++) {
                if (freq[k] > 0) {
                    mini = min(mini, freq[k]);
                    maxi = max(maxi, freq[k]);
                }
            }

            sum += maxi - mini;
        }
    }

    return sum;
}

int main() {
    string s = "aabcb";
    
    cout<<beautySum(s);

    return 0;
}
#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int numberOfArrays(vector<int>& differences, int lower, int upper) {
     // Starts from 0, so prefix[0] = 0.
    // Changing prefix[0] to any other number doesn't affect the answer.
    vector<long> prefix(differences.size() + 1);

    for (int i = 0; i < differences.size(); ++i)
      prefix[i + 1] += prefix[i] + differences[i];

    const long mx = *max_element(prefix.begin(), prefix.end());
    const long mn = *min_element(prefix.begin(), prefix.end());
    
    return max(0L, (upper - lower) - (mx - mn) + 1);
}

int main() {
    vector<int> differences = {1,-3,4};
    int lower = 1, upper = 6;

    cout<<numberOfArrays(differences, lower, upper);

    return 0;
}
#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

bool canArrange(vector<int>& arr, int k) {
    vector<int> freq(k, 0);  // To store frequency of remainders
    
    // Fill the frequency array with remainders
    for(int num : arr) {
        int remainder = ((num % k) + k) % k;  // Ensure positive remainder
        freq[remainder]++;
    }
    
    // Check if it's possible to form valid pairs
    for(int i = 1; i < k; ++i) {
        if(freq[i] != freq[k - i]) {
            return false;  // If remainder pairs do not match, return false
        }
    }
    
    // Check for remainder 0 (they must be paired among themselves)
    if(freq[0] % 2 != 0) {
        return false;
    }
    
    // Check for k/2 when k is even (they must be paired among themselves)
    if(k % 2 == 0 && freq[k / 2] % 2 != 0) {
        return false;
    }
    
    return true;
}

int main() {
    vector<int> arr = {9, 7, 5, 3};  // Example test case
    int k = 6;
    
    if(canArrange(arr, k)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}
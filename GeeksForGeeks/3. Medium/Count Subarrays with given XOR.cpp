#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

long subarrayXor(vector<int> &arr, int k) {
    unordered_map<int, int> mpp;
    int prefXOR = 0, ans = 0, need = 0;

    // Base case: prefix XOR = 0 occurs once before array starts
    mpp[0] = 1;

    for(size_t i = 0; i < arr.size(); i++) {
        prefXOR ^= arr[i];

        // If earlier prefix XOR was `need`,
        // then (need ^ prefXOR) = k ⇒ subarray XOR = k
        need = prefXOR ^ k;

        // Add all subarrays ending at i with XOR = k
        ans += mpp[need];

        // Record current prefix XOR for future subarrays
        mpp[prefXOR] += 1;
    }

    return ans;
}

int main() {
    vector<int> arr = {4, 2, 2, 6, 4};
    int k = 6;

    cout<<subarrayXor(arr, k);

    return 0;
}
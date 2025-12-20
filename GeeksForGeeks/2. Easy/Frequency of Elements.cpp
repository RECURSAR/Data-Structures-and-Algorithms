#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

vector<vector<int>> countFreq(vector<int>& arr) {
    unordered_map<int, int> freq;

    // Populated the map;
    for(auto num : arr) {
        freq[num] += 1;
    }
    
    // vector<vector<int>> result;
    // for(auto p : freq) {
    //     vector<int> temp;

    //     temp.push_back(p.first);
    //     temp.push_back(p.second);

    //     result.push_back(temp);
    // }

    vector<vector<int>> result;

    /*
    This avoids TLE for very large test-cases which make the compiler allot 
    new memory for the incoming data. So what we do is that we tell the compiler 
    earlier using reserve() that this much storage is needed atleast, so that 
    it does not have to allocate the memory again and again and simply just allocate 
    it once
    */
    result.reserve(freq.size());

    for(auto p : freq) {
        result.push_back({p.first, p.second});
    }

    return result;
}

int main() {
    vector<int> arr = {1, 2, 2, 3, 3, 5};

    vector<vector<int>> result = countFreq(arr);

    for(auto res : result) {
        for(auto r : res)
            cout<<r<<" ";
        cout<<endl;
    }

    return 0;
}
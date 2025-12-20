#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries){
    /*vector<int> fresult;

    for(auto query: queries){
        int res = arr[query[0]];

        for(int i = query[0] + 1; i <= query[1]; i++)
            res = res ^ arr[i];
        
        fresult.push_back(res);
    }

    return fresult;*/

    // OR a better way is to precompute a prefixXOR array where prefixXOR[i] holds the XOR of all elements from arr[0] to arr[i].

    int n = arr.size();
    vector<int> prefixXOR(n);
    
    // Compute prefix XOR
    prefixXOR[0] = arr[0];
    for (int i = 1; i < n; ++i) 
        prefixXOR[i] = prefixXOR[i - 1] ^ arr[i];
    
    vector<int> result;
    
    // Answer each query using prefix XOR
    for (auto& query : queries) {
        int left = query[0];
        int right = query[1];
        
        if (left == 0) 
            result.push_back(prefixXOR[right]);
        else 
            result.push_back(prefixXOR[right] ^ prefixXOR[left - 1]);
    }

    return result;
}

int main() {
    vector<int> arr = {1,3,4,8};
    vector<vector<int>> queries = {{0,1},{1,2},{0,3},{3,3}};

    vector<int> res = xorQueries(arr,queries);

    for(auto it: res)
        cout<<it<<endl;

    return 0;
}
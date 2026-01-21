#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

vector<int> leaders(vector<int>& arr) {
    vector<int> result;
    int greatest = arr[arr.size() - 1];

    result.push_back(arr[arr.size() - 1]);

    // size_t not used here becasue when i hits zero underflow will happen and we will
    // get a very large value which can lead to segmentation fault
    for(int i = arr.size() - 2; i >= 0; i--) {
        if(arr[i] >= greatest) {
            result.push_back(arr[i]);
            greatest = arr[i];
        }
    }
    
    reverse(result.begin(), result.end());

    return result;
}

int main() {
    vector<int> arr = {16, 17, 4, 3, 5, 2};

    vector<int> result = leaders(arr);
    for(auto num : result)
        cout<<num<<" ";

    return 0;
}
#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

void findSubsets(int index, int currentSum, vector<int> &result, vector<int> &arr) {
    if(index == (int)arr.size()) {
        result.push_back(currentSum);
        return;
    }

    // Pick
    findSubsets(index + 1, currentSum + arr[index], result, arr);

    // Not Pick
    findSubsets(index + 1, currentSum, result, arr);
}

vector<int> subsetSums(vector<int>& arr) {
    vector<int> result;

    findSubsets(0, 0, result, arr);
    sort(result.begin(), result.end());

    return result;
}

int main() {
    vector<int> arr = {2, 3};

    vector<int> result = subsetSums(arr);
    for(auto res : result)
        cout<<res<<" ";

    return 0;
}
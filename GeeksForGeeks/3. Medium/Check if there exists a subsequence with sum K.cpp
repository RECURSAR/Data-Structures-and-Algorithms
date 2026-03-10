#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

bool findSubsequenceSum(int index, int sum, vector<int> &arr, int n) {
    if(sum == 0)
        return true;
    if(index == n || sum < 0)
        return false;
    
    return findSubsequenceSum(index + 1, sum - arr[index], arr, n) || findSubsequenceSum(index + 1, sum, arr, n);
}

bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
    return findSubsequenceSum(0, k, arr, n);
}

int main() {
    int n = 7, k = 8;
    vector<int> arr = {10, 1, 2, 7, 6, 1, 5};

    checkSubsequenceSum(n, arr, k) ? cout<<"True" : cout<<"False";

    return 0;
}
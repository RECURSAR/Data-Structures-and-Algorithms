#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

vector<int> arrayRankTransform(vector<int>& arr) {
    vector<int> sortedArr = arr;  // Create a copy of the original array
    sort(sortedArr.begin(), sortedArr.end());  // Sort the array
    
    unordered_map<int, int> rankMap;  // To store the rank of each unique element
    int rank = 1;  // Rank starts from 1
    
    // Assign ranks to each unique element in the sorted array
    for (int num : sortedArr) {
        if (rankMap.find(num) == rankMap.end()) {  // If the element is not already ranked
            rankMap[num] = rank;
            rank++;
        }
    }
    
    // Replace each element in the original array with its rank
    for (int i = 0; i < arr.size(); ++i) {
        arr[i] = rankMap[arr[i]];
    }
    
    return arr;
}

int main() {
    vector<int> arr = {40, 10, 20, 30};
    vector<int> result = arrayRankTransform(arr);
    
    for (int num : result) {
        cout << num << " ";
    }
    
    return 0;
}
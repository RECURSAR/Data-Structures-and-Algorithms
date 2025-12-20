#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int getSecondLargest(vector<int> &arr) {
    if(arr.size() < 2)
        return -1;
        
    int largest = INT_MIN, secondLargest = largest;

    for(size_t i = 0; i < arr.size(); i++) {
        if(arr[i] > largest) {
            secondLargest = largest;
            largest = max(largest, arr[i]);
        }
        else if(arr[i] > secondLargest && arr[i] != largest){
            secondLargest = arr[i];
        }
    }
    
    // Returning -1 if no second largest number is found
    return (secondLargest == INT_MIN) ? -1 : secondLargest;
}

int main() {
    vector<int> arr = {12, 35, 1, 10, 34, 1};

    cout<<getSecondLargest(arr);

    return 0;
}
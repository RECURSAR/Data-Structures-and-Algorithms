#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

// Iterative
/*
void insertionSort(vector<int>& arr) {
    for(size_t i = 1; i < arr.size(); i++) {
        for(size_t j = i; j > 0; j--) {
            if(arr[j] < arr[j - 1])
                swap(arr[j], arr[j - 1]);
        }
    } 
}
*/

// Recursive
void recursiveInsertionSort(vector<int> &arr, int n) {
    if(n <= 1)
        return;

    recursiveInsertionSort(arr, n - 1);

    int last = arr[n - 1];
    int j = n - 2;

    while(j >= 0 && arr[j] > last) {
        arr[j + 1] = arr[j];
        j -= 1;
    }

    arr[j + 1] = last;
}

void insertionSort(vector<int>& arr) {
    recursiveInsertionSort(arr, arr.size());
}

int main() {
    vector<int> arr = {4, 1, 3, 9, 7};

    insertionSort(arr);
    for(auto num : arr)
        cout<<num<<" ";

    return 0;
}
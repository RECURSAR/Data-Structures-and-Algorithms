#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

// Partition function: places pivot in correct position
// and rearranges elements so that elements smaller than pivot
// are on the left, and elements greater are on the right
int partition(vector<int>& arr, int low, int high) {
    // Choose pivot as the last element
    int pivot = arr[high];

    // i tracks the boundary of "smaller than pivot" region
    int i = low - 1;

    // Loop over all elements except pivot
    for(int j = low; j <= high - 1; j++) {
        // If current element is smaller than pivot
        if(arr[j] < pivot) {
            i += 1;                  // expand "smaller than pivot" region
            swap(arr[i], arr[j]);    // move current element into this region
        }
    }
    
    // Place pivot after the last smaller element
    swap(arr[i + 1], arr[high]);

    // Return pivot index (now in its final sorted position)
    return i + 1;
}

// QuickSort recursive function
void quickSort(vector<int>& arr, int low, int high) {
    // Base case: if array has more than 1 element
    if(low < high) {
        // Partition array and get pivot index
        int pivot = partition(arr, low, high);

        // Recursively sort left sub-array
        quickSort(arr, low, pivot - 1);

        // Recursively sort right sub-array
        quickSort(arr, pivot + 1, high);
    }
}

int main() {
    vector<int> arr = {4, 1, 3, 9, 7};
    
    quickSort(arr, 0, arr.size() - 1);

    for(auto num : arr)
        cout<<num<<" ";

    return 0;
}
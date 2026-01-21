#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

// Iterative
// void bubbleSort(vector<int>& arr) {
//     for(size_t i = 0; i < arr.size() - 1; i++) {
//         // Sorted element goes at the last
//         for(size_t j = 0; j < arr.size() - i - 1; j++) {
//             if(arr[j + 1] < arr[j])
//                 swap(arr[j + 1], arr[j]);
//         }
//     }
// }

// Recursive
void recursiveBubbleSort(vector<int> &arr, int n) {
    if(n == 1)
        return;

    // For Optimization, if no swaps happened then that means the arary is sorted.
    int count = 0;

    for(int i = 0; i < n - 1; i++) {
        if(arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
            count += 1;
        }
    }

    if(count == 0)
        return;

    recursiveBubbleSort(arr, n - 1);
}

void bubbleSort(vector<int>& arr) {
    recursiveBubbleSort(arr, arr.size());
}

int main() {
    vector<int> arr = {4, 1, 3, 9, 7};

    bubbleSort(arr);
    for(auto num : arr)
        cout<<num<<" ";

    return 0;
}
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void merge(vector<int> &arr, int left, int middle, int right) {
    // Sizes of the two halves
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Temporary arrays
    vector<int> L(n1), R(n2);

    // Copy data to temp arrays
    for(int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for(int j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    // Merge temp arrays back into arr
    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2) {
        // Pick smaller value from L or R
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i += 1;
        }        
        else {
            arr[k] = R[j];
            j += 1;
        }

        k += 1;
    }

    // Copy remaining elements of L (if any)
    while(i < n1) {
        arr[k] = L[i];
        i += 1;
        k += 1;
    }
        
    // Copy remaining elements of R (if any)
    while(j < n2) {
        arr[k] = R[j];
        j += 1;
        k += 1;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    // Base case: single element
    if(left >= right)
        return;

    // Middle of the array
    int middle = left + (right - left) / 2;

    // Sort left half
    mergeSort(arr, left, middle);

    // Sort right half
    mergeSort(arr, middle + 1, right);

    // Merge sorted halves
    merge(arr, left, middle, right);
}

int main() {
    vector<int> arr = {4, 1, 3, 9};

    mergeSort(arr, 0, arr.size() - 1);

    for(int num : arr)
        cout << num << " ";

    return 0;
}

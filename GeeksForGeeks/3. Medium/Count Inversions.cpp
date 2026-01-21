#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int mergeLike(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low, right = mid + 1;    // left and right are starting index of left and right subarray
    int inversions = 0;

    while(left <= mid && right <= high) {
        if(arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left += 1;
        }
        else {
            temp.push_back(arr[right]);
            inversions += (mid - left + 1);     // All remaining left elements are inversions
            right += 1;
        }
    }

    while(left <= mid) {
        temp.push_back(arr[left]);
        left += 1;
    }

    while(right <= high) {
        temp.push_back(arr[right]);
        right += 1;
    }

    for(int i = low; i <= high; i++)
        arr[i] = temp[i - low];

    return inversions;
}

int mergeSortLike(vector<int> &arr, int low, int high) {
    int inversions = 0, mid = 0;

    if(low >= high)
        return inversions;

    mid = (low + high) / 2;

    // Inversions in left half
    inversions += mergeSortLike(arr, low, mid);

    // Inversions in right half
    inversions += mergeSortLike(arr, mid + 1, high);

    // Inversions during merge
    inversions += mergeLike(arr, low, mid, high);

    return inversions;
}

int inversionCount(vector<int> &arr) {
    return mergeSortLike(arr, 0, arr.size() - 1);
}

int main() {
    vector<int> arr = {2, 4, 1, 3, 5};

    cout<<inversionCount(arr);

    return 0;
}
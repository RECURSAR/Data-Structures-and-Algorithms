#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

void selectionSort(vector<int> &arr) {
    for(size_t i = 0; i < arr.size() - 1; i++) {
        int minIndex = i;

        for(size_t j = i + 1; j < arr.size(); j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    vector<int> arr = {4, 1, 3, 9, 7};

    selectionSort(arr);

    for(auto num : arr)
        cout<<num<<" ";

    return 0;
}
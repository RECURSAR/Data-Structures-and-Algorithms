#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

void recursiveReverse(int start, int end, vector<int> &arr) {
    if(start > end)
        return;

    swap(arr[start], arr[end]);

    recursiveReverse(start + 1, end - 1, arr);
}

void reverseArray(vector<int> &arr) {
    int start = 0, end = arr.size() - 1;    

    recursiveReverse(start, end, arr);
}

int main() {
    vector<int> arr = {1, 4, 3, 2, 6, 5};

    reverseArray(arr);

    for(auto number : arr)
        cout<<number<<" ";

    return 0;
}
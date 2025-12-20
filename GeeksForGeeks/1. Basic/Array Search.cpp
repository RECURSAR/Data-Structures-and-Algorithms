#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int search(vector<int>& arr, int x) {
    int index = -1;

    for(size_t i = 0; i < arr.size(); i++) {
        if(arr[i] == x) {
            index = i;
            return index;
        }
    }

    return index;
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    int x = 3;

    cout<<search(arr, x);

    return 0;
}
#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int largest(vector<int> &arr) {
    int largest = INT_MIN;

    for(size_t i = 0; i < arr.size(); i++) {
        if(arr[i] > largest)
            largest = max(arr[i], largest);
    }

    return largest;
}

int main() {
    vector<int> arr = {1, 8, 7, 56, 90};

    cout<<largest(arr);

    return 0;
}
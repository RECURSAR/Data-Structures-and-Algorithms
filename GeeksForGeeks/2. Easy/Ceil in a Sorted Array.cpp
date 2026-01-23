#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int findCeil(vector<int>& arr, int x) {
    int low = 0, mid = 0, high = arr.size() - 1, ceilIndex = -1;
    
    while(low <= high) {
        mid = (low + high) / 2;

        if(arr[mid] >= x) {
            ceilIndex = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return ceilIndex;
}

int main() {
    vector<int> arr = {1, 2, 8, 10, 10, 12, 19};
    int x= 5;

    cout<<findCeil(arr, x);

    return 0;
}
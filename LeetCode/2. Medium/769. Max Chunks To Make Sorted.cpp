#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int maxChunksToSorted(vector<int>& arr) {
    int ans = 0;
    int mx = INT_MIN;

    for (int i = 0; i < arr.size(); ++i) {
      mx = max(mx, arr[i]);
      if (mx == i)
        ++ans;
    }

    return ans;   
}

int main() {
    vector<int> arr = {4,3,2,1,0};

    cout<<maxChunksToSorted(arr);

    return 0;
}
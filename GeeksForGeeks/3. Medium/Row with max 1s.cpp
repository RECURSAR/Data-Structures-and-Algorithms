#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int rowWithMax1s(vector<vector<int>> &arr) {
    int low = 0, mid = 0, high = arr[0].size() - 1, 
        currentOnes = 0, maxOnes = 0, result = -1;

    for(size_t i = 0; i < arr.size(); i++) {
        low = 0, high = arr[i].size() - 1, currentOnes = 0;

        while(low <= high) {
            mid = low + (high - low) / 2;

            if(arr[i][mid] == 1) {
                if(arr[i][mid - 1] != 1 || mid == 0) {
                    currentOnes = arr[i].size() - mid;
                    break;
                }

                high = mid - 1;
            }
            else
                low = mid + 1;
        }

        if(currentOnes > maxOnes) {
            maxOnes = currentOnes;
            result = i;
        }
    }

    return result;
}

int main() {
    vector<vector<int>> arr = {{0, 1, 1, 1}, {0, 0, 1, 1}, {1, 1, 1, 1}, {0, 0, 0, 0}};

    cout<<rowWithMax1s(arr);

    return 0;
}
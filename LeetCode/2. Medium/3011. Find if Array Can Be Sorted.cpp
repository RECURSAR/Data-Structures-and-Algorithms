#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

bool canSortArray(vector<int>& nums) {
    int prevSetBits = -1, prevSegMax = INT_MIN, currentSegMax = INT_MIN, currentSegMin = INT_MAX; 
    
    for(auto num : nums){
        int setBits = __builtin_popcount(num);          // Calculates set bits
        
        // New Segment
        if(setBits != prevSetBits){
            if(prevSegMax > currentSegMin)
                return false;
            
            prevSetBits = setBits;
            prevSegMax = currentSegMax;
            currentSegMax = num;
            currentSegMin = num;
        } 
        
        else {
            currentSegMax = max(currentSegMax, num);
            currentSegMin = min(currentSegMin, num);
        }
    }

    return prevSegMax <= currentSegMin;
}

int main() {
    vector<int> nums = {8,4,2,30,15};

    canSortArray(nums) ? cout<<"True" : cout<<"False";

    return 0;
}
#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

long long maximumTripletValue(vector<int>& nums) {
    long long maxVal = 0;

    for(int i = 0; i < nums.size(); i++){
        for(int j = i + 1; j < nums.size(); j++){
            for(int k = j + 1; k < nums.size(); k++){
                long long temp = (long long)(nums[i] - nums[j]) * nums[k];
                maxVal = max(maxVal, temp);
            }
        }
    }
        
    return maxVal;
}

int main() {
    vector<int> nums = {12,6,1,2,7};

    cout<<maximumTripletValue(nums);

    return 0;
}
#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

bool check(vector<int>& nums) {
    int inversions = 0;
    
    for(size_t i = 0; i < nums.size(); i++){
        if(nums[i] > nums[(i+1) % nums.size()])
            inversions += 1;

        if(inversions > 1)
            return false;
    }

    return true;
}

int main() {
    vector<int> nums = {3, 4, 5, 1, 2};

    check(nums) ? cout<<"True" : cout<<"False";

    return 0;
}
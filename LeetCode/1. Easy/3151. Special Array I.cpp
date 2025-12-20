#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

bool isArraySpecial(vector<int>& nums) {
    for (int i = 1; i < nums.size(); ++i)
        if (nums[i] % 2 == nums[i - 1] % 2)
            return false;

    return true;
}

int main() {
    vector<int> nums = {2, 1, 4};

    isArraySpecial(nums) ? cout<<"True" : cout<<"False";

    return 0;
}
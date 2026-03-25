#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

vector<int> singleNumber(vector<int>& nums) {
    long XOR = 0;

    for(size_t i = 0; i < nums.size(); i++)
        XOR = XOR ^ nums[i];
    
    long long rightmostBit = (XOR & (XOR - 1)) ^ XOR;
    int XOR1 = 0, XOR2 = 0;

    for(size_t i = 0; i < nums.size(); i++) {
        if(nums[i] & rightmostBit)
            XOR1 = XOR1 ^ nums[i];
        else
            XOR2 = XOR2 ^ nums[i];
    }

    return {XOR1, XOR2};
}

int main() {
    vector<int> nums = {1, 2, 1, 3, 2, 5};
    
    vector<int> result = singleNumber(nums);
    for(auto res : result)
        cout<<res<<" ";

    return 0;
}
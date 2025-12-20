#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int maximumCount(vector<int>& nums) {
    return max(count_if(nums.begin(), nums.end(), [](int num) { return num > 0; }), count_if(nums.begin(), nums.end(), [](int num) { return num < 0; }));
}

int main() {
    vector<int> nums = {-2,-1,-1,1,2,3};

    cout<<maximumCount(nums);

    return 0;
}
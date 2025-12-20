#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

string findDifferentBinaryString(vector<string>& nums) {
    string ans;

    // Flip the i-th bit for each nums[i] so that `ans` is unique.
    for (int i = 0; i < nums.size(); ++i)
      ans += nums[i][i] == '0' ? '1' : '0';

    return ans;  
}

int main() {
    vector<string> nums = {"01","10"};
    
    cout<<findDifferentBinaryString(nums);

    return 0;
}
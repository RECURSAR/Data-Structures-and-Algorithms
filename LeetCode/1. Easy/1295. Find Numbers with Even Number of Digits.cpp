#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int findNumbers(vector<int>& nums) {
    int ans = 0;

    for (int num : nums)
      if (9 < num && num < 100 || 999 < num && num < 10000 || num == 100000)
        ++ans;

    return ans;    
}

int main() {
    vector<int> nums = {12,345,2,6,7896};

    cout<<findNumbers(nums);

    return 0;
}
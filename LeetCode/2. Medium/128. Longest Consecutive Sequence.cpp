#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int longestConsecutive(vector<int>& nums) {
    if(nums.empty())
        return 0;

    int longest = 1;
    unordered_set<int> set;
    
    for(auto num : nums)
        set.insert(num);
    
    for(auto num : set) {
        if(set.find(num - 1) == set.end()) {
            int count = 1;
            int currNum = num;

            while(set.find(currNum + 1) != set.end()) {
                count += 1;
                currNum += 1;
            }
                
            longest = max(longest, count);
        }
    }

    return longest;
}

int main() {
    vector<int> nums = {100,4,200,1,3,2};
    
    cout<<longestConsecutive(nums);

    return 0;
}
#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int longestConsecutive(vector<int>& nums) {
    if(nums.size() == 0)
        return 0;
    
    int longest = 1, localLongest = 1, currentNumber = 0;
    unordered_set<int> st;

    // Populating Set
    for(auto num : nums)
        st.insert(num);

    for(auto num : st) {
        // Find a starting point to avoid Re-Calculation
        if(st.find(num + 1) == st.end()) {
            localLongest = 1;
            currentNumber = num;

            while(st.find(currentNumber - 1) != st.end()) {
                localLongest += 1;
                currentNumber -= 1;
            }

            longest = max(longest, localLongest);   
        }
    }

    return longest;
}

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    
    cout<<longestConsecutive(nums);

    return 0;
}
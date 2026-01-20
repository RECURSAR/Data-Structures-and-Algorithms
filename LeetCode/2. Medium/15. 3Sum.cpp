#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

// Using a Hash Set (2 Sum Variation)
/*
vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int>> st;
    vector<vector<int>> result;
    int thirdNumber = 0;

    for(size_t i = 0; i < nums.size(); i++) {
        set<int> hashset;
        for(size_t j = i + 1; j < nums.size(); j++) {
            // a + b + c = 0. This means that a = - (b + c).
            // We are using this same principle to find the missing number
            // If we don't find it then we will just place it in a set
            thirdNumber = -(nums[i] + nums[j]);
            if(hashset.find(thirdNumber) != hashset.end()) {
                vector<int> temp = {nums[i], nums[j], thirdNumber};
                // Sorting this vector so that when this thing goes inside a set
                // so we are able to know if these numbers are unique or not
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(nums[j]);
        }
    }
    
    result = vector<vector<int>>(st.begin(), st.end());

    return result;
}*/

// Optimal Way
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    int sum = 0;
    size_t j, k = nums.size() - 1;

    sort(nums.begin(), nums.end());

    // i is fixed pointer
    for(size_t i = 0; i < nums.size(); i++) {
        if(i > 0 && nums[i] == nums[i - 1])
            continue;

        j = i + 1;
        k = nums.size() - 1;

        while(j < k) {
            sum = nums[i] + nums[j] + nums[k];
            // To increment it to zero we will go to right in sorted array
            if(sum < 0)
                j += 1;
            // To decrement it to zero we will go to left in sorted array
            else if(sum > 0)
                k -= 1;
            else {
                vector<int> temp = {nums[i], nums[j], nums[k]};
                result.push_back(temp);

                j += 1;
                k -= 1;
                
                // Duplicate element then skip it
                while(j < k && nums[j] == nums[j - 1])
                    j += 1;
                
                // Duplicate element then skip it
                while(j < k && nums[k] == nums[k + 1])
                    k -= 1;
            }
        }
    }

    return result;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    
    vector<vector<int>> result = threeSum(nums);
    for(auto row : result) {
        for(auto num : row)
            cout<<num;
        cout<<endl;
    }

    return 0;
}
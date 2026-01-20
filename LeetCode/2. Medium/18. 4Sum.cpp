#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    size_t j = 1, k = j + 1, l = nums.size() - 1;
    long long sum = 0;

    sort(nums.begin(), nums.end());

    for(size_t i = 0; i < nums.size(); i++) {
        if(i > 0 && nums[i] == nums[i - 1])
            continue;
        
            for(j = i + 1; j < nums.size(); j++) {
                if(j != (i + 1) && nums[j] == nums[j - 1])
                    continue;

                k = j + 1;
                l = nums.size() - 1;

                while(k < l) {
                    sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];

                    if(sum < target)
                        k += 1;
                    else if(sum > target)
                        l -= 1;
                    else {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        result.push_back(temp);

                        k += 1;
                        l -= 1;

                        while(k < l && nums[k] == nums[k - 1])
                            k += 1;

                        while(j < l && nums[l] == nums[l + 1])
                            l -= 1;
                    }
                }
            }
    }

    return result;
}

int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    
    vector<vector<int>> result = fourSum(nums, target);
    for(auto row : result) {
        for(auto num : row)
            cout<<num<<" ";
        cout<<endl;
    }

    return 0;
}
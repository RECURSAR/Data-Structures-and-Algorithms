#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int maxProduct(vector<int>& nums) {
    int prefixProduct = 1, suffixProduct = 1, result = INT_MIN;

    for(size_t i = 0; i < nums.size(); i++) {
        if(prefixProduct == 0)
            prefixProduct = 1;

        if(suffixProduct == 0)
            suffixProduct = 1;

        prefixProduct *= nums[i];
        suffixProduct *= nums[nums.size() - i - 1];

        result = max(result, max(prefixProduct, suffixProduct));
    }
    
    return result;
}

int main() {
    vector<int> nums = {2, 3, -2, 4};
    
    cout<<maxProduct(nums);

    return 0;
}
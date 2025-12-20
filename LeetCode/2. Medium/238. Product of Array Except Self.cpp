#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> nums = {-1,1,0,-3,3};
    int n = nums.size();
    vector<int> result(n, 1);

    int prefix = 1;
    for (int i = 0; i < n; i++) {
        result[i] = result[i] * prefix;
        prefix = prefix * nums[i];
    }

    int postfix = 1;
    for (int i = n - 1; i >= 0; i--) {
        result[i] = result[i] * postfix;
        postfix = postfix * nums[i];
    }

    for(int j = 0; j < result.size(); j++)
        cout<<result[j]<<" ";  

    return 0;
}
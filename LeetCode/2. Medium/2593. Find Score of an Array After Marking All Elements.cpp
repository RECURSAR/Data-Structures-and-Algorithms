#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

long long findScore(vector<int>& nums) {
    long ans = 0;
    set<pair<int, int>> numAndIndices;
    vector<bool> seen(nums.size());

    for (int i = 0; i < nums.size(); ++i)
        numAndIndices.insert({nums[i], i});

    for (const auto& p : numAndIndices) {
        int num = p.first;
        int i = p.second;
        if (seen[i])
            continue;
        if (i > 0)
            seen[i - 1] = true;
        if (i + 1 < nums.size())
            seen[i + 1] = true;
        seen[i] = true;
        ans += num;
    }

    return ans;
}

int main() {
    vector<int> nums = {2,1,3,4,5,2};

    cout<<findScore(nums);

    return 0;
}
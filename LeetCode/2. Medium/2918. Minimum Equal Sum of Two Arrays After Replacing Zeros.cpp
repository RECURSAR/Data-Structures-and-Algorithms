#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

long long minSum(vector<int>& nums1, vector<int>& nums2) {
    const long sum1 = accumulate(nums1.begin(), nums1.end(), 0L);
    const long sum2 = accumulate(nums2.begin(), nums2.end(), 0L);
    const int zero1 = std::count(nums1.begin(), nums1.end(), 0);
    const int zero2 = std::count(nums2.begin(), nums2.end(), 0);
    
    if (zero1 == 0 && sum1 < sum2 + zero2)
      return -1;

    if (zero2 == 0 && sum2 < sum1 + zero1)
      return -1;

    return max(sum1 + zero1, sum2 + zero2);
}

int main() {
    vector<int> nums1 = {3,2,0,1,0}, nums2 = {6,5,0};

    cout<<minSum(nums1, nums2);

    return 0;
}
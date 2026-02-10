#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if(nums1.size() > nums2.size())
        return findMedianSortedArrays(nums2, nums1);
    
    size_t n1 = nums1.size(), n2 = nums2.size();
    int low = 0, high = n1, cut1 = 0, cut2 = 0;
    double left1 = 0, left2 = 0, right1 = 0, right2 = 0;
    
    while(low <= high) {
        cut1 = low + (high - low) / 2;
        cut2 = (n1 + n2 + 1) / 2 - cut1;

        left1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
        left2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
        right1 = (cut1 == (int)n1) ? INT_MAX : nums1[cut1];
        right2 = (cut2 == (int)n2) ? INT_MAX : nums2[cut2];

        // Valid Partition
        if(left1 <= right2 && left2 <= right1) {
            if((n1 + n2) % 2 == 0)
                return ((max(left1, left2) + min(right1, right2)) / 2);
            else
                return max(left1, left2);
        }
        else if(left1 > right2)
            high = cut1 - 1;
        else
            low = cut1 + 1;
    }

    return 0.0;
}

int main() {
    vector<int> nums1 = {1, 3}, nums2 = {2};
    
    cout<<findMedianSortedArrays(nums1, nums2);

    return 0;
}
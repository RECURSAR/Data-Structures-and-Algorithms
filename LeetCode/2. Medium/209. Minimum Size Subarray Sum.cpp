#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7, l= 0, sum = 0, length = INT_MAX;

    for(int r = 0; r < nums.size(); r++){
        sum += nums[r];
        // While loop used beause we should keep incrementing l until we found the result   
        while(sum >= target){
            length = min(r - l + 1, length);
            sum = sum - nums[l];
            l++;
        }
    }

    if(length==INT_MAX)
        cout<<"0";
    else
        cout<<length;
              
   return 0;
}
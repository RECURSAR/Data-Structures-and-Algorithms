#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

// 1st solution
/*
int main()
{
    vector<int> nums = {1,2,3,1,2,3}; 
    int k = 2;
    map<int, int> numToIndex;
    bool result;

    for(int i = 0; i < nums.size(); i++){
        if(numToIndex.find(nums[i]) != numToIndex.end() && abs(numToIndex[nums[i]] - i) <= k){
            result = true;
            cout<<result<<endl;
            exit(0);
        }

        numToIndex[nums[i]] = i;
    }

    result = false;
    cout<<result<<endl;

   return 0;
}
*/

// 2nd solution - Sliding Window
int main(){
    vector<int> nums = {1,2,3,1,2,3}; 
    int k = 2, l = 0, r = 0;
    set<int> num;
    bool result;

    for(r = 0; r<nums.size(); r++){
        if(r - l > k){
            num.erase(nums[l]);
            l++;
        }   

        if(num.find(nums[r]) != num.end()){
            result = true;
            cout<<result<<endl;
            exit(0);
        }

        num.insert(nums[r]);
    }

    result = false;
    cout<<result<<endl;
    
    return 0;
}
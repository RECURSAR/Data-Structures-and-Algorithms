#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

bool divideArray(vector<int>& nums) {
    vector<int> count(501);

    for (const int num : nums)
      ++count[num];
    return all_of(count.begin(), count.end(), [](int c) { return c % 2 == 0; });       
}

int main() {
    vector<int> nums = {3,2,3,2,2,2};

    divideArray(nums) ? cout<<"True" : cout<<"False";

    return 0;
}
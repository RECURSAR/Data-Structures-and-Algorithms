#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;
 
int maximumSwap(int num) {
    string nums = to_string(num);
    char max_digit = '0';
    int max_i = -1;
    int swap_i = -1, swap_j = -1;

    for(int i = nums.size() - 1; i >= 0; i--){
        if(nums[i] > max_digit){
            max_digit = nums[i];
            max_i = i;
        }
        else if(nums[i] < max_digit){
            swap_i = i;
            swap_j = max_i;
        }
    }

    if(swap_i != -1)
        swap(nums[swap_i],nums[swap_j]);
    
    return stoi(nums);
}

int main() {
    int num = 2736;

    cout<<maximumSwap(num);

    return 0;
}
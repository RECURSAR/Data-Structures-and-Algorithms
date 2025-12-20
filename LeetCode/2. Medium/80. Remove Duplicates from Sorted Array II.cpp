#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> nums = {1,1,1,2,2,2,3,3,3};
    int l = 0;
    int r = 0;
        
    while (r < nums.size()) {
        int count = 1;
        while (r + 1 < nums.size() && nums[r] == nums[r + 1]) {
            r++;
            count++;
        }
        
        for (int i = 0; i < std::min(2, count); i++) {
            nums[l] = nums[r];
            l++;
        }
        
        r++;
    }

    for(int i = 0; i<l; i++){
        cout<<nums[i]<<" ";
    }
    
    return 0;
}
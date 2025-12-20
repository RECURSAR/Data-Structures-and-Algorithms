#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
 
using namespace std;
 
int main()
{
    vector<int> nums = {3,2,1,0,4};
    int goal = nums.size() - 1;

    for(int i = nums.size()-1; i>0; i--){
        if(i + nums[i] >= goal){
            goal--;
        }
    }

    cout<<goal;

    return 0;
}
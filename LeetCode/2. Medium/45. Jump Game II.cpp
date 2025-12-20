#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
 
using namespace std;
 
int main()
{
    vector<int> nums = {2,3,0,1,4};
    int min_steps = 0, l=0, r=0, max_jump = 0;
    
    while(r < nums.size()-1){
        max_jump = 0;

        for(int i=l; i<r+1; i++)
            max_jump = max(max_jump, i + nums[i]);
        
        l = r + 1;
        r = max_jump;
        min_steps++;
    }

    cout<<min_steps;

    return 0;
}
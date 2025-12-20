#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> nums = {3,2,2,3};
    int val = 3, k = 0;  

    cout<<nums.size()<<endl;

    for(int i = 0; i < nums.size(); i++){
        if(val != nums[i]){
            nums[k] = nums[i];
            k++;
        }
    }
        
    cout<<k<<endl;

    for(int i = 0; i < k; i++){
        cout<<nums[i]<<" ";
    }
    
    return 0;
}
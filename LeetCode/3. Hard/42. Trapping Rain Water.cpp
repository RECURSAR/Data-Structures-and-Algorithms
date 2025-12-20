#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    vector<int> height = {4,2,0,3,2,5};
    int i=0, j=height.size()-1, leftMax = height[i], rightMax = height[j], sum = 0;

    if(height.size()==0)
        return 0;

    while(i < j){
        if(leftMax < rightMax){
            i++;
            leftMax = max(leftMax, height[i]);
            sum = sum + leftMax - height[i];
        }
        else{
            j--;
            rightMax = max(rightMax, height[j]);
            sum = sum + rightMax - height[j];
        }
    }

    cout<<sum;
    
    return 0;
}
#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

// Using maxPrefix and maxSuffix
/*
int trap(vector<int>& height) {
    int n = height.size(), water = 0;;
    if(n == 0)
        return 0;

    vector<int> prefixMax(n), suffixMax(n);

    // Max Height from Left 
    prefixMax[0] = height[0];
    for(int i = 1; i < n; i++)
        prefixMax[i] = max(prefixMax[i - 1], height[i]);

    // Max Height from Right
    suffixMax[n - 1] = height[n - 1];
    for(int i = n - 2; i >= 0; i--)
        suffixMax[i] = max(suffixMax[i + 1], height[i]);
    
    // Trapped rainwater at each index
    for(int i = 0; i < n; i++)
        water += min(prefixMax[i], suffixMax[i]) - height[i];

    return water;
}
*/

// Using 2 Pointers
int trap(vector<int>& height) {
    int left = 0, right = height.size() - 1, 
        maxLeft = 0, maxRight = 0, 
        water = 0;

    while(left < right) {
        if(height[left] <= height[right]) {
            // Left side is BottleNeck
            if(height[left] >= maxLeft)
                maxLeft = height[left];
            else
                water += maxLeft - height[left];
            
            left += 1;
        }
        else {
            // Right side is BottleNeck
            if(height[right] >= maxRight)
                maxRight = height[right];
            else
                water += maxRight - height[right];
            
            right -= 1;
        }
    }

    return water;
}

int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};  

    cout<<trap(height)<<endl;

    return 0;
}
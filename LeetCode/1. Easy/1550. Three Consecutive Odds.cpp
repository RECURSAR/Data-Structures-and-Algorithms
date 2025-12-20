#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

bool threeConsecutiveOdds(vector<int>& arr) {
    if(arr.size() < 3)
        return false;
    
    int count = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] % 2 != 0)
            count += 1;
        else
            count = 0;
        
        if(count == 3)
            return true;
    }

    return false;
}

int main() {
    vector<int> arr = {2,6,4,1};

    threeConsecutiveOdds(arr) ? cout<<"True" : cout<<"False";

    return 0;
}
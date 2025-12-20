#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

bool checkIfExist(vector<int>& arr) {
    unordered_set<int> seen;

    for(int num : arr){
        if(seen.count(2 * num) || (num % 2 == 0 && seen.count(num / 2)))
            return true;
            
        seen.insert(num);
    }

    return false;
}

int main() {
    vector<int> arr = {10,2,5,3};

    checkIfExist(arr) ? cout<<"True" : cout<<"False";

    return 0;
}
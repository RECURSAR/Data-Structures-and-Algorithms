#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    
}

int main() {
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    rotate(matrix);
    for(auto nums : matrix) {
        for(auto num : nums)
            cout<<num<<" ";
        cout<<endl;
    }

    return 0;
}
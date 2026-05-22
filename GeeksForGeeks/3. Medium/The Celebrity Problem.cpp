#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int celebrity(vector<vector<int>>& mat) {
    int candidate = 0;
    for(size_t i = 1; i < mat.size(); i++) {
        if(mat[candidate][i] == 1)
            candidate = i;
    }

    for(size_t i = 0; i < mat.size(); i++) {
        if(i == candidate)
            continue;
        
        // Celebrity must NOT know any one
        if(mat[candidate][i] == 1)
            return -1;

        // Celebrity must be known by EVERYONE
        if(mat[i][candidate] == 0)
            return -1;
    }

    return candidate;
}

int main() {
    vector<vector<int>> mat = {{1, 1, 0},
                               {0, 1, 0},
                               {0, 1, 1}
                            };

    cout<<celebrity(mat);

    return 0;
}
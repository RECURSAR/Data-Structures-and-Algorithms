#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

void findCombinations(int index, vector<int> current, vector<vector<int>> &result, vector<int> &candidates, int target) {
    if(target == 0) {
        result.push_back(current);
            return;
    }

    for(int i = index; i < (int)candidates.size(); i++) {
        // Skip Duplicate
        if(i > index && candidates[i] == candidates[i - 1])
            continue;
        
        if(candidates[i] > target)
            break;
        
        current.push_back(candidates[i]);
        findCombinations(i + 1, current, result, candidates, target - candidates[i]);
        current.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> result;

    sort(candidates.begin(), candidates.end());
    findCombinations(0, {}, result, candidates, target);
    
    return result; 
}

int main() {
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    
    vector<vector<int>> result = combinationSum2(candidates, target);
    for(auto res : result) {
        for(auto r : res)
            cout<<r<<" ";
        cout<<endl;
    }

    return 0;
}
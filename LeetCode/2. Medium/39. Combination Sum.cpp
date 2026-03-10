#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

// Recursive Solution
/*
void findCombinations(int index, vector<int> current, vector<vector<int>> &result, vector<int> &candidates, int target) {
    if(target == 0) {
        result.push_back(current);
        return;
    }

    if(index == (int)candidates.size() || target < 0)
        return;
    
    // Pick
    current.push_back(candidates[index]);
    findCombinations(index, current, result, candidates, target - candidates[index]);
    current.pop_back();

    // Not Pick
    findCombinations(index + 1, current, result, candidates, target);
}
*/

// Recursive Solution - Slightly Better than Previous
void findCombinations(int index, vector<int> current, vector<vector<int>> &result, vector<int> &candidates, int target) {
    if(index == (int)candidates.size()) {
        if(target == 0)
            result.push_back(current);
        return;
    }

    // Pick
    if(candidates[index] <= target) {
        current.push_back(candidates[index]);
        findCombinations(index, current, result, candidates, target - candidates[index]);
        current.pop_back();
    }

    // Skip
    findCombinations(index + 1, current, result, candidates, target);
}


vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;

    findCombinations(0, {}, result, candidates, target);

    return result;
}

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result = combinationSum(candidates, target);
    for(auto res : result) {
        for(auto r : res)
            cout<<r<<" ";
        cout<<endl;
    }

    return 0;
}
#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

// Recursive Solution
/*
void findCombinations(int choice, vector<int> current, vector<vector<int>> &result, int k, int n) {
    if(n == 0 && (int)current.size() == k) {
        result.push_back(current);
        return;
    }

    for(int i = choice; i < 10; i++) {
        if(i > n || (int)current.size() > k)
            break;
        
        
        if((int)current.size() <= k) {
            current.push_back(i);
            findCombinations(i + 1, current, result, k, n - i);
            current.pop_back();
        }
        else
            break;
    }
}
*/

// Recursive Solution - Slightly Better than Previous
void findCombinations(int choice, vector<int> current, vector<vector<int>> &result, int k, int n) {
    if(n == 0 && (int)current.size() == k) {
        result.push_back(current);
        return;
    }

    if(n <= 0 || (int)current.size() > k)
        return;

    for(int i = choice; i <= 9; i++) {
        if(i <= n) {
            current.push_back(i);
            findCombinations(i + 1, current, result, k, n - i);
            current.pop_back();
        }
        else
            break;
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> result;

    findCombinations(1, {}, result, k, n);

    return result;
}

int main() {
    int k = 3, n = 7;
    
    vector<vector<int>> result = combinationSum3(k, n);
    for(auto res : result) {
        for(auto r : res)
            cout<<r<<" ";
        cout<<endl;
    }

    return 0;
}
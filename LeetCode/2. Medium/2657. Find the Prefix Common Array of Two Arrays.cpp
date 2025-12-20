#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    const int n = A.size();
    int prefixCommon = 0;
    vector<int> ans;
    vector<int> count(n + 1);

    for (int i = 0; i < A.size(); ++i) {
      if (++count[A[i]] == 2)
        ++prefixCommon;

      if (++count[B[i]] == 2)
        ++prefixCommon;
        
      ans.push_back(prefixCommon);
    }

    return ans; 
}

int main() {
    vector<int> A = {1,3,2,4}, B = {3,1,2,4};

    vector<int> result = findThePrefixCommonArray(A, B);
    for(auto res : result)
        cout<<res<<" ";

    return 0;
}
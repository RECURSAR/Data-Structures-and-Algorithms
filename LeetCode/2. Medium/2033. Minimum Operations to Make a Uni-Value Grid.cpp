#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int minOperations(vector<vector<int>>& grid, int x) {
    vector<int> arr;
    for (const vector<int>& row : grid)
      arr.insert(arr.end(), row.begin(), row.end());
    if (std::any_of(arr.begin(), arr.end(), [&](int a) { return (a - arr[0]) % x; }))
      return -1;

    int ans = 0;

    nth_element(arr.begin(), arr.begin() + arr.size() / 2, arr.end());

    for (const int a : arr)
      ans += abs(a - arr[arr.size() / 2]) / x;

    return ans;
}

int main() {
    vector<vector<int>> grid = {{2,4},{6,8}};
    int x = 2;

    cout<<minOperations(grid, x);

    return 0;
}
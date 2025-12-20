#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

long long maxKelements(vector<int>& nums, int k) {
    priority_queue<int> heap(nums.begin(), nums.end());
    long long score = 0;

    while (k > 0) {
        int top = heap.top();
        heap.pop();

        score += top;

        int newVal = ceil(top / 3.0);
        heap.push(newVal);

        k--;
    }

    return score;
}

int main() {
    vector<int> nums = {10,10,10,10,10};
    int k = 5;

    cout<<maxKelements(nums, k);
    
    return 0;
}
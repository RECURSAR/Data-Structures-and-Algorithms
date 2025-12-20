#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int largestCombination(vector<int>& candidates) {
    int largest = 0;

    for(int i = 0; i < 24; i++){
        int count = 0;

        for(auto candidate : candidates){
            if(candidate >> i & 1)
                count += 1;
        }

        largest = max(largest, count);
    }

    return largest;
}

int main() {
    vector<int> candidates = {33,93,31,99,74,37,3,4,2,94,77,10,75,54,24,95,65,100,41,82,35,65,38,49,85,72,67,21,20,31};

    cout<<largestCombination(candidates);

    return 0;
}
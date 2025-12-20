#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

vector<int> lexicalOrder(int n) {
    vector<int> result;
    int current = 1;

    // Perform the DFS-like traversal over the numbers
    for (int i = 0; i < n; i++) {
        result.push_back(current);
        if (current * 10 <= n) {
            // Go deeper: multiply the current number by 10
            current *= 10;
        } else {
            // Increment the current number by 1 (go to the next sibling)
            if (current >= n) {
                current /= 10;
            }
            current++;
            while (current % 10 == 0) {
                current /= 10;
            }
        }
    }

    return result;
}

int main() {
    int n = 13;
    
    vector<int> lexical = lexicalOrder(n);

    for(auto order: lexical)
        cout<<order<<endl;

    return 0;
}
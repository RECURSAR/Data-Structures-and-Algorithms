#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

// Function to count the steps between the current node and its next sibling
long long countSteps(int n, long long first, long long next) {
    long long steps = 0;
    while (first <= n) {
        steps += min((long long)n + 1, next) - first; // Count the steps between `first` and `next`
        first *= 10;
        next *= 10;
    }
    
    return steps;
}

int findKthNumber(int n, int k) {
    int current = 1;  // Start with 1 as the first number
    k--;              // Decrease k by 1 as we start with the number 1
    
    while (k > 0) {
        long long steps = countSteps(n, current, current + 1); // Number of steps between current and current + 1
        if (steps <= k) {
            current++;  // Move to the next sibling
            k -= steps; // Decrease k by the number of steps skipped
        } else {
            current *= 10; // Move to the next level in the tree (deeper)
            k--;           // Decrease k as we've taken one step downwards
        }
    }
    
    return current;
}

int main() {
    int n = 13, k = 2;

    cout<<findKthNumber(n, k);

    return 0;
}
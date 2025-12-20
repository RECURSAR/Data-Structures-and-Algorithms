#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

long numChildren(const vector<int>& candies, int m) {
    return accumulate(candies.begin(), candies.end(), 0L, [&](long subtotal, int c) { return subtotal + c / m; });
};

int maximumCandies(vector<int>& candies, long long k) {
    int l = 1;
    int r = accumulate(candies.begin(), candies.end(), 0L) / k;

    while (l < r) {
      const int m = (l + r) / 2;
      if (numChildren(candies, m) < k)
        r = m;
      else
        l = m + 1;
    }

    return numChildren(candies, l) >= k ? l : l - 1;
}

int main() {
    vector<int> candies = {5, 8, 6};
    long long k = 3;

    cout<<maximumCandies(candies, k);

    return 0;
}
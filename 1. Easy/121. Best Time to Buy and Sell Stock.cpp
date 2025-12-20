#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int maxProfit(vector<int>& prices) {
    int min = INT_MAX, maximumProfit = 0;

    for(size_t i = 0; i < prices.size(); i++) {
        if(prices[i] < min)
            min = prices[i];
        else
            maximumProfit = max(maximumProfit, prices[i] - min);
    }

    return maximumProfit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout<<maxProfit(prices);

    return 0;
}
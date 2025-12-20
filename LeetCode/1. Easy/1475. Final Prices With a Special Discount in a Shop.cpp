#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

vector<int> finalPrices(vector<int>& prices) {
    vector<int> ans{prices};
    stack<int> stack;

    for (int j = 0; j < prices.size(); ++j) {
      // stack[-1] : = i in the problem description.
      while (!stack.empty() && prices[j] <= prices[stack.top()])
        ans[stack.top()] -= prices[j], stack.pop();
      stack.push(j);
    }

    return ans;
}

int main() {
    vector<int> prices = {8,4,6,2,3};

    vector<int> result = finalPrices(prices);
    for(auto res: result)
        cout<<res<<" ";

    return 0;
}
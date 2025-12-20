#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

vector<int> findEvenNumbers(vector<int>& digits) {
    vector<int> ans;
    vector<int> count(10);

    for (const int digit : digits)
      count[digit] += 1;

    for (int a = 1; a <= 9; a++)    // As first digit can't be 0
      for (int b = 0; b <= 9; b++)
        for (int c = 0; c <= 8; c += 2)
          if (count[a] > 0 && count[b] > (b == a) && count[c] > (c == a) + (c == b))
            ans.push_back(a * 100 + b * 10 + c);

    return ans;
}

int main() {
    vector<int> digits = {2,1,3,0};

    vector<int> result = findEvenNumbers(digits);
    for(auto res : result)
        cout<<res<<" ";

    return 0;
}
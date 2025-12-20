#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int numRabbits(vector<int>& answers) {
    int ans = 0;
    vector<int> count(1000);

    for (const int answer : answers) {
      if (count[answer] % (answer + 1) == 0)
        ans += answer + 1;
      ++count[answer];
    }

    return ans;
}

int main() {
    vector<int> answers = {1,1,2};

    cout<<numRabbits(answers);

    return 0;
}
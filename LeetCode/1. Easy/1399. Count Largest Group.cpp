#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int getDigitSum(int num) {
    int digitSum = 0;
    while (num > 0) {
      digitSum += num % 10;
      num /= 10;
    }
    return digitSum;
}

int countLargestGroup(int n) {
    vector<int> count(9 * 4 + 1);
    for (int i = 1; i <= n; ++i)
      ++count[getDigitSum(i)];
    return std::count(count.begin(), count.end(), *std::max_element(count.begin(), count.end()));
}

int main() {
    int n = 13;

    cout<<countLargestGroup(n);

    return 0;
}
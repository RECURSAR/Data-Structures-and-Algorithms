#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

bool isSymmetricInteger(int num) {
    if (num >= 10 && num <= 99)
      return num / 10 == num % 10;

    if (num >= 1000 && num <= 9999) {
      const int left = num / 100;
      const int right = num % 100;
      return left / 10 + left % 10 == right / 10 + right % 10;
    }
    
    return false;
}
  
int countSymmetricIntegers(int low, int high) {
    int ans = 0;

    for (int num = low; num <= high; ++num)
      if (isSymmetricInteger(num))
        ans += 1;

    return ans; 
}

int main() {
    int low = 1, high = 100;

    cout<<countSymmetricIntegers(low, high);

    return 0;
}
#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

bool checkPowersOfThree(int n) {
    while (n > 1) {
        const int r = n % 3;
        if (r == 2)
          return false;
          
        n /= 3;
      }
  
      return true; 
}

int main() {
    int n = 12;

    checkPowersOfThree(n) ? cout<<"True" : cout<<"False";

    return 0;
}
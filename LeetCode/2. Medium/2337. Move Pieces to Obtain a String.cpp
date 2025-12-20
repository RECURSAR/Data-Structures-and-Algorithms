#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

bool canChange(string start, string target) {
    const int n = start.length();
    int i = 0;  // start's index
    int j = 0;  // target's index

    while (i <= n && j <= n) {
      while (i < n && start[i] == '_')
        i++;

      while (j < n && target[j] == '_')
        j++;
        
      if (i == n || j == n)
        return i == n && j == n;

      if (start[i] != target[j])
        return false;

      if (start[i] == 'R' && i > j)
        return false;

      if (start[i] == 'L' && i < j)
        return false;

      i++;
      j++;
    }

    return true;
}

int main() {
    string start = "_L__R__R_", target = "L______RR";

    canChange(start, target) ? cout<<"True" : cout<<"False";

    return 0;
}
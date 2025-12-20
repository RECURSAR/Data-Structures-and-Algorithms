#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

bool isPowerOfFour(int);

int main()
{
   int n = 5;
   bool result;

   result = isPowerOfFour(n);
   cout<<result;
   return 0;
}

bool isPowerOfFour(int n){
    // Base case: 4^0 = 1
    if (n == 1) 
        return true; 

    // If n is less than or equal to 0, or not divisible by 4
    if (n <= 0 || n % 4 != 0) 
        return false;

    return isPowerOfFour(n / 4); 
}
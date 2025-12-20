#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;
 
bool isPowerOfTwo(int);

int main()
{
   int n = 8;
   bool result;

   result = isPowerOfTwo(n);
   cout<<result;
   return 0;
}

bool isPowerOfTwo(int n){
    if(n == 1)
        return true;
    if(n<= 0 || n%2 != 0)
        return false;
    
    return isPowerOfTwo(n/2);
}
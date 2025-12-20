#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

bool isPowerOfThree(int);

int main()
{
    int n = 27;
    bool result;

    result = isPowerOfThree(n);
    cout<<result;
   return 0;
}

bool isPowerOfThree(int n){
    if(n==1)
        return true;
    if(n<=0 || n%3!=0)
        return false;

    return isPowerOfThree(n/3);
}
#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int passThePillow(int , int);

int main()
{
    int n = 3, time = 2, result;
    
    result = passThePillow(n, time);
    cout<<result;
                    
   return 0;
}

int passThePillow(int n, int time){
    int rounds = time/(n-1);
    int ans = 0;

    if(rounds%2==0)
        ans = (1+time%(n-1));
    else 
        ans = (n-time%(n-1));
    
    return ans;
}
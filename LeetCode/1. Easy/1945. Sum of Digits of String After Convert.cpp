#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int getLucky(string s, int k){
    int transformed = 0, sum;

    // Converting string to an integer
    for(int i = 0; i < s.size(); i++){
        int digit = s[i] - 'a' + 1;

        // Add the digits of each converted number directly to sum
        while (digit > 0) {
            transformed += digit % 10;
            digit /= 10;
        }
    }

    // Add the digits of the integer k times
    while(k > 1){
        sum = 0;
        while(transformed != 0){
            sum = sum + transformed % 10;
            transformed = transformed / 10;
        }

        transformed = sum;
        k--;
    }

    return transformed;
}

int main()
{
    string s = "zbax";
    int k = 2;
    int res = getLucky(s,k);
    cout<<res;

    return 0;
}